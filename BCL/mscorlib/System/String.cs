namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"char *str;
    ")]
    class __String
    {
        // DO NOT ADD FIELDS OR PROPERTIES!!!

        __String() { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        struct System__String *other = (struct System__String*)parameter1;
	    this->str = (char*)malloc(strlen(other->str) + 1);
	    strcpy(this->str, other->str);
        CIL_ret();
        ")]
        __String(System.String str) { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *str0 = (struct System__String*)parameter0;
        struct System__String *str1 = (struct System__String*)parameter1;
        struct System__String *newstr;
        CIL_newobj(System__String, SYSTEM__STRING_ctor);
	    newstr = (struct System__String *)peek_pointer(0);
	    newstr->str = (char*)malloc(strlen(str0->str) + strlen(str1->str) + 1);
	    strcpy(newstr->str, str0->str);
        strcat(newstr->str, str1->str);
        CIL_ret();
        ")]
        public static string Concat(string str0, string str1) { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        push_value32(strlen(this->str), CIL_int32);
        ")]
        int get_Length() { return 0; }

        public static string Concat(object arg0, object arg1)
        {
            return Concat(arg0.ToString(), arg1.ToString());
        }

        public static string Concat(object arg0, object arg1, object arg2)
        {
            return Concat(arg0.ToString(), arg1.ToString(), arg2.ToString());
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *str0 = (struct System__String*)parameter0;
        struct System__String *str1 = (struct System__String*)parameter1;
        struct System__String *str2 = (struct System__String*)parameter2;
        struct System__String *newstr;
        CIL_newobj(System__String, SYSTEM__STRING_ctor);
	    newstr = (struct System__String *)peek_pointer(0);
	    newstr->str = (char*)malloc(strlen(str0->str) + strlen(str1->str) + strlen(str2->str) + 1);
	    strcpy(newstr->str, str0->str);
        strcat(newstr->str, str1->str);
        strcat(newstr->str, str2->str);
        CIL_ret();
        ")]
        public static string Concat(string arg0, string arg1, string arg2) { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        CIL_ldarg__0();
        CIL_ret();
        ")]
        public override string ToString() { return null; }
    }
}
