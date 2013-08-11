using Poly.Internals.CompilerImplemented;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    public class Program
    {
        static SHA1 sha = new SHA1CryptoServiceProvider();

        public static string ConvertTypeToCName(string type)
        {
            type = type.Replace(".__", ".");
            type = type.Replace(".", "__");
            type = type.Replace("::", "_m_");
            return type;
        }

        static void Main(string[] args)
        {
            SDILReader.Globals.LoadOpCodes();

            string codefile, headerfile;
            try
            {
                codefile = args[1];
                headerfile = args[2];
            }
            catch
            {
                codefile = "code.c";
                headerfile = "header.c";
            }

            string code = "#include \"" + headerfile + "\"\n\n";
            string header = "#pragma once\n#include \"polyruntime.h\"\n#include \"mscorlib.h\"\n\n";

            /*string path = Path.GetDirectoryName(Assembly.GetAssembly(typeof(Program)).CodeBase);
            path = path.Replace("file:\\", "");
            Assembly ass = Assembly.LoadFile(path + "\\Tester.dll");*/
            Assembly ass;
            if (args.Length > 0)
            {
                string input = Path.GetFullPath(args[0]);
                ass = Assembly.LoadFrom(input);
                Console.WriteLine(ass.Location);
            }
            else
            {
                string path = Path.GetDirectoryName(Assembly.GetAssembly(typeof(Program)).CodeBase);
                path = path.Replace("file:\\", "");
                ass = Assembly.LoadFile(path + "\\Tester.dll");
            }

            code += "// Imports\n";
            foreach (var export in ass.GetReferencedAssemblies()) {
                code += "#include \"" + export.Name + ".h\"\n";
            }

            Module[] modules = ass.GetModules();
            for (int i = 0; i < modules.Length; i++)
            {
                code += "// module " + modules[i].FullyQualifiedName + "\n\n";
                header += "// module " + modules[i].FullyQualifiedName + "\n\n";

                List<Type> types = modules[i].GetTypes().ToList();
                types.Sort(delegate(Type t1, Type t2) {
                    if (t1.FullName.Contains(".__")) t1 = Type.GetType(t1.FullName.Replace(".__", "."));
                    if (t2.FullName.Contains(".__")) t2 = Type.GetType(t1.FullName.Replace(".__", "."));
                    if (t1.FullName == "System.Object") return -1;
                    if (t2.FullName == "System.Object") return 1;
                    if (t1.IsSubclassOf(t2))
                    {
                        return 1;
                    }
                    else if (t1 == t2)
                    {
                        return 0;
                    }
                    else if (t2.IsSubclassOf(t1))
                    {
                        return -1;
                    }
                    return 0;
                });
                foreach (var type in types)
                {
                    code += "// class " + type.FullName + "\n";
                    header += "// class " + type.FullName + "\n";
                    header += "struct " + ConvertTypeToCName(type.FullName) + " {\n";

                    if (type.BaseType != null && type.FullName != "System.Object" && type.FullName != "System.__Object")
                    {
                        header += "  struct " + ConvertTypeToCName(type.BaseType.FullName) + " __base; // base class\n";
                    }
                    if (type.GetCustomAttribute(typeof(StructureCodeAttribute), true) != null)
                    {
                        StructureCodeAttribute str = (StructureCodeAttribute)type.GetCustomAttribute(typeof(StructureCodeAttribute), true);
                        header += str.GetCode();
                    }
                    FieldInfo[] fis = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);
                    for (int j = 0; j < fis.Length; j++)
                    {
                        if (fis[j].FieldType.IsValueType)
                        {
                            int bytes = getTypeSize(fis[j].FieldType);
                            header += "    int" + bytes + "_t " + fis[j].Name + "; // " + fis[j].MetadataToken + "\n";
                        }
                        else
                        {
                            header += "    uintptr_t " + fis[j].Name + "; //" + fis[j].MetadataToken + "\n";
                        }
                    }
                    header += "};\n";

                    for (int j = 0; j < fis.Length; j++)
                    {
                        code += "enum CIL_Type " + ConvertTypeToCName(type.FullName) + "_f_" + fis[j].Name + "__type = " + GetInternalType(fis[j].FieldType) + "; // " + fis[j].FieldType.FullName + "\n";
                        header += "extern enum CIL_Type " + ConvertTypeToCName(type.FullName) + "_f_" + fis[j].Name + "__type;\n";
                    }

                    ConstructorInfo[] cis = type.GetConstructors(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);
                    for (int j = 0; j < cis.Length; j++)
                    {
                        string addedcode = "    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)\"" + type.FullName.Replace(".__", ".") + "\";\n";
                        foreach (var virtmethod in type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).Where(m => m.IsVirtual))
                        {
                            addedcode += "    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, \"" + GetInternalMethodName(virtmethod, false) + "\", &" + GetInternalMethodName(virtmethod) +
                            "); /* " + virtmethod.Name + " */\n";
                        }
                        ProcessMethodBody(cis[j], ref code, ref header, addedcode);
                    }

                    MethodInfo[] mis = type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);
                    for (int j = 0; j < mis.Length; j++)
                    {
                        ProcessMethodBody(mis[j], ref code, ref header);
                    }
                }
            }

            File.WriteAllText(codefile, code);
            File.WriteAllText(headerfile, header);
        }

        private static string GetInternalType(Type type)
        {
            switch (type.FullName)
            {
                case "System.Int8":
                case "System.UInt8":
                case "System.Byte":
                case "System.SByte":
                case "System.Int16":
                case "System.UInt16":
                case "System.Char":
                case "System.Short":
                case "System.UShort":
                case "System.Int32":
                case "System.UInt32":
                case "System.Boolean":
                    return "CIL_int32";
                case "System.Int64":
                case "System.UInt64":
                case "System.Long":
                case "System.ULong":
                    return "CIL_int64";
                case "System.Single":
                    return "CIL_float32";
                case "System.Double":
                    return "CIL_float64";

                default:
                    return "CIL_pointer";
            }
            return "CIL_unknown";
        }

        private static string ProcessMethodBody(MethodBase m, ref string code, ref string header, string addedcode = "")
        {
            // check if the method has a body

            //if (m.GetMethodBody() != null)
            //{
            SDILReader.MethodBodyReader mbr = new SDILReader.MethodBodyReader(m);

            bool skipFirstConstructorCall = false;
            bool processMethodBody = true;

            // Do not call the base class constructor for System.Object, because that would create an infinite recursive loop
            if (m.DeclaringType.FullName == "System.__Object" && m.IsConstructor) skipFirstConstructorCall = true;

            code += "/* " + m.DeclaringType.FullName + "::" + m.Name + " */\n";
            code += "void *" + GetInternalMethodName(m) + "(/*";
            foreach (ParameterInfo p in m.GetParameters())
            {
                code += p.Position + ":";
                code += p.Name;
                code += "<" + p.MetadataToken + ">, ";
            }
            code += "*/) {\n";

            header += "/* " + m.DeclaringType.FullName + "::" + m.Name + " */\n";
            header += "void *" + GetInternalMethodName(m) + "(/*";
            foreach (ParameterInfo p in m.GetParameters())
            {
                header += p.Position + ":";
                header += p.Name;
                header += "<" + p.MetadataToken + ">, ";
            }
            header += "*/);\n";

            // parameters
            int staticOffset = m.IsStatic ? 1 : 0;
            for (int i = m.GetParameters().Count() - 1; i >= 0; i--)
            {
                ParameterInfo p = m.GetParameters().Where(a => a.Position == i).First();
                if (p.ParameterType.IsValueType)
                {
                    int bytes = getTypeSize(p.ParameterType);
                    code += "    int" + bytes + "_t parameter" + (p.Position + 1 - staticOffset) + " = pop_value" + bytes + "();\n";
                    code += "    enum CIL_Type parameter" + (p.Position + 1 - staticOffset) + "__type = " + GetInternalType(p.ParameterType) + "; // " + p.ParameterType.FullName + "\n";
                }
                else
                {
                    code += "    uintptr_t parameter" + (p.Position + 1 - staticOffset) + " = pop_pointer();\n";
                    code += "    enum CIL_Type parameter" + (p.Position + 1 - staticOffset) + "__type = " + GetInternalType(p.ParameterType) + "; // " + p.ParameterType.FullName + "\n";
                }
            }
            if (!m.IsStatic)
            {
                code += "    uintptr_t parameter0 = pop_pointer();\n";
                code += "    enum CIL_Type parameter0__type = CIL_pointer;\n";
            }

            if (m.GetCustomAttributes(typeof(Poly.Internals.CompilerImplemented.InlineCodeAttribute), true).Length > 0)
            {
                // This is an internal method that has to be handled by the compiler (that's me!)

                code += "    /* INLINE CODE */\n";

                InlineCodeAttribute a = (InlineCodeAttribute)m.GetCustomAttributes(typeof(Poly.Internals.CompilerImplemented.InlineCodeAttribute), true)[0];
                PolyCompiler.CompilerImplementation.InlineCode(a.GetCode(), a.GetLang(), ref code);
                if (a.GetReplaceCompleteImplementation()) processMethodBody = false; 

                code += "\n    /* END INLINE CODE */\n";
            }

            if (processMethodBody)
            {
                if (m.GetMethodBody() != null)
                {
                    // locals
                    foreach (LocalVariableInfo l in m.GetMethodBody().LocalVariables)
                    {
                        if (l.LocalType.IsValueType)
                        {
                            int bytes = getTypeSize(l.LocalType);
                            code += "    int" + bytes + "_t local" + l.LocalIndex + " = 0;\n";
                            code += "    enum CIL_Type local" + l.LocalIndex + "__type = " + GetInternalType(l.LocalType) + "; // " + l.LocalType.FullName + "\n";
                        }
                        else
                        {
                            code += "    uintptr_t local" + l.LocalIndex + " = 0;\n";
                            code += "    enum CIL_Type local" + l.LocalIndex + "__type = " + GetInternalType(l.LocalType) + "; // " + l.LocalType.FullName + "\n";
                        }
                    }

                    foreach (SDILReader.ILInstruction instr in mbr.instructions)
                    {
                        if (skipFirstConstructorCall && instr.Code == System.Reflection.Emit.OpCodes.Call && ((MethodBase)instr.Operand).IsConstructor)
                        {
                            code += "    pop_pointer();\n";
                            code += addedcode; // addedcode shoud have been afther this call, but this call is removed, so we handle the addedcode ourself.
                            continue;
                        }

                        code += "    ";

                        switch (instr.Code.Name)
                        {
                            case "br.s":
                                code += "goto " + ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset((int)instr.Operand);
                                break;
                            default:
                                code += ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name);
                                code += instr.GetCode();
                                break;
                        }

                        code += ";\n";

                        // Addedcode is pasted after the FIRST constructor call
                        if (instr.Code == System.Reflection.Emit.OpCodes.Call && ((MethodBase)instr.Operand).IsConstructor)
                        {
                            code += addedcode;
                            addedcode = "";
                        }
                    }
                }
            }

            code += "    return 0;\n}\n";
            // }

            return code;
        }

        public static string GetInternalMethodName(MethodBase m, bool includePath = true)
        {
            string path = m.DeclaringType.FullName.Replace(".__", ".");
            string type = m.Name;
            type = type.TrimStart(new char[] { '_' });
            string sig;
            if (includePath)
                sig = path + "::" + type;
            else
                sig = type;
            foreach (var p in m.GetParameters())
            {
                sig += "__" + p.ParameterType.FullName;
            }
            
            System.Text.ASCIIEncoding encoder = new System.Text.ASCIIEncoding();
            string ret = "m" + BitConverter.ToString(sha.ComputeHash(encoder.GetBytes(sig))).Replace("-", "");
            return ConvertTypeToCName(ret.ToString());
        }

        private static int getTypeSize(Type type)
        {
            int bytes = Marshal.SizeOf(type) * 8;
            if (bytes < 32) bytes = 32;
            return bytes;
        }
    }
}
