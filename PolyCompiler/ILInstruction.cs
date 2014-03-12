using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection.Emit;
using Poly.Internals.CompilerImplemented;
using System.Reflection;
using System.Runtime.InteropServices;
using PolyCompiler;

namespace SDILReader
{
    public class ILInstruction
    {
        // Fields
        private OpCode code;
        private object operand;
        //private byte[] operandData;
        private int offset;

        // Properties
        public OpCode Code
        {
            get { return code; }
            set { code = value; }
        }

        public object Operand
        {
            get { return operand; }
            set { operand = value; }
        }

        /*public byte[] OperandData
        {
            get { return operandData; }
            set { operandData = value; }
        }*/

        public int Offset
        {
            get { return offset; }
            set { offset = value; }
        }

        /// <summary>
        /// Returns a friendly strign representation of this instruction
        /// </summary>
        /// <returns></returns>
        public string GetCode(MethodBase m, CompilerContext context)
        {
            string result = "";
            bool putOpenParenthesis = true;
            string scope = Naming.ConvertTypeToCName(m.DeclaringType.FullName + "::" + m.Name);
            if (operand != null)
            {
                if (code.Name == "newobj")
                {
                    System.Reflection.ConstructorInfo mOperand = (System.Reflection.ConstructorInfo)operand;
                    if (mOperand.ReflectedType.IsGenericType)
                    {
                        string def = "generic_" + Naming.ConvertTypeToCName(mOperand.ReflectedType);
                        foreach (var gtype in mOperand.ReflectedType.GenericTypeArguments)
                        {
                            def += "_G_" + Naming.ConvertTypeToCName(gtype);
                        }

                        result += "CIL_newobj_generic(";
                        result += Naming.ConvertTypeToCName(mOperand.ReflectedType) + ", ";
                        result += Naming.GetInternalMethodName(mOperand) + ", ";
                        result += def + "__typelist_length, ";
                        result += def + "__typelist ";
                        result += "/* " + mOperand.DeclaringType.FullName + "::" + mOperand.Name + " */";

                        if (!context.GenericTypeListGenerated.Contains(mOperand.ReflectedType))
                        {
                            context.CodeHeader.AppendLine("static enum CIL_Type* " + def + "__typelist;");
                            context.CodeHeader.AppendLine("static int " + def + "__typelist_length;");
                            context.Init.AppendLine("    " + def + "__typelist_length = " + mOperand.ReflectedType.GenericTypeArguments.Length + ";");
                            context.Init.AppendLine("    " + def + "__typelist = malloc(sizeof(enum CIL_Type) * " + mOperand.ReflectedType.GenericTypeArguments.Length + ");");
                            for (int i = 0; i < mOperand.ReflectedType.GenericTypeArguments.Length; i++)
                            {
                                var gtype = mOperand.ReflectedType.GenericTypeArguments[i];
                                context.Init.AppendLine("    " + def + "__typelist[" + i + "] = " + TypeHelper.GetInternalType(gtype) + ";");
                            }

                            context.GenericTypeListGenerated.Add(mOperand.ReflectedType);
                        }
                    }
                    else
                    {
                        result += "CIL_newobj(";
                        result += Naming.ConvertTypeToCName(mOperand.ReflectedType) + ", ";
                        result += Naming.GetInternalMethodName(mOperand);
                        result += "/* " + mOperand.DeclaringType.FullName + "::" + mOperand.Name + " */";
                    }
                }

                /*else if (code.Name == "castclass")
                {
                    System.Reflection.ConstructorInfo mOperand = (System.Reflection.ConstructorInfo)operand;
                    result += Naming.ConvertTypeToCName(mOperand.ReflectedType.ToString()) + ", ";
                }*/
                else
                {
                    result += Naming.ConvertTypeToCName("CIL_" + code.Name);

                    if (code.Name == "stfld" || code.Name == "ldfld")
                    {
                        System.Reflection.FieldInfo fOperand = ((System.Reflection.FieldInfo)operand);
                        if (fOperand.DeclaringType.IsGenericType)
                        {
                            string gtypename = fOperand.DeclaringType.Namespace;
                            if (gtypename == null) gtypename = "";
                            else gtypename += ".";
                            gtypename += fOperand.DeclaringType.Name;
                            var thisfield = fOperand.DeclaringType.Assembly.GetType(gtypename).GetField(fOperand.Name);
                            if (thisfield.FieldType.IsGenericParameter)
                            {
                                result += "_generic";
                            }
                            else
                            {
                                result += "";
                            }
                        }
                        else
                        {
                            result += "";
                        }
                    }
                    if (code.Name == "call")
                    {
                        System.Reflection.ConstructorInfo fOperand = operand as ConstructorInfo;
                        if (fOperand != null && fOperand.DeclaringType.IsGenericType)
                        {
                            result += "_generic_ctor(";
                            result += "base_typelist_length, base_typelist, ";
                            putOpenParenthesis = false;
                        }
                    }

                    if (putOpenParenthesis) result += "(";
                    switch (code.OperandType)
                    {
                        case OperandType.InlineField:
                            System.Reflection.FieldInfo fOperand = ((System.Reflection.FieldInfo)operand);
                            /*result += PolyCompiler.Program.ConvertTypeToCName(fOperand.FieldType.ToString()) + " " +
                                PolyCompiler.Program.ConvertTypeToCName(fOperand.ReflectedType.ToString()) +
                                "::" + fOperand.Name + "";*/
                            result += Naming.ConvertTypeToCName(fOperand.DeclaringType) + ", " + Naming.ConvertTypeToCName(fOperand.Name);
                            break;
                        case OperandType.InlineMethod:
                            try
                            {
                                System.Reflection.MethodInfo mOperand = (System.Reflection.MethodInfo)operand;
                                if (!mOperand.IsStatic) result += "/*instance*/ ";
                                result += "" + Naming.GetInternalMethodName(mOperand);
                                result += ", \"" + Naming.GetInternalMethodName(mOperand, false) + "\"";
                                result += ", " + mOperand.GetParameters().Length + ", " + (mOperand.IsVirtual ? "1" : "0");
                                result += "/* " + mOperand.ReturnParameter.ParameterType.FullName + " " + mOperand.DeclaringType.FullName + "::" + mOperand.Name + "(";
                                foreach (var param in mOperand.GetParameters())
                                {
                                    result += param.ParameterType.FullName + ", ";
                                }
                                result += ") */";
                            }
                            catch
                            {
                                try
                                {
                                    System.Reflection.ConstructorInfo mOperand = (System.Reflection.ConstructorInfo)operand;
                                    if (!mOperand.IsStatic) result += "/*constructor*/ ";
                                    result += "" + PolyCompiler.Naming.GetInternalMethodName(mOperand);
                                    result += ", \"NONE\", " + mOperand.GetParameters().Length + ", 0";
                                    result += " /* " + mOperand.DeclaringType.FullName + "::" + mOperand.Name + "(";
                                    foreach (var param in mOperand.GetParameters())
                                    {
                                        result += param.ParameterType.FullName + ", ";
                                    }
                                    result += ") */";
                                }
                                catch
                                {
                                    throw new NotImplementedException();
                                }
                            }
                            break;
                        case OperandType.ShortInlineBrTarget:
                        case OperandType.InlineBrTarget:
                            result += scope;
                            result += GetExpandedOffset((int)operand);
                            break;
                        case OperandType.InlineType:
                            result += operand.ToString();
                            break;
                        case OperandType.InlineString:
                            string str = operand.ToString();
                            str = str.Replace("\\", "\\\\");
                            str = str.Replace("\n", @"\n");
                            str = str.Replace("\b", @"\b");
                            str = str.Replace("\f", @"\f");
                            str = str.Replace("\n", @"\n");
                            str = str.Replace("\r", @"\r");
                            str = str.Replace("\t", @"\t");
                            str = str.Replace("\v", @"\v");
                            str = str.Replace("'", @"\'");
                            str = str.Replace("\"", "\\\"");
                            str = str.Replace("?", @"\?");
                            result += "\"" + str + "\"";
                            break;
                        case OperandType.ShortInlineVar:
                            result += operand.ToString();
                            break;
                        case OperandType.InlineI:
                        case OperandType.ShortInlineI:
                            result += operand.ToString() + "u";
                            break;
                        case OperandType.InlineI8:
                            result += operand.ToString() + "ull";
                            break;
                        case OperandType.InlineR:
                            double d = (double)operand;
                            result += d.ToString("F").Replace(',', '.');
                            break;
                        case OperandType.ShortInlineR:
                            Single s = (Single)operand;
                            result += s.ToString("F").Replace(',', '.') + "f";
                            break;
                        case OperandType.InlineTok:
                            if (operand is Type)
                                result += ", " + ((Type)operand).FullName;
                            else if (operand is FieldInfo)
                            {
                                System.Reflection.FieldInfo o = ((System.Reflection.FieldInfo)operand);
                                if (!o.IsStatic)
                                {
                                    result += "field, ";
                                    result += PolyCompiler.Naming.ConvertTypeToCName(o.DeclaringType.FullName) + ", ";
                                    result += context.Offsets[o].ToString() + ", ";
                                    result += TypeHelper.GetTypeSize(o.FieldType) / 8;
                                }
                                else
                                {
                                    result += "static_field, ";
                                    result += PolyCompiler.Naming.ConvertTypeToCName(o.DeclaringType.FullName) + ", ";
                                    result += PolyCompiler.Naming.GetInternalFieldName(o.Name) + ", ";
                                    result += "0, ";
                                    result += TypeHelper.GetTypeSize(o.FieldType) / 8;
                                }
                            }
                            else
                                throw new NotImplementedException();
                            break;

                        default: result += "not supported"; break;
                    }
                }
            }
            else
            {
                result += Naming.ConvertTypeToCName("CIL_" + code.Name) + "(";
            }
            return result + ")";

        }

        /// <summary>
        /// Add enough zeros to a number as to be represented on 4 characters
        /// </summary>
        /// <param name="offset">
        /// The number that must be represented on 4 characters
        /// </param>
        /// <returns>
        /// </returns>
        public static string GetExpandedOffset(long offset)
        {
            string result = offset.ToString();
            for (int i = 0; result.Length < 4; i++)
            {
                result = "0" + result;
            }
            return result;
        }

        public ILInstruction()
        {

        }
    }
}
