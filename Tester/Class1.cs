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
        //static int bas = 25;

        static void Bla(int i)
        {
            //Console.WriteLine(Environment.StackTrace);
            
            Console.WriteLine(i);
            if (i > 4)
            {
                throw new NotImplementedException();
            }

            try
            {
                Bla(i + 1);
            }
            catch (Exception)
            {
                Console.WriteLine("Should happen " + i);
            }
            finally
            {
                Console.WriteLine("Fin: " + i);
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

        static int get() { return 10; }

        static void Main(string[] args)
        {
            Test6();
        }

    }
}
