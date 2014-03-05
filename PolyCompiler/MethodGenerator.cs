using Poly.Internals.CompilerImplemented;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    class MethodGenerator
    {
        public static void ProcessMethods(Type type, CompilerContext context)
        {
            ConstructorInfo[] cis = type.GetConstructors(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);
            for (int j = 0; j < cis.Length; j++)
            {
                if (cis[j].Name == ".cctor")
                {
                    if ((type.Attributes & TypeAttributes.BeforeFieldInit) != 0)
                    {
                        context.Init.Append(Naming.GetInternalMethodName(cis[j], true) + "();\n");
                    }
                    else
                    {
                        // If not marked BeforeFieldInit then that type’s initializer method is executed at (i.e., is triggered by):
                        /*  a. first access to any static field of that type, or 
                            b. first invocation of any static method of that type, or 
                            c. first invocation of any instance or virtual method of that type if it is a value 
                            type or 
                            d. first invocation of any constructor for that type. */

                        throw new NotImplementedException();
                    }
                }

                string addedcode = "    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)\"" + type.FullName.Replace(".__", ".") + "\";\n";
                foreach (var virtmethod in type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).Where(m => m.IsVirtual))
                {
                    addedcode += "    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, \"" + Naming.GetInternalMethodName(virtmethod, false) + "\", &" + Naming.GetInternalMethodName(virtmethod) +
                   "); /* " + virtmethod.Name + " */\n";
                }
                ProcessMethodBody(cis[j], context, addedcode);
            }

            MethodInfo[] mis = type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);
            for (int j = 0; j < mis.Length; j++)
            {
                ProcessMethodBody(mis[j], context);
            }
        }

        public static void ProcessMethodBody(MethodBase m, CompilerContext context, string addedcode = "")
        {
            SDILReader.MethodBodyReader mbr = new SDILReader.MethodBodyReader(m);

            bool skipFirstConstructorCall = false;
            bool processMethodBody = true;

            // Do not call the base class constructor for System.Object, because that would create an infinite recursive loop
            if (m.DeclaringType.FullName == "System.__Object" && m.IsConstructor) skipFirstConstructorCall = true;

            context.Code.Append("/* " + m.DeclaringType.FullName + "::" + m.Name + " */\n");
            context.Code.Append("void *" + Naming.GetInternalMethodName(m) + "(/*");
            foreach (ParameterInfo p in m.GetParameters())
            {
                context.Code.Append(p.Position + ":");
                context.Code.Append(p.Name);
                context.Code.Append("<" + p.MetadataToken + ">, ");
            }
            context.Code.Append("*/) {\n");

            context.Header.Append("/* " + m.DeclaringType.FullName + "::" + m.Name + " */\n");
            context.Header.Append("void *" + Naming.GetInternalMethodName(m) + "(/*");
            foreach (ParameterInfo p in m.GetParameters())
            {
                context.Header.Append(p.Position + ":");
                context.Header.Append(p.Name);
                context.Header.Append("<" + p.MetadataToken + ">, ");
            }
            context.Header.Append("*/);\n");

            // parameters
            int parameterOffset = 0;
            if (m.IsStatic) parameterOffset = 1;

            if (m.IsConstructor)
            {
                // constructors get the object as last parameter on the stack instead of the first
                context.Code.Append("    uintptr_t parameter0 = pop_pointer();\n");
                context.Code.Append("    enum CIL_Type parameter0__type = CIL_pointer;\n");
            }

            for (int i = m.GetParameters().Count() - 1; i >= 0; i--)
            {
                ParameterInfo p = m.GetParameters().Where(a => a.Position == i).First();
                if (p.ParameterType.IsValueType)
                {
                    int bytes = TypeHelper.GetTypeSize(p.ParameterType);
                    context.Code.Append("    int" + bytes + "_t parameter" + (p.Position + 1 - parameterOffset) + " = pop_value" + bytes + "();\n");
                    context.Code.Append("    enum CIL_Type parameter" + (p.Position + 1 - parameterOffset) + "__type = " + Naming.GetInternalType(p.ParameterType) + "; // " + p.ParameterType.FullName + "\n");
                }
                else
                {
                    context.Code.Append("    uintptr_t parameter" + (p.Position + 1 - parameterOffset) + " = pop_pointer();\n");
                    context.Code.Append("    enum CIL_Type parameter" + (p.Position + 1 - parameterOffset) + "__type = " + Naming.GetInternalType(p.ParameterType) + "; // " + p.ParameterType.FullName + "\n");
                }
            }
            if (!m.IsStatic && !m.IsConstructor)
            {
                context.Code.Append("    uintptr_t parameter0 = pop_pointer();\n");
                context.Code.Append("    enum CIL_Type parameter0__type = CIL_pointer;\n");
            }

            if (m.GetCustomAttributes(typeof(Poly.Internals.CompilerImplemented.InlineCodeAttribute), true).Length > 0)
            {
                // This is an internal method that has to be handled by the compiler (that's me!)

                context.Code.Append("    /* INLINE CODE */\n");

                InlineCodeAttribute a = (InlineCodeAttribute)m.GetCustomAttributes(typeof(Poly.Internals.CompilerImplemented.InlineCodeAttribute), true)[0];
                string code = "";
                PolyCompiler.CompilerImplementation.InlineCode(a.GetCode(), a.GetLang(), ref code);
                context.Code.Append(code);

                if (a.GetReplaceCompleteImplementation()) processMethodBody = false;

                context.Code.Append("\n    /* END INLINE CODE */\n");
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
                            int bytes = TypeHelper.GetTypeSize(l.LocalType);
                            context.Code.Append("    int" + bytes + "_t local" + l.LocalIndex + " = 0;\n");
                            context.Code.Append("    enum CIL_Type local" + l.LocalIndex + "__type = " + Naming.GetInternalType(l.LocalType) + "; // " + l.LocalType.FullName + "\n");
                        }
                        else
                        {
                            context.Code.Append("    uintptr_t local" + l.LocalIndex + " = 0;\n");
                            context.Code.Append("    enum CIL_Type local" + l.LocalIndex + "__type = " + Naming.GetInternalType(l.LocalType) + "; // " + l.LocalType.FullName + "\n");
                        }
                    }

                    foreach (SDILReader.ILInstruction instr in mbr.instructions)
                    {
                        if (skipFirstConstructorCall && instr.Code == System.Reflection.Emit.OpCodes.Call && ((MethodBase)instr.Operand).IsConstructor)
                        {
                            context.Code.Append("    pop_pointer();\n");
                            context.Code.Append(addedcode); // addedcode shoud have been afther this call, but this call is removed, so we handle the addedcode ourself.
                            continue;
                        }

                        context.Code.Append("    ");

                        switch (instr.Code.Name)
                        {
                            case "br.s":
                                context.Code.Append("goto " + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset((int)instr.Operand));
                                break;
                            default:
                                context.Code.Append(instr.GetCode(m, context));
                                break;
                        }

                        context.Code.Append(";\n");

                        // Addedcode is pasted after the FIRST constructor call
                        if (instr.Code == System.Reflection.Emit.OpCodes.Call && ((MethodBase)instr.Operand).IsConstructor)
                        {
                            context.Code.Append(addedcode);
                            addedcode = "";
                        }
                    }
                }
            }

            context.Code.Append("    return 0;\n}\n");
        }
    }
}
