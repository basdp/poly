using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class exception1
{
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

    static void Main(string[] l)
    {
        string[] args = l;
        if (args.Length != 1) args = new string[] { "3" };
        
        Test3();
    }
}
