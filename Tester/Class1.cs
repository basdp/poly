using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    class D<T, U> 
    {
        public T tval;
        public U uval;
    }

    class H<T>: D<int, T>
    {
        public T t1val;
    }

    class I<T>: H<T>
    {
        public int intvar;

        public void setVar(T v)
        {
            var = v;
        }

        public T var;
        public T getVar()
        {
            return uval;
        }
    }

    class X
    {
        public static int Main()
        {
            I<long> a = new I<long>();
            a.uval = 908765746576897L;
            a.tval = 89;

            Console.WriteLine(a.uval);
            Console.WriteLine(a.getVar());

            return 200;
        }

    }
}