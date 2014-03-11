#pragma warning disable 0465,0114,0108

namespace System
{
    [Poly.Internals.CompilerImplemented.StructureCode(@"
    map_t __CILsymboltable;
    intptr_t __CILtype;
    intptr_t __CILbaseclasses;
    int* __CILbaseclasses_length;
    intptr_t __CILbaseinterfaces;
    int* __CILbaseinterfaces_length;
    int __CILisgeneric;
    enum CIL_Type* __CILgenerictypelist;
    int __CILgenerictypelist_length;
    ")]
    class __Object
    {
        [Poly.Internals.CompilerImplemented.InlineCode(@"
        ((struct System__Object*)parameter0)->__CILsymboltable = hashmap_new();
        ((struct System__Object*)parameter0)->__CILisgeneric = 0;
        ((struct System__Object*)parameter0)->__CILgenerictypelist_length = 0;
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

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        const char *type = (const char*)(((struct System__Object*)parameter0)->__CILtype);
        CIL_ldstr(type);
        CIL_newobj(System__Type, mCBE8D294E24BA0AFAB3C8B977360892A2BD95CC8); // System.Type::.ctor(String fullName)
        ")]
        public Type GetType() { return null; }

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
