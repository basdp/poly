using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace jk
{
    class A
    {
        public int val;

        public A()
        {
            Console.WriteLine("A()");
            val = 10;
        }

        public A(int v)
        {
            Console.WriteLine("A(int)");
            val = v;
        }
    }

    class B : A
    {
        public B()
            : base(65)
        {
            Console.WriteLine("B()");
        }

    }

    class D
    {
        public static int Main(string[] args)
        {
            A a1 = new A();
            if (a1.val != 10) return 1;

            A a2 = new A(32);
            if (a1.val != 32) return 1;

            B b = new B();
            if (a1.val != 65) return 1;

            return 200;
        }
    }
}