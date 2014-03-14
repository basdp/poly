namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"int64_t value;
    ")]
    class __Int64
    {
        __Int64()
        {
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        char buffer[24];
        struct System__Int64 *this = (struct System__Int64*)parameter0;
        snprintf(buffer, 24, ""%lld"", this->value);
        CIL_ldstr(buffer);
        ")]
        public override string ToString() { return null; }
    }
}
