using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
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


/*
class D
{
    public static int Main(string[] args)
    {
        List<string> l = new List<string>();

        l.Add("string1");
        l.Add("string2");
        l.Add("string3");
        l.Add("string4");
        l.Add("string5");

        foreach (var s in l)
        {
            Console.WriteLine(s);
        }

        //for (int i = 0; i < l.Count; i++)
        //    Console.WriteLine(l[i]);

        return 200;
    }
}
*/