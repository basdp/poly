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

        public T getVar2()
        {
            return var2;
        }
    }

    class X
    {
        public static int Main()
        {
            I<Int64> i = new I<Int64>();
            i.var2 = 21474836478L;
            Console.WriteLine(i.getVar2());

            return 200;
        }

    }
}