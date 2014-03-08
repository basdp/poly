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
            context.Code.Append("// class " + type.FullName + "\n");

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
                addedcode += "    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&" + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses;\n";
                addedcode += "    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &" + Naming.ConvertTypeToCName(type.FullName) + "__baseclasses_length;\n";
                foreach (var virtmethod in type.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).Where(m => m.IsVirtual))
                {
                    addedcode += "    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, \"" + Naming.GetInternalMethodName(virtmethod, false) + "\", &" + Naming.GetInternalMethodName(virtmethod) +
                   "); /* " + virtmethod.Name + " */\n";
                }
                FieldInfo[] fis = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
                for (int k = 0; k < fis.Length; k++)
                {
                    addedcode += "    ((struct " + Naming.ConvertTypeToCName(type.FullName) +"*)parameter0)->";
                    if (fis[k].FieldType.IsValueType)
                    {
                        int bits = TypeHelper.GetTypeSize(fis[k].FieldType);
                        if (bits <= 64)
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
                    }
                    addedcode += "\n";
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
            if (m.Name == "Main" && m.IsStatic)
            {
                // yay, we found a entry point
                // TODO: what if multiple Main?

                context.Main.AppendLine("int main(int argc, char** argv) {");
                context.Main.AppendLine("    int entryStackSize = 0;");
                context.Main.AppendLine("    int boundExceptions = 0;");

                if (m.GetParameters().Count() == 1)
                {
                    context.Main.AppendLine("    push_value32(argc - 1, CIL_int32);");
                    context.Main.AppendLine("    CIL_newarr(System.String);");
                    context.Main.AppendLine("    uintptr_t args = pop_pointer();");
                    context.Main.AppendLine("    int i;");
                    context.Main.AppendLine("    for(i = 1; i < argc; i++) {");
                    context.Main.AppendLine("        push_pointer(args);");
                    context.Main.AppendLine("        push_value32(i - 1, CIL_int32);");
                    context.Main.AppendLine("        CIL_ldstr(argv[i]);");
                    context.Main.AppendLine("        CIL_stelem__ref();");
                    context.Main.AppendLine("    }");
                    context.Main.AppendLine("    push_pointer(args);");
                }
                else if (m.GetParameters().Count() > 1)
                {
                    throw new NotImplementedException(); // I think this is illegal also
                }

                context.Main.AppendLine("    CIL_call(" + Naming.GetInternalMethodName(m) + ", \"" + Naming.GetInternalMethodName(m, false) + "\", " + m.GetParameters().Count() + ", 0);");

                context.Main.AppendLine("    if (stack_size() > 1 || (stack_size() > 0 && stack_top_type() == CIL_int32)) { printf(\"DEBUG WARNING: Stack is not empty at end of program. (int32 for return is allowed)\\n\"); print_stack(); }\n");
                context.Main.AppendLine("    if (stack_size() > 0 && stack_top_type() == CIL_int32) { return pop_value32(); }\n");
                context.Main.AppendLine("    else { return 0; }\n");
                
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
            context.Code.Append("void *" + Naming.GetInternalMethodName(m) + "(/*");
            if (m.GetParameters().Count() > 0)
                context.Code.Append(m.GetParameters().Select(p => p.ParameterType.Name + " " + p.Name).Aggregate((a, b) => a + ", " + b));
            context.Code.Append("*/) {\n");

            context.Header.Append("/* " + m.DeclaringType.FullName + "::" + m.Name + " */\n");
            context.Header.AppendLine("extern char* " + Naming.GetInternalMethodName(m) + "_sig;");
            context.Header.Append("void *" + Naming.GetInternalMethodName(m) + "(/*");
            if (m.GetParameters().Count() > 0)
                context.Header.Append(m.GetParameters().Select(p => p.ParameterType.Name + " " + p.Name).Aggregate((a, b) => a + ", " + b));
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

            context.Code.AppendLine("    int entryStackSize = stack_size();");
            context.Code.AppendLine("    int boundExceptions = 0;");

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
