using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Reflection;


class D
{
    public static int Main(string[] args)
    {
        List<long> l = new List<long>();

        l.Add(9);
        l.Add(12345678908);
        l.Add(7);
        l.Add(6);
        l.Add(5);

        foreach (var s in l)
        {
            Console.WriteLine(s);
        }

        //for (int i = 0; i < l.Count; i++)
        //    Console.WriteLine(l[i]);

        return 200;
    }
}
