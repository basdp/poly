using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"int64_t value;
    ")]
    class __Double
    {
        __Double()
        {
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        char buffer[24];
        struct System__Double *this = (struct System__Double*)parameter0;
        double d;
        memcpy(&d, &this->value, 8);
        snprintf(buffer, 24, ""%.12f"", this->value);
        CIL_ldstr(buffer);
        ")]
        public override string ToString() { return null; }
    }
}
