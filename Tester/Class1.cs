using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class E
{
    public static int Main(string[] args)
    {
        
        Console.WriteLine(args[0]);
        return 0;
    }
}

/*
class D
{
    public static int Main(string[] args)
    {
        ArrayList l = new ArrayList();

        l.Add("string1");
        l.Add("string2");
        l.Add("string3");
        l.Add("string4");
        l.Add("string5");
        l.Add(4);

        l[2] = 4.45;

        foreach (var s in l)
        {
            Console.WriteLine(s);
        }

        //for (int i = 0; i < l.Count; i++)
        //    Console.WriteLine(l[i]);

        return 200;
    }
}*/

/*
interface ITest
{
    int GetSomething();
}

class W : ITest
{
    public static int Main(string[] args)
    {
        ITest foo = new W();
        Console.WriteLine(foo.GetSomething());

        return 200;
    }

    public int GetSomething()
    {
        return 5;
    }
}*/