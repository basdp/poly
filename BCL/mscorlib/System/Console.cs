using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
    public class Console
    {
        [Poly.Internals.CompilerImplemented.InlineCode(@"
            printf(""%c\n"", parameter0);
        ")]
        public static void WriteLine(char value) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
            printf(""%i\n"", parameter0);
        ")]
        public static void WriteLine(int value) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
            printf(""%lld\n"", (int64_t)parameter0);
        ")]
        public static void WriteLine(Int64 value) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
            printf(""%i\n"", parameter0);
        ")]
        public static void WriteLine(byte value) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
            float f;
            memcpy(&f, &parameter0, 4);
            printf(""%.6f\n"", f);
        ")]
        public static void WriteLine(float value) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
            double f;
            memcpy(&f, &parameter0, 8);
            printf(""%.14f\n"", f);
        ")]
        public static void WriteLine(double value) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
            char *str = CIL_getCStringFromSystemString(parameter0);
            printf(""%s\n"", str);
        ")]
        public static void WriteLine(string value) { }

        public static void WriteLine(object value)
        {
            WriteLine(value.ToString());
        }
    }
}
