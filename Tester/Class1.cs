using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace jk
{
    class D
    {
        public static int Main(string[] args)
        {
            ArrayList l = new ArrayList();

            l.Add("string1");
            l.Add("string2");
            l.Add("string3");
            l.Add("string4");
            l.Add("string5");
            l.Add(4);

            l[2] = 4.45;

            foreach (var s in l)
            {
                Console.WriteLine(s);
            }

            //for (int i = 0; i < l.Count; i++)
            //    Console.WriteLine(l[i]);

                return 200;
        }
    }
}