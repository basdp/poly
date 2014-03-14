using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    struct H
    {
        public int a;
        public bool b;
        public double d;
    }

    class I<T>
    {
        public int intvar;

        public void setVar(T v)
        {
            var = v;
        }

        public T var;
        public T getVar()
        {
            return var;
        }
    }

    class X
    {
        public static int Main()
        {
            I<H> a = new I<H>();
            a.var = new H() { a = 3, b = false, d = 23.34 };

            if (a.getVar().d != 23.34)
                return 1;

            return 200;
        }

    }
}