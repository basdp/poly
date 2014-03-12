using Poly.Internals.CompilerImplemented;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    class TypeGenerator
    {
        public static void ProcessTypeDefinition(Type type, CompilerContext context)
        {
            if (type.IsInterface)
            {
                ProcessInterface(type, context);
                return;
            }

            context.Header.Append("// class " + type.FullName + "\n");
            context.Header.Append("struct " + Naming.ConvertTypeToCName(type.FullName) + " {\n");

            if (type.BaseType != null && type.FullName != "System.Object" && type.FullName != "System.__Object")
            {
                context.Header.Append("  struct " + Naming.ConvertTypeToCName(type.BaseType.FullName) + " __base; // base class\n");
            }
            if (type.GetCustomAttribute(typeof(StructureCodeAttribute), true) != null)
            {
                StructureCodeAttribute str = (StructureCodeAttribute)type.GetCustomAttribute(typeof(StructureCodeAttribute), true);
                context.Header.Append(str.GetCode());
            }

            // todo .pack? (type.StructLayoutAttribute.Pack)

            int classSize = 0;
            FieldInfo[] fis = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
            for (int j = 0; j < fis.Length; j++)
            {
                context.Offsets[fis[j]] = classSize;

                if (fis[j].FieldType.IsValueType)
                {
                    int bits = TypeHelper.GetTypeSize(fis[j].FieldType);
                    if (bits <= 64 && bits > 0)
                    {
                        context.Header.Append("    int" + bits + "_t " + Naming.GetInternalFieldName(fis[j].Name) + "; // " + fis[j].MetadataToken + "\n");
                    }
                    else
                    {
                        context.Header.Append("    int8_t " + Naming.GetInternalFieldName(fis[j].Name) + "[" + (bits / 8) + "]; // " + fis[j].MetadataToken + "\n");
                    }
                    classSize += bits / 8;
                }
                else
                {
                    context.Header.Append("    uintptr_t " + Naming.GetInternalFieldName(fis[j].Name) + "; //" + fis[j].MetadataToken + "\n");
                    // TODO: 64 bit?
                    classSize += 4;
                }

                if (type.IsGenericTypeDefinition && fis[j].FieldType.IsGenericParameter)
                {
                    context.Header.Append("    enum CIL_Type " + Naming.GetInternalFieldName(fis[j].Name) + "__type;\n");
                }
            }

            if (type.StructLayoutAttribute != null && type.StructLayoutAttribute.Size != 0)
            {
                //header += "#ifdef POLY32\n";
                context.Header.Append("    int8_t __padding[" + (type.StructLayoutAttribute.Size - classSize) + "];\n");
                //header += "#elif POLY64\n";
                //header += "    int8_t __padding[" + (type.StructLayoutAttribute.Size - classSize64) + "];\n";
                //header += "#else\n";
                //header += "#error The class " + type.FullName + " has specific allignment requirements. This has not been implemented for the active platform.\n";
                //header += "#endif\n";
            }

            context.Header.Append("};\n");

            ProcessBaseClasses(type, context);
            ProcessBaseInterfaces(type, context);

            for (int j = 0; j < fis.Length; j++)
            {
                context.Code.Append("enum CIL_Type " + Naming.ConvertTypeToCName(type.FullName) + "_f_" + Naming.GetInternalFieldName(fis[j].Name) + "__type = " + TypeHelper.GetInternalType(fis[j].FieldType) + "; // " + fis[j].FieldType.FullName + "\n");
                context.Header.Append("extern enum CIL_Type " + Naming.ConvertTypeToCName(type.FullName) + "_f_" + Naming.GetInternalFieldName(fis[j].Name) + "__type;\n");
            }

            // Static fields
            fis = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static);
            for (int j = 0; j < fis.Length; j++)
            {
                if (fis[j].FieldType.IsValueType)
                {
                    int bits = TypeHelper.GetTypeSize(fis[j].FieldType);
                    if (bits <= 64 && bits > 0)
                    {
                        context.Header.Append("int" + bits + "_t " + Naming.ConvertTypeToCName(type.FullName) + "_sf_" + Naming.GetInternalFieldName(fis[j].Name) + "; // " + fis[j].MetadataToken + "\n");
                    }
                    else
                    {
                        context.Header.Append("int8_t " + Naming.ConvertTypeToCName(type.FullName) + "_sf_" + Naming.GetInternalFieldName(fis[j].Name) + "[" + (bits / 8) + "]; // " + fis[j].MetadataToken + "\n");
                    }
                }
                else
                {
                    context.Header.Append("uintptr_t " + Naming.ConvertTypeToCName(type.FullName) + "_sf_" + Naming.GetInternalFieldName(fis[j].Name) + "; //" + fis[j].MetadataToken + "\n");
                }

                if ((FieldAttributes.HasFieldRVA & fis[j].Attributes) != 0)
                {
                    if (!fis[j].IsStatic) throw new NotImplementedException();
                    context.Init.Append("    // RVA for " + type.FullName + "::" + fis[j].Name + "\n");
                    object o = fis[j].GetValue(null);
                    int size = Marshal.SizeOf(o);
                    byte[] arr = new byte[size];
                    IntPtr ptr = Marshal.AllocHGlobal(size);

                    Marshal.StructureToPtr(o, ptr, true);
                    Marshal.Copy(ptr, arr, 0, size);
                    Marshal.FreeHGlobal(ptr);

                    for (int k = 0; k < arr.Length; k++)
                    {
                        context.Init.Append("    " + Naming.ConvertTypeToCName(type.FullName) + "_sf_" + Naming.GetInternalFieldName(fis[j].Name) + "[" + k + "] = " + arr[k] + ";\n");
                    }

                }
            }
            for (int j = 0; j < fis.Length; j++)
            {
                context.Code.Append("enum CIL_Type " + Naming.ConvertTypeToCName(type.FullName) + "_sf_" + Naming.GetInternalFieldName(fis[j].Name) + "__type = " + TypeHelper.GetInternalType(fis[j].FieldType) + "; // " + fis[j].FieldType.FullName + "\n");
                context.Header.Append("extern enum CIL_Type " + Naming.ConvertTypeToCName(type.FullName) + "_sf_" + Naming.GetInternalFieldName(fis[j].Name) + "__type;\n");
            }
        }

        private static void ProcessBaseClasses(Type type, CompilerContext context)
        {
            Type baseType = type.BaseType;
            List<Type> baseTypes = new List<Type>();
            while (baseType != null && type.FullName != "System.Object" && type.FullName != "System.__Object")
            {
                baseTypes.Add(baseType);
                baseType = baseType.BaseType;
            }

            context.Code.AppendLine("int " + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses_length = " + baseTypes.Count + ";");
            if (baseTypes.Count == 0)
            {
                context.Header.AppendLine("extern char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses[1];");
                context.Code.AppendLine("char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses[1] = { \"\" };");
            }
            else
            {
                context.Header.AppendLine("extern char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses[" + baseTypes.Count + "];");
                context.Code.AppendLine("char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses[" + baseTypes.Count + "] = {");
                for (int i = 0; i < baseTypes.Count; i++)
                {
                    context.Code.Append("    \"" + baseTypes[i].FullName.Replace(".__", ".") + "\"");
                    if (i < baseTypes.Count - 1) context.Code.Append(", ");
                    context.Code.Append("\n");
                }
                context.Code.AppendLine("};");
            }
        }

        private static void ProcessBaseInterfaces(Type type, CompilerContext context)
        {
            var interfaces = type.GetInterfaces();

            context.Code.AppendLine("int " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces_length = " + interfaces.Length + ";");
            if (interfaces.Length == 0)
            {
                context.Header.AppendLine("extern char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[1];");
                context.Code.AppendLine("char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[1] = { \"\" };");
            }
            else
            {
                context.Header.AppendLine("extern char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[" + interfaces.Length + "];");
                context.Code.AppendLine("char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[" + interfaces.Length + "] = {");
                for (int i = 0; i < interfaces.Length; i++)
                {
                    context.Code.Append("    \"" + interfaces[i].FullName.Replace(".__", ".") + "\"");
                    if (i < interfaces.Length - 1) context.Code.Append(", ");
                    context.Code.Append("\n");
                }
                context.Code.AppendLine("};");
            }
        }

        private static void ProcessInterface(Type type, CompilerContext context)
        {
            context.Header.Append("// interface " + type.FullName + "\n");
            
            Type baseType = type.BaseType;
            List<Type> baseTypes = new List<Type>();
            while (baseType != null && type.FullName != "System.Object" && type.FullName != "System.__Object")
            {
                baseTypes.Add(baseType);
                baseType = baseType.BaseType;
            }

            context.Code.AppendLine("int " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces_length = " + baseTypes.Count + ";");
            if (baseTypes.Count == 0)
            {
                context.Header.AppendLine("extern char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[1];");
                context.Code.AppendLine("char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[1] = { \"\" };");
            }
            else
            {
                context.Header.AppendLine("extern char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[" + baseTypes.Count + "];");
                context.Code.AppendLine("char* " + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces[" + baseTypes.Count + "] = {");
                for (int i = 0; i < baseTypes.Count; i++)
                {
                    context.Code.Append("    \"" + baseTypes[i].FullName.Replace(".__", ".") + "\"");
                    if (i < baseTypes.Count - 1) context.Code.Append(", ");
                    context.Code.Append("\n");
                }
                context.Code.AppendLine("};");
            }
        }
    }
}
