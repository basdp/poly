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
        throw new Exception("muhaha");
    }
}
