using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"int32_t value;
    ")]
    class __Single
    {
        __Single()
        {
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        char buffer[12];
        struct System__Single *this = (struct System__Single*)parameter0;
        float f;
        memcpy(&f, &this->value, 4);
        snprintf(buffer, 12, ""%.6f"", this->value);
        CIL_ldstr(buffer);
        ")]
        public override string ToString() { return null; }
    }
}
