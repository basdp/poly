using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    class TypeHelper
    {
        public static int GetTypeSize(Type type)
        {
            if (GetInternalType(type) == "CIL_valuetype")
            {
                int bits = Marshal.SizeOf(type) + 4 * 6;
                return -1;
            }
            else
            {
                int bits = Marshal.SizeOf(type) * 8;
                if (bits < 32) bits = 32;
                return bits;
            }
        }

        public static string GetInternalType(Type type)
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
                    if (type.IsValueType)
                        return "CIL_valuetype";
                    else
                        return "CIL_pointer";
            }
        }
    }
}
