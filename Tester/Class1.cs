using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    /*class S<T> where T : new()
    {
        public T hoi;

        public T geth(T hoi)
        {
            T i = new T();
            return i;
        }

    }*/

    class X
    {
        public static DKJ Test<DKJ>(int i, DKJ u)
        {
            Console.WriteLine(i);
            Console.WriteLine(u);
            return u;
        }

        public static int Main()
        {

            Console.WriteLine(Test<string>(4, "hoi"));

            return 200;
        }

    }
}