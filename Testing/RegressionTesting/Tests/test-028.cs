using System;
using System.Threading;
using System.Reflection;

namespace ILD
{
    class H<T>
    {

        public T var;
        public T getVar()
        {
            return var;
        }
    }

    class I<T> : H<T>
    {
        public int intvar;

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
            
            a.setVar(21474836479L);
            if (a.var != 21474836479L) return 3;

            a.setVar(21474836476L);
            if (a.getVar() != 21474836476L) 
                return 1;

            return 200;
        }

    }
}