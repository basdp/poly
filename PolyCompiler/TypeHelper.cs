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
            int bytes = Marshal.SizeOf(type) * 8;
            if (bytes < 32) bytes = 32;
            return bytes;
        }
    }
}
