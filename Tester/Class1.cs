using System;

namespace Tester
{
    class Test
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
    }

    class Program
    {
        static void Main(string[] args)
        {
            Test[] ints = new Test[4];
            ints[0] = new Test(1);
            ints[1] = new Test(2);
            ints[2] = new Test(3);
            ints[3] = new Test(4);
            System.Console.WriteLine(ints[3]);
        }
    }
}
