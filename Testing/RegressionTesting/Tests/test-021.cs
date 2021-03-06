using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    class I<T>
    {
        public T var;
        public int intvar;

        public T getVar()
        {
            return var;
        }

        public void setVar(T v) 
        {
            var = v;
        }
    }

    class X
    {
        public static int Main()
        {
            I<Int64> a = new I<Int64>();
            a.var = 987;
            a.intvar = 5;

            if (a.var != 987) return 1;
            if (a.intvar != 5) return 2;

            a.setVar(21474836479L);
            if (a.var != 21474836479L) return 3;

            a.setVar(21474836476L);
            if (a.getVar() != 21474836476L) return 4;

            return 200;
        }

    }
}