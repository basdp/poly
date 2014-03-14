using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    class I<T>
    {
        public T var;
        public int intvar;
    }
    
    class X
    {
        public static int Main()
        {
            I<Int64> a = new I<Int64>();
            a.var = 21474836478L;
            a.intvar = 5;

            if (a.var != 21474836478L) return 1;
            if (a.intvar != 5) return 2;

            I<string> b = new I<string>();
            b.var = "hoi";

            if (b.var != "hoi") return 3;

            return 200;
        }

    }
}