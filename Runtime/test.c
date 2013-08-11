#include "opcodes.h"
#include "object.h"

// module D:\projects\PolyCompiler\PolyCompiler\bin\Debug\Tester.dll

// class Tester.Class1
struct Tester__Class1 {
    int32_t age; // 67108865
    int32_t s; // 67108866
    int32_t q; // 67108867
    int32_t r; // 67108868
    int32_t ssf; // 67108869
    int32_t z; // 67108870
    int64_t sdsf; // 67108871
    int64_t dbl; // 67108872
    int32_t flp; // 67108873
};
enum CIL_Type Tester__Class1_f_age__type = CIL_int32; // System.Int32
enum CIL_Type Tester__Class1_f_s__type = CIL_int32; // System.Char
enum CIL_Type Tester__Class1_f_q__type = CIL_int32; // System.SByte
enum CIL_Type Tester__Class1_f_r__type = CIL_int32; // System.Int16
enum CIL_Type Tester__Class1_f_ssf__type = CIL_int32; // System.UInt16
enum CIL_Type Tester__Class1_f_z__type = CIL_int32; // System.Int16
enum CIL_Type Tester__Class1_f_sdsf__type = CIL_int64; // System.UInt64
enum CIL_Type Tester__Class1_f_dbl__type = CIL_float64; // System.Double
enum CIL_Type Tester__Class1_f_flp__type = CIL_float32; // System.Single
/* Tester.Class1::.ctor */
void *m4F41DFF653861B07F39F2933DE78DA5776C73742(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_float32; // System.Single
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Int32
    Tester__Class1_m___ctor0000: ldarg__0();
    Tester__Class1_m___ctor0001: ldc__i4__s(9);
    Tester__Class1_m___ctor0003: stfld(Tester__Class1, age);
    Tester__Class1_m___ctor0008: ldarg__0();
    Tester__Class1_m___ctor0009: ldc__r8(10.50);
    Tester__Class1_m___ctor0018: stfld(Tester__Class1, dbl);
    Tester__Class1_m___ctor0023: ldarg__0();
    Tester__Class1_m___ctor0024: ldc__r4(10.50f);
    Tester__Class1_m___ctor0029: stfld(Tester__Class1, flp);
    Tester__Class1_m___ctor0034: ldarg__0();
    Tester__Class1_m___ctor0035: call(/*constructor*/ &m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16/* System.Object::.ctor */);
    Tester__Class1_m___ctor0040: nop();
    Tester__Class1_m___ctor0041: nop();
    Tester__Class1_m___ctor0042: ldarg__0();
    Tester__Class1_m___ctor0043: ldc__i4__s(10);
    Tester__Class1_m___ctor0045: stfld(Tester__Class1, age);
    Tester__Class1_m___ctor0050: ldc__i4__4();
    Tester__Class1_m___ctor0051: stloc__1();
    Tester__Class1_m___ctor0052: ldarg__0();
    Tester__Class1_m___ctor0053: ldfld(Tester__Class1, flp);
    Tester__Class1_m___ctor0058: ldloc__1();
    Tester__Class1_m___ctor0059: conv__r4();
    Tester__Class1_m___ctor0060: add();
    Tester__Class1_m___ctor0061: stloc__0();
    Tester__Class1_m___ctor0062: ldarg__0();
    Tester__Class1_m___ctor0063: ldloc__0();
    Tester__Class1_m___ctor0064: stfld(Tester__Class1, flp);
    Tester__Class1_m___ctor0069: ldarg__0();
    Tester__Class1_m___ctor0070: ldfld(Tester__Class1, flp);
    Tester__Class1_m___ctor0075: call(mEDF138FDB2788EDB35A1D6295E387C5BBB754328/* System.Console::WriteLine */);
    Tester__Class1_m___ctor0080: nop();
    Tester__Class1_m___ctor0081: nop();
    Tester__Class1_m___ctor0082: ret();
}
/* Tester.Class1::WhatIsMyAge */
void *m3C7DDD796A78460964716AAF2CDF85FCB2BD0820(/*0:bla<134217729>, */) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Boolean
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Int32
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Int32
    Tester__Class1_m_WhatIsMyAge0000: nop();
    Tester__Class1_m_WhatIsMyAge0001: ldc__i4__5();
    Tester__Class1_m_WhatIsMyAge0002: stloc__0();
    Tester__Class1_m_WhatIsMyAge0003: ldarg__0();
    Tester__Class1_m_WhatIsMyAge0004: ldfld(Tester__Class1, age);
    Tester__Class1_m_WhatIsMyAge0009: ldc__i4__5();
    Tester__Class1_m_WhatIsMyAge0010: add();
    Tester__Class1_m_WhatIsMyAge0011: ldc__i4__2();
    Tester__Class1_m_WhatIsMyAge0012: sub();
    Tester__Class1_m_WhatIsMyAge0013: stloc__1();
    goto Tester__Class1_m_WhatIsMyAge0016;
    Tester__Class1_m_WhatIsMyAge0016: ldloc__1();
    Tester__Class1_m_WhatIsMyAge0017: ret();
}
/* Tester.Class1::ItsMyBirthday */
void *m410957CF6F95228686CC30630D73721BC9A97A1D(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    Tester__Class1_m_ItsMyBirthday0000: nop();
    Tester__Class1_m_ItsMyBirthday0001: ldarg__0();
    Tester__Class1_m_ItsMyBirthday0002: ldarg__0();
    Tester__Class1_m_ItsMyBirthday0003: ldc__i4__0();
    Tester__Class1_m_ItsMyBirthday0004: call(/*instance*/ &m3C7DDD796A78460964716AAF2CDF85FCB2BD0820/* Tester.Class1::WhatIsMyAge */);
    Tester__Class1_m_ItsMyBirthday0009: ldc__i4__1();
    Tester__Class1_m_ItsMyBirthday0010: add();
    Tester__Class1_m_ItsMyBirthday0011: stfld(Tester__Class1, age);
    Tester__Class1_m_ItsMyBirthday0016: ret();
}
/* Tester.Class1::SetMyAge */
void *m8A6F962A306F4521C3E7BBEFBD04336CD7CE861B(/*0:newAge<134217730>, */) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Int32
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    Tester__Class1_m_SetMyAge0000: nop();
    Tester__Class1_m_SetMyAge0001: ldarg__0();
    Tester__Class1_m_SetMyAge0002: ldarg__1();
    Tester__Class1_m_SetMyAge0003: stfld(Tester__Class1, age);
    Tester__Class1_m_SetMyAge0008: ret();
}
// class Tester.Class2
struct Tester__Class2 {
    int32_t i; // 67108874
};
enum CIL_Type Tester__Class2_f_i__type = CIL_int32; // System.Int32
/* Tester.Class2::.ctor */
void *mBA6B977B579893F83B02CD67A53179C2F8BD84E8(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    Tester__Class2_m___ctor0000: ldarg__0();
    Tester__Class2_m___ctor0001: call(/*constructor*/ &m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16/* System.Object::.ctor */);
    Tester__Class2_m___ctor0006: ret();
}
/* Tester.Class2::Main */
void *mC4FCE3879EE362488AFBAD3F6AD6344A279C76F8(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // Tester.Class1
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Int32
    Tester__Class2_m_Main0000: nop();
    Tester__Class2_m_Main0001: newobj(Tester__Class1, m4F41DFF653861B07F39F2933DE78DA5776C73742/* Tester.Class1::.ctor */);
    Tester__Class2_m_Main0006: stloc__0();
    Tester__Class2_m_Main0007: ldloc__0();
    Tester__Class2_m_Main0008: ldc__i4__s(33);
    Tester__Class2_m_Main0010: callvirt(/*instance*/ &m8A6F962A306F4521C3E7BBEFBD04336CD7CE861B/* Tester.Class1::SetMyAge */);
    Tester__Class2_m_Main0015: nop();
    Tester__Class2_m_Main0016: ldloc__0();
    Tester__Class2_m_Main0017: ldc__i4__1();
    Tester__Class2_m_Main0018: callvirt(/*instance*/ &m3C7DDD796A78460964716AAF2CDF85FCB2BD0820/* Tester.Class1::WhatIsMyAge */);
    Tester__Class2_m_Main0023: stloc__1();
    Tester__Class2_m_Main0024: ldloc__1();
    Tester__Class2_m_Main0025: call(m7066EF1436C6E50530DE29D56356D6747108D4DB/* System.Console::WriteLine */);
    Tester__Class2_m_Main0030: nop();
    Tester__Class2_m_Main0031: ret();
}
