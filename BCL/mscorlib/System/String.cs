namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"char *str;
    ")]
    class __String
    {
        // DO NOT ADD FIELDS OR PROPERTIES!!!

        // TODO: String is array of UTF16 (2 byte) chars

        __String() { }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        struct System__String *other = (struct System__String*)parameter1;
        this->str = (char*)malloc(strlen(other->str) + 1);
        strcpy(this->str, other->str);
        CIL_ret();
        ")]
        __String(System.String str) { }

        //TODO: with concat, a null string will be converted to a empty string (so no nullpointerreference exceptions!

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *str0 = (struct System__String*)parameter0;
        struct System__String *str1 = (struct System__String*)parameter1;
        struct System__String *newstr;
        CIL_newobj(System__String, SYSTEM__STRING_ctor);
        newstr = (struct System__String *)peek_pointer(0);
        if (str0 == 0) throw_NullReferenceException();
        if (str1 == 0) throw_NullReferenceException();
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
        if (str0 == 0) throw_NullReferenceException();
        if (str1 == 0) throw_NullReferenceException();
        if (str2 == 0) throw_NullReferenceException();
        newstr->str = (char*)malloc(strlen(str0->str) + strlen(str1->str) + strlen(str2->str) + 1);
        strcpy(newstr->str, str0->str);
        strcat(newstr->str, str1->str);
        strcat(newstr->str, str2->str);
        CIL_ret();
        ")]
        public static string Concat(string arg0, string arg1, string arg2) { return null; }

        public static string Concat(object arg0, object arg1, object arg2, object arg3)
        {
            return Concat(arg0.ToString(), arg1.ToString(), arg2.ToString(), arg3.ToString());
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *str0 = (struct System__String*)parameter0;
        struct System__String *str1 = (struct System__String*)parameter1;
        struct System__String *str2 = (struct System__String*)parameter2;
        struct System__String *str3 = (struct System__String*)parameter3;
        struct System__String *newstr;
        CIL_newobj(System__String, SYSTEM__STRING_ctor);
        newstr = (struct System__String *)peek_pointer(0);
        if (str0 == 0) throw_NullReferenceException();
        if (str1 == 0) throw_NullReferenceException();
        if (str2 == 0) throw_NullReferenceException();
        if (str3 == 0) throw_NullReferenceException();
        newstr->str = (char*)malloc(strlen(str0->str) + strlen(str1->str) + strlen(str2->str) + strlen(str3->str) + 1);
        strcpy(newstr->str, str0->str);
        strcat(newstr->str, str1->str);
        strcat(newstr->str, str2->str);
        strcat(newstr->str, str3->str);
        CIL_ret();
        ")]
        public static string Concat(string arg0, string arg1, string arg2, string arg3) { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        CIL_ldarg__0();
        CIL_ret();
        ")]
        public override string ToString() { return null; }


        public static bool operator ==(__String a, __String b)
        {
            return a.Equals(b);
        }

        public static bool operator !=(__String a, __String b)
        {
            return !a.Equals(b);
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        struct System__String *other = (struct System__String*)parameter1;
        if (strcmp(this->str, other->str) == 0) {
            push_value32(1, CIL_int32);
        } else {
            push_value32(0, CIL_int32);
        }
        ")]
        public bool Equals(__String other)
        { return false; }

        public override bool Equals(object obj)
        {
            if (obj.GetType().Equals(this.GetType())) return Equals((string)obj);
            return false;
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        unsigned long hash = 5381;
        int c;
        char* str = this->str;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        push_value32((int32_t)hash, CIL_int32);
        ")]
        public override int GetHashCode()
        { return 0; }

        public int IndexOf(string str)
        {
            int len = this.get_Length();
            int mlen = str.Length;
            for (int i = 0; i <= len - mlen; i++)
            {
                int j = 0;
                while (this.get_Chars(i + j) == str[j]) {
                    j++;
                    if (j == mlen) return i;
                }
            }
            return -1;
        }

        public int IndexOf(char c)
        {
            int len = this.get_Length();
            for (int i = 0; i < len; i++)
            {
                if (this.get_Chars(i) == c) return i;
            }
            return -1;
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        int start = parameter1;
        struct System__String *newstr;
        CIL_newobj(System__String, SYSTEM__STRING_ctor);
        newstr = (struct System__String *)peek_pointer(0);
        if (this == 0) throw_NullReferenceException();
        if (start < 0) throw_ArgumentOutOfRangeException();
        int len = strlen(this->str);
        if (start > len) throw_ArgumentOutOfRangeException();
        newstr->str = (char*)malloc(len - start + 1);
        strncpy(newstr->str, this->str + start, len - start);
        newstr->str[len - start] = '\0';
        CIL_ret();
        ")]
        public string Substring(int start)
        { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        int start = parameter1;
        int length = parameter2;
        struct System__String *newstr;
        CIL_newobj(System__String, SYSTEM__STRING_ctor);
        newstr = (struct System__String *)peek_pointer(0);
        if (this == 0) throw_NullReferenceException();
        int origlen = strlen(this->str);
        if (start < 0) throw_ArgumentOutOfRangeException();
        if (length < 0) throw_ArgumentOutOfRangeException();
        if (start + length > origlen) throw_ArgumentOutOfRangeException();
        newstr->str = (char*)malloc(length + 1);
        strncpy(newstr->str, this->str + start, length);
        newstr->str[length] = '\0';
        CIL_ret();
        ")]
        public string Substring(int start, int length)
        { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        int i = parameter1;
        if (i < 0 || i > strlen(this->str) - 1) {
            throw_IndexOutOfRangeException();
        }
        char c = this->str[i];
        push_value32((int32_t)c, CIL_int32);
        ")]
        public char get_Chars(int i)
        { return '0'; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct System__String *this = (struct System__String*)parameter0;
        free(this->str);
        ")]
        private void __cleanup() { }

        ~__String() 
        {
            __cleanup();
        }

    }
}
