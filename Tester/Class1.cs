using System;

namespace Tester
{
    /*class Test
    {
        static int sdf {
            get; set;
        }

        int value = 90;
        public Test(int val)
        {
            value = val;
        }

        public int getVal() { return value; }

        public override string ToString()
        {
            return "Test: " + getVal();
        }
    }
    */
    class Program
    {

        static void aaa(int a)
        {
            if (a < 5)
            {
                throw new NullReferenceException();
            }
        }
        static void Test6(int a)
        {
            try
            {
                aaa(a);
                Console.WriteLine("NO EX");
            }
            catch (NullReferenceException)
            {
                Console.WriteLine("NRE");
                throw;
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


        static void Main(string[] args)
        {
            string str = "goedendag";

            try
            {
                int a = 4;
                Console.WriteLine(a);
                Test6(a);
            }
            catch (Exception e)
            {
                Console.WriteLine("EX MAIN");
                Console.WriteLine(e.StackTrace);
            }
            finally
            {
                Console.WriteLine("FI2");
            }
        }

    }
}
