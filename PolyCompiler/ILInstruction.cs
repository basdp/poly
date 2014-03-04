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
        public string GetCode(string extraCode = "")
        {
            string result = "";
            result += GetExpandedOffset(offset) + ": " + extraCode + PolyCompiler.Program.ConvertTypeToCName("CIL_" + code.Name) + "(";
            if (operand != null)
            {
                if (code.Name == "newobj")
                {
                    System.Reflection.ConstructorInfo mOperand = (System.Reflection.ConstructorInfo)operand;
                    result += PolyCompiler.Program.ConvertTypeToCName(mOperand.ReflectedType.ToString()) + ", ";
                    result += PolyCompiler.Program.GetInternalMethodName(mOperand);
                    result += "/* " + mOperand.DeclaringType.FullName + "::" + mOperand.Name + " */";
                }
                else
                {
                    switch (code.OperandType)
                    {
                        case OperandType.InlineField:
                            System.Reflection.FieldInfo fOperand = ((System.Reflection.FieldInfo)operand);
                            /*result += PolyCompiler.Program.ConvertTypeToCName(fOperand.FieldType.ToString()) + " " +
                                PolyCompiler.Program.ConvertTypeToCName(fOperand.ReflectedType.ToString()) +
                                "::" + fOperand.Name + "";*/
                            result += PolyCompiler.Program.ConvertTypeToCName(fOperand.DeclaringType.FullName) + ", " + PolyCompiler.Program.ConvertTypeToCName(fOperand.Name);
                            break;
                        case OperandType.InlineMethod:
                            try
                            {
                                System.Reflection.MethodInfo mOperand = (System.Reflection.MethodInfo)operand;
                                if (!mOperand.IsStatic) result += "/*instance*/ ";
                                result += "&" + PolyCompiler.Program.GetInternalMethodName(mOperand);
                                result += ", \"" + PolyCompiler.Program.GetInternalMethodName(mOperand, false) + "\"";
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
                                    result += "&" + PolyCompiler.Program.GetInternalMethodName(mOperand);
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
                                }
                            }
                            break;
                        case OperandType.ShortInlineBrTarget:
                        case OperandType.InlineBrTarget:
                            result += GetExpandedOffset((int)operand);
                            break;
                        case OperandType.InlineType:
                            result += operand.ToString();
                            break;
                        case OperandType.InlineString:
                            if (operand.ToString() == "\r\n") result += " \"\\r\\n\"";
                            else result += "\"" + operand.ToString() + "\"";
                            break;
                        case OperandType.ShortInlineVar:
                            result += operand.ToString();
                            break;
                        case OperandType.InlineI:
                        case OperandType.InlineI8:
                        case OperandType.ShortInlineI:
                            result += operand.ToString();
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
                                    result += PolyCompiler.Program.ConvertTypeToCName(o.DeclaringType.FullName) + ", ";
                                    result += Program.Offsets[o].ToString() + ", ";
                                    result += Program.GetTypeSize(o.FieldType) / 8;
                                }
                                else
                                {
                                    result += "static_field, ";
                                    result += PolyCompiler.Program.ConvertTypeToCName(o.DeclaringType.FullName) + ", ";
                                    result += PolyCompiler.Program.GetInternalFieldName(o.Name) + ", ";
                                    result += "0, ";
                                    result += Program.GetTypeSize(o.FieldType) / 8;
                                }
                            }
                            else
                                throw new NotImplementedException();
                            break;

                        default: result += "not supported"; break;
                    }
                }
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
