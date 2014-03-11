using System;
using System.Threading;
using System.Reflection;

struct Test
{
    public int a;
    public int b;
    public int c;
}

class I<T>
{
    public T var;
}

class X
{
    public static int Main()
    {
        //I<Test> a = new I<Test>();
        //a.var = new Test() { a = 3, b = 5, c = 6 };
        I<Int64> a = new I<Int64>();
        a.var = 9;
        Console.WriteLine(a.var);

        I<string> b = new I<string>();
        b.var = "hoi";

        Console.WriteLine(b.var);

        return 200;
    }

}