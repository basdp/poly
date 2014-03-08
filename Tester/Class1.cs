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
<<<<<<< HEAD

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
=======
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
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
            }
        }


<<<<<<< HEAD
        static void Main(string[] args)
        {
            try
            {
                int a = 4;
                Test6(a);
            }
            catch (Exception e)
            {
                Console.WriteLine("EX MAIN");
                Console.WriteLine(e.StackTrace);
=======
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
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
            }
            finally
            {
                Console.WriteLine("FI2");
            }
        }

<<<<<<< HEAD
=======
        static int get() { return 10; }

        static void Main(string[] args)
        {
            Test6();
        }

>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
    }
}
