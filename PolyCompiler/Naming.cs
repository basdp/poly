using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    class Naming
    {
        static SHA1 sha = new SHA1CryptoServiceProvider();

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
                    return "CIL_pointer";
            }
            return "CIL_unknown";
        }
        
        public static string GetInternalFieldName(string f)
        {
            f = f.Replace("$$", "_f_");
            f = f.Replace("-", "_");
            f = f.Replace("<", "_");
            f = f.Replace(">", "_");
            return f;
        }

        public static string ConvertTypeToCName(string type)
        {
            type = type.Replace(".__", ".");
            type = type.Replace(".", "__");
            type = type.Replace("::", "_m_");

            type = type.Replace("<", "_");
            type = type.Replace(">", "_");

            type = type.Replace("{", "__");
            type = type.Replace("}", "__");
            type = type.Replace("+", "_plus_");
            type = type.Replace("-", "_");
            type = type.Replace("=", "_eq_");

            return type;
        }

    }
}
