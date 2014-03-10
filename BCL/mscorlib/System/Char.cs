namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"uint16_t value;
    ")]
    class __Char
    {
        __Char()
        {
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        char buffer[2];
        struct System__Char *this = (struct System__Char*)parameter0;
        buffer[0] = (char)this->value;
        buffer[1] = '\0';
        CIL_ldstr(buffer);
        ")]
        public override string ToString() { return null; }
    }
}
