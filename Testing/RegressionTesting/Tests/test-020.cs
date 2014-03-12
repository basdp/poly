using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    struct Test
    {
        public int a;
        public int b;
        public int c;
    }

    class H<T, I>
    {
        public T ds;
        public I var;
    }

    class I<T> : H<int, T>
    {
        public T var2;
        public int intvar;
    }

    class X
    {
        public static int Main()
        {
            //I<Test> a = new I<Test>();
            //a.var = new Test() { a = 3, b = 5, c = 6 };
            I<Int64> a = new I<Int64>();
            a.var = 21474836478L;
            a.var2 = 4567;
            a.intvar = 5;

			if (a.var != 21474836478L) return 1;
			if (a.intvar != 5) return 2;
			if (a.var2 != 4567) return 3;
			
            I<string> b = new I<string>();
            b.var = "hoi";

			if (b.var != "hoi") return 4;
			
            return 200;

            return 200;
        }

    }
}