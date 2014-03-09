namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"int32_t value;
    ")]
    class __Int32 : __ValueType
    {
        __Int32()
        {
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        char buffer[12];
        struct System__Int32 *this = (struct System__Int32*)parameter0;
        snprintf(buffer, 12, ""%d"", this->value);
        CIL_ldstr(buffer);
        ")]
        public override string ToString() { return null; }
    }
}
