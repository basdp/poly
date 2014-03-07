using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Poly.TestFramework
{
    public class Assert
    {
        public static void AreEqual(object a, object b)
        {
            AreEqual(a, b, "");
        }
        public static void AreEqual(object a, object b, string message)
        {
            if (a.Equals(b))
            {

            }
        }
    }
}
