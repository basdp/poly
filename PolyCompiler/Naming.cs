﻿using System;
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
            string fullname = m.DeclaringType.FullName;
            if (m.DeclaringType.IsGenericType && fullname.IndexOf('[') != -1) fullname = fullname.Substring(0, fullname.IndexOf('['));
            string path = fullname.Replace(".__", ".");
            string type = m.Name;
            type = type.TrimStart(new char[] { '_' });
            string sig;
            if (includePath)
                sig = path + "::" + type;
            else
                sig = type;
            foreach (var p in m.GetParameters())
            {
                sig += "__" + p.ParameterType.FullName.Replace(".__", ".");
            }

            MethodInfo mi = m as MethodInfo;
            if (mi != null) 
                sig = mi.ReturnType.FullName + "__" + sig;


            System.Text.ASCIIEncoding encoder = new System.Text.ASCIIEncoding();
            string ret = "m" + BitConverter.ToString(sha.ComputeHash(encoder.GetBytes(sig))).Replace("-", "");
            return ConvertTypeToCName(ret.ToString());
        }
        public static string GetInternalMethodName(string name)
        {
            string sig = name;
            System.Text.ASCIIEncoding encoder = new System.Text.ASCIIEncoding();
            string ret = "m" + BitConverter.ToString(sha.ComputeHash(encoder.GetBytes(sig))).Replace("-", "");
            return ConvertTypeToCName(ret.ToString());
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
            type = type.Replace("`", "__");

            return type;
        }

        public static string ConvertTypeToCName(Type type)
        {
            string fullname = "";
            if (!type.IsGenericType) return ConvertTypeToCName(type.FullName);

            fullname = type.FullName;
            if (fullname.IndexOf('[') != -1) fullname = fullname.Substring(0, type.FullName.IndexOf('['));
            /*foreach (var p in type.GenericTypeArguments)
            {
                fullname += "<" + p.FullName + ">";
            }*/
            return ConvertTypeToCName(fullname);
        }

    }
}
