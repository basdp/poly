using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    class CompilerImplementation
    {
        internal static void InlineCode(string code, string lang, ref string result)
        {
            if (lang != "C") throw new NotImplementedException();

            result += "{" + code + "}";
        }
    }
}
