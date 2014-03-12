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

    class I<T>
    {
        public T var;
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
            a.intvar = 5;
            Console.WriteLine(a.var);
            Console.WriteLine(a.intvar);

            I<string> b = new I<string>();
            b.var = "hoi";

            Console.WriteLine(b.var);

            return 200;
        }

    }
}