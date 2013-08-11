namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"
    map_t __CILsymboltable;
    intptr_t __CILtype;
    ")]
    class __Object
    {
        [Poly.Internals.CompilerImplemented.InlineCode(@"
        ((struct System__Object*)parameter0)->__CILsymboltable = hashmap_new();
        ", replaceCompleteImplementation: false)]
        public __Object() { }

        public virtual bool Equals(__Object other)
        {
            return this == other;
        }

        public static bool Equals(__Object objA, __Object objB)
        {
            return objA == objB;
        }

        protected virtual void Finalize() { }

        public virtual int GetHashCode() { return 0; }

        //public Type GetType() { return typeof(Object); }

        /*protected Object MemberwiseClone() { return null;  }

        public static bool ReferenceEquals(Object objA, Object objB)
        {
            return false;
        }
        */

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        const char *type = (const char*)(((struct System__Object*)parameter0)->__CILtype);
        CIL_ldstr(type);
        ")]
        public virtual string ToString() { return null; }
    }
}
