using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class exception1
{
    static void Test1()
    {
        try
        {
            throw new Exception();
            Console.WriteLine("NI");
        }
        catch (Exception)
        {
            Console.WriteLine("EX");
        }
        Console.WriteLine("CO");
    }

    static void Test2()
    {
        object o = null;
        try
        {
            o.ToString();
        }
        catch (NullReferenceException)
        {
            Console.WriteLine("NRE");
        }
        catch (Exception)
        {
            Console.WriteLine("RE");
        }
    }

    static void Test3()
    {
        try
        {
            throw new NotImplementedException();
        }
        catch (NullReferenceException)
        {
            Console.WriteLine("NIE");
        }
        catch (Exception)
        {
            Console.WriteLine("RE");
        }
    }

    static void Test4()
    {
        try
        {
            throw new NotImplementedException();
        }
        catch (NullReferenceException)
        {
            Console.WriteLine("NRE");
        }
        catch (Exception)
        {
            Console.WriteLine("RE");
        }
        finally
        {
            Console.WriteLine("FI");
        }
    }

    static void NestedException()
    {
        throw new NullReferenceException();
    }

    static void Test5()
    {
        try
        {
            NestedException();
        }
        catch (NullReferenceException)
        {
            Console.WriteLine("NRE");
        }
        catch (Exception)
        {
            Console.WriteLine("RE");
        }
        finally
        {
            Console.WriteLine("FI");
        }
    }
    static void NestedException2()
    {
        try
        {
            throw new Exception();
        }
        finally
        {
            Console.WriteLine("FI1");
        }
    }

    static void Test6()
    {
        try
        {
            NestedException2();
        }
        catch (NullReferenceException)
        {
            Console.WriteLine("NRE");
        }
        catch (Exception)
        {
            Console.WriteLine("RE");
        }
        finally
        {
            Console.WriteLine("FI2");
        }
    }

    static void Test7NestedException2()
    {
        try
        {
            try
            {
                throw new Exception();
            }
            finally
            {
                Console.WriteLine("FI0");
            }
        }
        finally
        {
            Console.WriteLine("FI1");
        }
    }

    static void Test7NestedException1()
    {
        Console.WriteLine("a");
        Test7NestedException2();

        Console.WriteLine("b");
    }

    static void Test7()
    {
        try
        {
            Test7NestedException1();
        }
        catch (NullReferenceException)
        {
            Console.WriteLine("NRE");
        }
        catch (Exception)
        {
            Console.WriteLine("RE");
        }
        finally
        {
            Console.WriteLine("FI2");
        }
    }
    static void Main(string[] args)
    {
        if (args.Length != 1) return;

        if (args[0] == "1") Test1();
        if (args[0] == "2") Test2();
        if (args[0] == "3") Test3();
        if (args[0] == "4") Test4();
        if (args[0] == "5") Test5();
        if (args[0] == "6") Test6();
        if (args[0] == "7") Test7();
    }
}
