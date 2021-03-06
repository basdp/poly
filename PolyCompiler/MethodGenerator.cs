﻿using Poly.Internals.CompilerImplemented;
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
            context.Code.Append("// class " + type.FullName + "\n");

            var cis = type.GetConstructors(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance).ToList();
            cis.Sort(delegate(ConstructorInfo t1, ConstructorInfo t2)
            {
                if (t1.Name == ".cctor")
                {
                    return -1;
                }
                else if (t1 == t2)
                {
                    return 0;
                }
                else if (t2.Name == ".cctor")
                {
                    return 1;
                }
                return t1.Name.CompareTo(t2.Name);
            });
            for (int j = 0; j < cis.Count; j++)
            {
                string addedcode = "";
                if (cis[j].Name == ".cctor")
                {
                    if ((type.Attributes & TypeAttributes.BeforeFieldInit) != 0)
                    {
                        context.Init.Append("CIL_call_unsafe(" + Naming.GetInternalMethodName(cis[j], true) + ", \"\", 0, 0);\n");
                    }
                    else
                    {
                        // If not marked BeforeFieldInit then that type’s initializer method is executed at (i.e., is triggered by):
                        /*  a. first access to any static field of that type, or 
                            b. first invocation of any static method of that type, or 
                            c. first invocation of any instance or virtual method of that type if it is a value type or 
                            d. first invocation of any constructor for that type. */

                        context.CallCctorAtAccess.Add(type);
                        addedcode += "    " + Naming.ConvertTypeToCName(type.FullName) + "__cctor_called = 1;\n";
                        context.Header.AppendLine("int " + Naming.ConvertTypeToCName(type.FullName) + "__cctor_called;");
                        context.Code.AppendLine("int " + Naming.ConvertTypeToCName(type.FullName) + "__cctor_called = 0;");
                    }
                }
                else
                {
                    addedcode += "    " + Naming.ConvertTypeToCName(type.FullName) + "__cctor_init();\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)\"" + type.FullName.Replace(".__", ".") + "\";\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&" + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses;\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &" + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses_length;\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILbaseinterfaces = (intptr_t)&" + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces;\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILbaseinterfaces_length = &" + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces_length;\n";

                    if (type.IsGenericTypeDefinition)
                    {
                        addedcode += "    ((struct System__Object*)parameter0)->__CILisgeneric = 1;\n";
                        addedcode += "    ((struct System__Object*)parameter0)->__CILgenerictypelist_length = generictypelist_length;\n";
                        addedcode += "    ((struct System__Object*)parameter0)->__CILgenerictypelist = generictypelist;\n";
                        foreach (var field in type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance))
                        {
                            if (field.FieldType.IsGenericParameter)
                            {
                                int typeindex = field.FieldType.GenericParameterPosition;
                                addedcode += "    ((struct " + Naming.ConvertTypeToCName(type) + "*)parameter0)->" + field.Name + "__type = ";
                                addedcode += "generictypelist[" + typeindex + "];\n";
                            }
                        }
                    }
                    foreach (var virtmethod in type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).Where(m => m.IsVirtual || m.IsFinal))
                    {
                        addedcode += "    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, \"" + Naming.GetInternalMethodName(virtmethod, false) + "\", &" + Naming.GetInternalMethodName(virtmethod) +
                       "); /* " + virtmethod.Name + " -> SIG: " + Naming.GetInternalMethodName(virtmethod, false, true) + " */\n";
                    }

                    addedcode += "    if (!skipDefaultInitialization) {\n";
                    FieldInfo[] fis = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
                    for (int k = 0; k < fis.Length; k++)
                    {
                        /*if (fis[k].FieldType.IsGenericParameter)
                        {
                            addedcode += "    push_default_value(((struct " + Naming.ConvertTypeToCName(type.FullName) + "*)parameter0)->" + Naming.GetInternalFieldName(fis[k].Name) + "__type);\n";
                            addedcode += "    CIL_box_ciltype(((struct " + Naming.ConvertTypeToCName(type.FullName) + "*)parameter0)->" + Naming.GetInternalFieldName(fis[k].Name) + "__type);\n";
                        }*/

                        addedcode += "        ((struct " + Naming.ConvertTypeToCName(type.FullName) + "*)parameter0)->";
                        if (fis[k].FieldType.IsValueType)
                        {
                            int bits = TypeHelper.GetTypeSize(fis[k].FieldType);
                            if (bits <= 64 && bits > 0)
                            {
                                addedcode += Naming.GetInternalFieldName(fis[k].Name) + " = 0;";
                            }
                            else
                            {
                                addedcode += Naming.GetInternalFieldName(fis[k].Name) + " = { 0 };";
                            }
                        }
                        else
                        {
                            addedcode += Naming.GetInternalFieldName(fis[k].Name) + " = 0;";
                            /*if (fis[k].FieldType.IsGenericParameter)
                            {
                                addedcode += Naming.GetInternalFieldName(fis[k].Name) + " = pop_pointer();";
                            }
                            else
                            {
                                addedcode += Naming.GetInternalFieldName(fis[k].Name) + " = 0;";
                            }*/
                        }
                        addedcode += "\n";

                    }
                    addedcode += "    }\n";
                }

                ProcessMethodBody(cis[j], context, addedcode);
            }

            if (context.CallCctorAtAccess.Contains(type))
            {
                context.Header.Append("#define " + Naming.ConvertTypeToCName(type.FullName) + "__cctor_init() ");
                context.Header.AppendLine("if (!" + Naming.ConvertTypeToCName(type.FullName) + "__cctor_called) CIL_call(" + Naming.GetInternalMethodName(type.FullName + "::.cctor") + ", \"\", 0, 0);");
            }
            else
            {
                context.Header.AppendLine("#define " + Naming.ConvertTypeToCName(type.FullName) + "__cctor_init() ");
            }
            
            // if this type has no default constructor (.ctor()) for any reason, generate it
            if (type.IsValueType)
            {
                string addedcode = "    uintptr_t parameter0 = pop_pointer();\n    enum CIL_Type parameter0__type = CIL_pointer;\n    struct LinkedList gcList = linkedlist_new();\n    int entryStackSize = stack_size();\n    int boundExceptions = 0;\n    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)\"" + type.FullName.Replace(".__", ".") + "\";\n";
                string startscope = Naming.ConvertTypeToCName(type.FullName + "::__init") + "__start";
                addedcode += "    void* method_start;\n";
                addedcode += "    " + startscope + ": STORE_LABEL_ADDRESS(method_start, " + startscope + ");\n\n";
                addedcode += "    CIL_ldarg__0();\n    CIL_call(/*constructor*/ mEDC8295D0100B7A05696604AA16180D59191E3E6, \"NONE\", 0, 0 /* System.ValueType::.ctor() */);\n";
                addedcode += "    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&" + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses;\n";
                addedcode += "    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &" + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses_length;\n";
                addedcode += "    ((struct System__Object*)parameter0)->__CILbaseinterfaces = (intptr_t)&" + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces;\n";
                addedcode += "    ((struct System__Object*)parameter0)->__CILbaseinterfaces_length = &" + Naming.ConvertTypeToCName(type.FullName) + "__baseinterfaces_length;\n";
                foreach (var virtmethod in type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).Where(m => m.IsVirtual))
                {
                    addedcode += "    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, \"" + Naming.GetInternalMethodName(virtmethod, false) + "\", &" + Naming.GetInternalMethodName(virtmethod) +
                   "); /* " + virtmethod.Name + " */\n";
                }
                if (type.IsGenericTypeDefinition)
                {
                    addedcode += "    ((struct System__Object*)parameter0)->__CILisgeneric = 1;\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILgenerictypelist_length = generictypelist_length;\n";
                    addedcode += "    ((struct System__Object*)parameter0)->__CILgenerictypelist = generictypelist;\n";
                }

                context.Header.Append("void *" + Naming.ConvertTypeToCName(type.FullName) + "__init(");
                if (type.IsGenericTypeDefinition) context.Header.Append("int, enum CIL_Type*");
                context.Header.AppendLine(");");

                context.Code.Append("void *" + Naming.ConvertTypeToCName(type.FullName) + "__init(");
                if (type.IsGenericTypeDefinition) context.Code.Append("int generictypelist_length, enum CIL_Type* generictypelist");                
                context.Code.Append(") {\n");
                context.Code.Append(addedcode);
                context.Code.AppendLine("return 0; \n}");

            }

            MethodInfo[] mis = type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);
            for (int j = 0; j < mis.Length; j++)
            {
                ProcessMethodBody(mis[j], context);
            }
        }

        public static void ProcessMethodBody(MethodBase m, CompilerContext context, string addedcode = "")
        {
            if (m.Name == "Main" && m.IsStatic && !context.DoNotGenerateMain && (context.EntryClass == null || context.EntryClass == Naming.GetFullName(m.DeclaringType)))
            {
                // yay, we found an entry point
                context.IsExecutable = true;
                if (context.MainGenerated)
                {
                    Console.Error.WriteLine("PolyCompiler: Error: Multiple Main(...) methods found. Please specify the Entry Point using --main");
                    Environment.Exit(1);
                }
                
                context.MainGenerated = true;

                context.Main.AppendLine("int main(int argc, char** argv) {");
                context.Main.AppendLine("    gc_init();");
                context.Main.AppendLine("    struct LinkedList gcList = linkedlist_new();");
                context.Main.AppendLine("    int entryStackSize = 0;");
                context.Main.AppendLine("    int boundExceptions = 0;");

                context.Main.AppendLine("    init_" + Naming.ConvertTypeToCName(m.DeclaringType.Assembly.GetName().Name) + "();");

                if (m.GetParameters().Count() == 1)
                {
                    context.Main.AppendLine("    push_value32(argc - 1, CIL_int32);");
                    context.Main.AppendLine("    CIL_newarr(System.String);");
                    context.Main.AppendLine("    uintptr_t args = pop_pointer();");
                    context.Main.AppendLine("    gc_retain(0, args);");
                    context.Main.AppendLine("    int i;");
                    context.Main.AppendLine("    for(i = 1; i < argc; i++) {");
                    context.Main.AppendLine("        push_arraypointer(args);");
                    context.Main.AppendLine("        push_value32(i - 1, CIL_int32);");
                    context.Main.AppendLine("        CIL_ldstr(argv[i]);");
                    context.Main.AppendLine("        CIL_stelem__ref();");
                    context.Main.AppendLine("    }");
                    context.Main.AppendLine("    push_arraypointer(args);");
                }
                else if (m.GetParameters().Count() > 1)
                {
                    throw new NotImplementedException(); // I think this is illegal also
                }

                context.Main.AppendLine("    CIL_call_unsafe(" + Naming.GetInternalMethodName(m) + ", \"" + Naming.GetInternalMethodName(m, false) + "\", " + m.GetParameters().Count() + ", 0);");

                if (m.GetParameters().Count() == 1)
                {
                    context.Main.AppendLine("    gc_release(0, args);");
                }

                context.Main.AppendLine("    linkedlist_free(&gcList);");
                context.Main.AppendLine("    gc_cycle();");
                if (context.DebugLevel > 1)
                {
                    context.Main.AppendLine("    if (heap_size() > 0) { printf(\"DEBUG WARNING: Heap is not empty at end of program.\\n\"); print_heap(); }");
                    context.Main.AppendLine("    if (stack_size() > 1 || (stack_size() > 0 && stack_top_type() != CIL_int32)) { printf(\"DEBUG WARNING: Stack is not empty at end of program. (int32 for return is allowed)\\n\"); print_stack(); }");
                }
                context.Main.AppendLine("    if (stack_size() > 0 && stack_top_type() == CIL_int32) { return pop_value32(); }");
                context.Main.AppendLine("    else { return 0; }");
                
                context.Main.AppendLine("}");
            }

            SDILReader.MethodBodyReader mbr = new SDILReader.MethodBodyReader(m);

            bool skipFirstConstructorCall = false;
            bool processMethodBody = true;

            // Do not call the base class constructor for System.Object, because that would create an infinite recursive loop
            if (m.DeclaringType.FullName == "System.__Object" && m.IsConstructor) skipFirstConstructorCall = true;

            context.Code.Append("/* " + m.DeclaringType.FullName.Replace(".__", ".") + "::" + m.Name + " */\n");
            context.Code.Append("char* " + Naming.GetInternalMethodName(m) + "_sig = \"" + m.DeclaringType.FullName.Replace(".__", ".") + "::" + m.Name + "(");
            if (m.GetParameters().Count() > 0)
                context.Code.Append(m.GetParameters().Select(p => p.ParameterType.Name + " " + p.Name).Aggregate((a, b) => a + ", " + b));
            context.Code.Append(")\";\n");

            context.Header.Append("/* " + m.DeclaringType.FullName + "::" + m.Name + " */\n");
            context.Header.AppendLine("extern char* " + Naming.GetInternalMethodName(m) + "_sig;");

            if (m.IsConstructor && m.DeclaringType.IsGenericTypeDefinition)
            {
                context.Header.Append("void *" + Naming.GetInternalMethodName(m) + "(int, enum CIL_Type*);\n");

                context.Code.Append("void *" + Naming.GetInternalMethodName(m) + "(int generictypelist_length, enum CIL_Type* generictypelist) {\n");
            }
            else
            {
                //string hname = Naming.GetInternalMethodName(m);

                context.Header.Append("void *" + Naming.GetInternalMethodName(m) + "(");
                if (m.IsGenericMethod) context.Header.Append("int generictypelist_length, enum CIL_Type* generictypelist");
                context.Header.Append(");\n");

                context.Code.AppendLine("// SIG: " + Naming.GetInternalMethodName(m, true, true));
                context.Code.Append("void *" + Naming.GetInternalMethodName(m) + "(");
                if (m.IsGenericMethod) context.Code.Append("int generictypelist_length, enum CIL_Type* generictypelist");
                context.Code.Append(") {\n");
            }

            context.Code.AppendLine("    struct LinkedList gcList = linkedlist_new();");

            // parameters
            int parameterOffset = 0;
            if (m.IsStatic) parameterOffset = 1;

            if (m.IsConstructor)
            {
                // constructors get the object as last parameter on the stack instead of the first
                context.Code.Append("    uintptr_t parameter0 = pop_pointer();\n");
                context.Code.Append("    enum CIL_Type parameter0__type = CIL_pointer;\n");
                context.Code.Append("    gc_retain(0, parameter0);\n    linkedlist_append(&gcList, (uintptr_t)&parameter0);\n");
                context.Code.Append("    int skipDefaultInitialization = 0;\n");

                // TODO: typelist generation should be in init, so there is only one place typelists are malloc'd
                if (m.DeclaringType.BaseType.GenericTypeArguments.Length > 0)
                {
                    context.Code.AppendLine("    int base_typelist_length = " + m.DeclaringType.BaseType.GenericTypeArguments.Length + ";");
                    context.Code.AppendLine("    enum CIL_Type* base_typelist = malloc(sizeof(enum CIL_Type) * " + m.DeclaringType.BaseType.GenericTypeArguments.Length + ");");
                    for (int i = 0; i < m.DeclaringType.BaseType.GenericTypeArguments.Length; i++)
                    {
                        var gtype = m.DeclaringType.BaseType.GenericTypeArguments[i];
                        int i2 = m.DeclaringType.GetGenericArguments().ToList().IndexOf(gtype);
                        if (i2 == -1) context.Code.AppendLine("    base_typelist[" + i + "] = " + TypeHelper.GetInternalType(gtype) + ";");
                        else context.Code.AppendLine("    base_typelist[" + i + "] = generictypelist[" + i2 + "];");
                    }
                }
            }

            if (m.Name == ".cctor")
            {
                context.Code.Append(addedcode);
            }

            for (int i = m.GetParameters().Count() - 1; i >= 0; i--)
            {
                ParameterInfo p = m.GetParameters().Where(a => a.Position == i).First();
                if (p.ParameterType.IsValueType)
                {
                    int bits = TypeHelper.GetTypeSize(p.ParameterType);
                    if (bits <= 64 && bits > 0)
                    {
                        context.Code.Append("    int" + bits + "_t parameter" + (p.Position + 1 - parameterOffset) + " = pop_value" + bits + "();\n");
                    }
                    else
                    {
                        context.Code.Append("    int8_t parameter" + (p.Position + 1 - parameterOffset) + "[sizeof(struct " + Naming.ConvertTypeToCName(p.ParameterType.FullName) + ")];\n");
                        context.Code.Append("    memcpy(&parameter" + (p.Position + 1 - parameterOffset) + ", (void*)pop_pointer(), sizeof(struct " + Naming.ConvertTypeToCName(p.ParameterType.FullName) + "));\n");
                    }
                    context.Code.Append("    enum CIL_Type parameter" + (p.Position + 1 - parameterOffset) + "__type = " + TypeHelper.GetInternalType(p.ParameterType) + "; // " + p.ParameterType.FullName + "\n");
                }
                else
                {
                    if (p.ParameterType.IsGenericParameter)
                    {
                        context.Code.AppendLine("    enum CIL_Type parameter" + (p.Position + 1 - parameterOffset) + "__type = stack_top_type(); // " + p.ParameterType.Name);
                        context.Code.AppendLine("    int64_t parameter" + (p.Position + 1 - parameterOffset) + ";");
                        context.Code.AppendLine("    if (stack_top_size() == 8) {");
                        context.Code.AppendLine("        parameter" + (p.Position + 1 - parameterOffset) + " = pop_value64();");
                        context.Code.AppendLine("    } else {");
                        context.Code.AppendLine("        parameter" + (p.Position + 1 - parameterOffset) + " = pop_value32();");
                        context.Code.AppendLine("    }");
                        context.Code.AppendLine("    if (parameter" + (p.Position + 1 - parameterOffset) + "__type == CIL_pointer || parameter" + (p.Position + 1 - parameterOffset) + "__type == CIL_array) {\n        gc_retain(0, parameter" + (p.Position + 1 - parameterOffset) + ");\n    linkedlist_append(&gcList, (uintptr_t)&parameter" + (p.Position + 1 - parameterOffset) + ");\n    }");
                    }
                    else
                    {
                        context.Code.Append("    uintptr_t parameter" + (p.Position + 1 - parameterOffset) + " = pop_pointer();\n");
                        context.Code.Append("    enum CIL_Type parameter" + (p.Position + 1 - parameterOffset) + "__type = " + TypeHelper.GetInternalType(p.ParameterType) + "; // " + p.ParameterType.FullName + "\n");
                        if (TypeHelper.GetInternalType(p.ParameterType) == "CIL_pointer" || TypeHelper.GetInternalType(p.ParameterType) == "CIL_array")
                        {
                            context.Code.AppendLine("    gc_retain(0, parameter" + (p.Position + 1 - parameterOffset) + ");");
                            context.Code.AppendLine("    linkedlist_append(&gcList, (uintptr_t)&parameter" + (p.Position + 1 - parameterOffset) + ");");
                        }
                    }
                }
            }
            if (!m.IsStatic && !m.IsConstructor)
            {
                context.Code.AppendLine("    uintptr_t parameter0 = pop_pointer();");
                context.Code.AppendLine("    enum CIL_Type parameter0__type = CIL_pointer;");
                context.Code.AppendLine("    gc_retain(0, parameter0);");
                context.Code.AppendLine("    linkedlist_append(&gcList, (uintptr_t)&parameter0);");
            }

            if (m.IsConstructor && m.DeclaringType.IsValueType)
            {
                // Call the init of the valuetype in the constructor
                context.Code.AppendLine("    push_pointer(parameter0);");
                if (m.DeclaringType.IsGenericTypeDefinition)
                {
                    context.Code.AppendLine("    CIL_initobj_generic(" + Naming.ConvertTypeToCName(m.DeclaringType) + ", generictypelist_length, generictypelist);");
                }
                else
                {
                    SDILReader.ILInstruction ili = new SDILReader.ILInstruction();
                    ili.Code = System.Reflection.Emit.OpCodes.Initobj;
                    ili.Operand = m.DeclaringType;
                    context.Code.AppendLine(ili.GetCode(m, context));
                }
                //context.Code.AppendLine("    CIL_initobj(" + Naming.ConvertTypeToCName(m.DeclaringType) + ");");
            }

            context.Code.AppendLine("    int entryStackSize = stack_size();");
            context.Code.AppendLine("    int boundExceptions = 0;");

            string startscope = Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + "__start";
            context.Code.AppendLine("    void* method_start;");
            context.Code.AppendLine("    " + startscope + ": STORE_LABEL_ADDRESS(method_start, " + startscope + ");\n");

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

            if (m.IsStatic || m.DeclaringType.IsValueType)
            {
                context.Code.AppendLine("    " + Naming.ConvertTypeToCName(m.DeclaringType.FullName) + "__cctor_init();");
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
                            int bits = TypeHelper.GetTypeSize(l.LocalType);
                            if (bits <= 64 && bits > 0)
                            {
                                context.Code.Append("    int" + bits + "_t local" + l.LocalIndex + " = 0;\n");
                            }
                            else
                            {
                                context.Code.Append("    int8_t local" + l.LocalIndex + "[sizeof(struct " + Naming.ConvertTypeToCName(l.LocalType) + ")] = { 0 };\n");
                            }
                            context.Code.Append("    enum CIL_Type local" + l.LocalIndex + "__type = " + TypeHelper.GetInternalType(l.LocalType) + "; // " + l.LocalType.FullName + "\n");
                            if (TypeHelper.GetInternalType(l.LocalType) == "CIL_pointer" || TypeHelper.GetInternalType(l.LocalType) == "CIL_array")
                            {
                                context.Code.AppendLine("    linkedlist_append(&gcList, (uintptr_t)&local" + (l.LocalIndex) + ");");
                            }                            
                        }
                        else
                        {
                            if (l.LocalType.IsGenericParameter)
                            {
                                context.Code.Append("    int64_t local" + l.LocalIndex + " = 0;\n");
                                if (l.LocalType.DeclaringMethod == null)
                                {
                                    // class generic
                                    context.Code.Append("    enum CIL_Type local" + l.LocalIndex + "__type = ((struct System__Object*)parameter0)->__CILgenerictypelist[" + l.LocalType.GenericParameterPosition + "]; // " + l.LocalType.FullName + "\n");
                                }
                                else
                                {
                                    // method generic
                                    context.Code.Append("    enum CIL_Type local" + l.LocalIndex + "__type = generictypelist[" + l.LocalType.GenericParameterPosition + "]; // " + l.LocalType.FullName + "\n");
                                }
                                context.Code.AppendLine("    if (local" + l.LocalIndex + "__type == CIL_pointer || local" + l.LocalIndex + "__type == CIL_array) { linkedlist_append(&gcList, (uintptr_t)&local" + (l.LocalIndex) + "); }");
                            }
                            else
                            {
                                context.Code.Append("    uintptr_t local" + l.LocalIndex + " = 0;\n");
                                context.Code.Append("    enum CIL_Type local" + l.LocalIndex + "__type = " + TypeHelper.GetInternalType(l.LocalType) + "; // " + l.LocalType.FullName + "\n");
                                if (TypeHelper.GetInternalType(l.LocalType) == "CIL_pointer" || TypeHelper.GetInternalType(l.LocalType) == "CIL_array")
                                {
                                    context.Code.AppendLine("    linkedlist_append(&gcList, (uintptr_t)&local" + (l.LocalIndex) + ");");
                                }  
                            }
                        }
                    }

                    foreach (SDILReader.ILInstruction instr in mbr.instructions)
                    {
                        if (instr.Code == System.Reflection.Emit.OpCodes.Call)
                        {
                            if (((MethodBase)instr.Operand).IsConstructor)
                            {
                                if (skipFirstConstructorCall)
                                {
                                    context.Code.Append("    pop_pointer();\n");
                                    context.Code.Append(addedcode); // addedcode shoud have been afther this call, but this call is removed, so we handle the addedcode ourself.
                                    continue;
                                }

                                if (m.IsConstructor && ((ConstructorInfo)instr.Operand).DeclaringType == m.DeclaringType)
                                {
                                    // this is a constructor and it calls another constructor. This means that all fields are already set to a (default) value, and we shouldn't override it
                                    context.Code.Append("    skipDefaultInitialization = 1;\n");
                                }
                            }
                        }

                        string scope = Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name);
                        string label = scope + SDILReader.ILInstruction.GetExpandedOffset(instr.Offset);
                        context.Code.Append("    ");
                        context.Code.Append(label + ": ");

                        // exception code
                        // TODO: refactor
                        foreach (var exc in m.GetMethodBody().ExceptionHandlingClauses.Reverse())
                        {
                            switch (exc.Flags)
                            {
                                case ExceptionHandlingClauseOptions.Filter:
                                    throw new NotImplementedException(); // TODO: Exception: Filter
                                case ExceptionHandlingClauseOptions.Finally:
                                    if (instr.Offset == exc.TryOffset)
                                    {
                                        context.Code.AppendLine("register_finally(" + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset(exc.HandlerOffset) + ", " +
                                                "" + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset(exc.TryOffset) + ", " +
                                                exc.TryLength.ToString() + ");");
                                        context.Code.Append(new string(' ', label.Length + 6));
                                    }
                                    break;
                                case ExceptionHandlingClauseOptions.Fault:
                                    throw new NotImplementedException(); // TODO: Exception: Fault
                                case ExceptionHandlingClauseOptions.Clause:
                                    if (instr.Offset == exc.TryOffset)
                                    {
                                        context.Code.AppendLine("register_catch(\"" + exc.CatchType.FullName + "\", " +
                                            "" + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset(exc.HandlerOffset) + ", " +
                                            "" + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset(exc.TryOffset) + ", " +
                                            exc.TryLength.ToString() + ", " + "stack_size());");
                                        context.Code.Append(new string(' ', label.Length + 6));
                                    }
                                    if (instr.Offset == exc.TryOffset + exc.TryLength)
                                    {
                                        context.Code.AppendLine("// End try of type " + exc.CatchType.Name);
                                        context.Code.Append(new string(' ', label.Length + 6));
                                    }
                                    break;
                                default:
                                    throw new FormatException();
                            }
                        }

                        switch (instr.Code.Name)
                        {
                            case "br.s":
                            case "br":
                                context.Code.Append("goto " + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset((int)instr.Operand));
                                break;
                            /*case "leave.s":
                                int numexc = GetNumberOfExceptionHandlersForOffset(m.GetMethodBody(), instr.Offset);
                                context.Code.Append(Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset(instr.Offset) + ": ");
                                context.Code.Append("CIL_leave__s(" + Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name) + SDILReader.ILInstruction.GetExpandedOffset((int)instr.Operand) + ", " + numexc + ")");
                                break;*/
                            /*case "throw":
                                context.Code.Append("CIL_throw(" + label + ")");
                                break;*/
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

            context.Code.Append("    CIL_ret();\n}\n");
        }

    }
}
