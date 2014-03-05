using System;

namespace Tester
{
    class Test
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

    class Program
    {
        //static int bas = 25;

        static void Main(string[] args)
        {
            //bas = 42;


            //Test[] ints = new Test[] { new Test(1), new Test(2), new Test(3), new Test(4) };
            //Test[] ints = new Test[] { }
            //double[] ints = new double[] { 1.1, 2.2, 3.3, 4.4, 5.5 };
            //ints[4] = 4.5;
            //System.Console.WriteLine(ints[3]);

            string str = "hoi Bas";
            //char s = str[3];

            int d = 4;
            if (d < 5)
            {
                System.Console.WriteLine("Yeah");
            }

            //System.Console.WriteLine(ints[3].ToString());
        }
    }
}
