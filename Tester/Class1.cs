using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Reflection;


class D
{
    public static void test(out long hoi)
    {
        hoi = 1234567890987;
    }

    public static int Main(string[] args)
    {
        long hoi = 9;
        test(out hoi);
        Console.WriteLine(hoi);

        return 200;
    }
}
