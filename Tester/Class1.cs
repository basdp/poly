using System;

namespace Tester
{
    /*class Test
    {
        int value;
        public Test(int val)
        {
            value = val;
        }

        public int getVal() { return value; }

        public override string ToString()
        {
            return "Test: " + getVal();
        }
    }*/

    class Program
    {
        //static int bas = 25;

        static void Main(string[] args)
        {
            //bas = 42;

            /*
            Test[] ints = new Test[4];
            ints[0] = new Test(1);
            ints[1] = new Test(2);
            ints[2] = new Test(3);
            ints[3] = new Test(4);*/
            //Test[] ints = new Test[] { }
            int[] ints = new[] { 1, 2, 3, 4, 5 };
            System.Console.WriteLine(ints[3]);
            //System.Console.WriteLine(bas);
        }
    }
}
