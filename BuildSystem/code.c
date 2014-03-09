#include "header.h"

// Imports
#include "mscorlib.h"
#include "Poly.Internals.h"
// module C:\Users\Bas\Documents\GitHub\poly\BCL\mscorlib\bin\Debug\mscorlib.dll

int System__Object__baseclasses_length = 0;
char* System__Object__baseclasses[1] = { "" };
int System__Attribute__baseclasses_length = 1;
char* System__Attribute__baseclasses[1] = {
    "System.Object"
};
int System__Runtime__CompilerServices__RuntimeHelpers__baseclasses_length = 1;
char* System__Runtime__CompilerServices__RuntimeHelpers__baseclasses[1] = {
    "System.Object"
};
int mscorlib__System__RuntimeFieldHandle__baseclasses_length = 1;
char* mscorlib__System__RuntimeFieldHandle__baseclasses[1] = {
    "System.Object"
};
int System__Exception__baseclasses_length = 1;
char* System__Exception__baseclasses[1] = {
    "System.Object"
};
enum CIL_Type System__Exception_f__Message_k__BackingField__type = CIL_pointer; // System.String
enum CIL_Type System__Exception_f__HelpLink_k__BackingField__type = CIL_pointer; // System.String
enum CIL_Type System__Exception_f__HResult_k__BackingField__type = CIL_int32; // System.Int32
enum CIL_Type System__Exception_f__InnerException_k__BackingField__type = CIL_pointer; // System.Exception
enum CIL_Type System__Exception_f__Source_k__BackingField__type = CIL_pointer; // System.String
enum CIL_Type System__Exception_f__StackTrace_k__BackingField__type = CIL_pointer; // System.String
int System__Console__baseclasses_length = 1;
char* System__Console__baseclasses[1] = {
    "System.Object"
};
int System__ValueType__baseclasses_length = 1;
char* System__ValueType__baseclasses[1] = {
    "System.Object"
};
int System__Int32__baseclasses_length = 2;
char* System__Int32__baseclasses[2] = {
    "System.ValueType", 
    "System.Object"
};
int System__ArgumentOutOfRangeException__baseclasses_length = 2;
char* System__ArgumentOutOfRangeException__baseclasses[2] = {
    "System.Exception", 
    "System.Object"
};
int System__IndexOutOfRangeException__baseclasses_length = 2;
char* System__IndexOutOfRangeException__baseclasses[2] = {
    "System.Exception", 
    "System.Object"
};
int System__InvalidCastException__baseclasses_length = 2;
char* System__InvalidCastException__baseclasses[2] = {
    "System.Exception", 
    "System.Object"
};
int System__NullReferenceException__baseclasses_length = 2;
char* System__NullReferenceException__baseclasses[2] = {
    "System.Exception", 
    "System.Object"
};
int System__NotImplementedException__baseclasses_length = 2;
char* System__NotImplementedException__baseclasses[2] = {
    "System.Exception", 
    "System.Object"
};
int System__Environment_plus_StackFrame__baseclasses_length = 1;
char* System__Environment_plus_StackFrame__baseclasses[1] = {
    "System.Object"
};
enum CIL_Type System__Environment_plus_StackFrame_f_MethodSignature__type = CIL_pointer; // System.String
enum CIL_Type System__Environment_plus_StackFrame_f_FileName__type = CIL_pointer; // System.String
enum CIL_Type System__Environment_plus_StackFrame_f_LineNumber__type = CIL_int32; // System.Int32
int System__Environment__baseclasses_length = 1;
char* System__Environment__baseclasses[1] = {
    "System.Object"
};
int System__String__baseclasses_length = 1;
char* System__String__baseclasses[1] = {
    "System.Object"
};
int System__Type__baseclasses_length = 1;
char* System__Type__baseclasses[1] = {
    "System.Object"
};
enum CIL_Type System__Type_f__FullName_k__BackingField__type = CIL_pointer; // System.String
// class System.__Object
/* System.Object::.ctor */
char* m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16_sig = "System.Object::.ctor()";
void *m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        ((struct System__Object*)parameter0)->__CILsymboltable = hashmap_new();
        }
    /* END INLINE CODE */
    System__Object_m___ctor0000: CIL_ldarg__0();
    pop_pointer();
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Object";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Object__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Object__baseclasses_length;
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m75B859EF0005863D5158396CB89114C5BF752DA3", &mF028F029FE2B7E6C5FC6B76272F2F98668C649C8); /* Equals */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m45CBA2DC20411DD9EC01754632B97E0F780E4D29", &m72555D2152F856160EF44D93DC781F86F5767954); /* Finalize */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m9B47C032938820269CE9D24A72B299C9D2A50C6C", &m8958E27C1CE11706E956EA94762D23FD80EB2F8F); /* GetHashCode */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", &m8E6836504E6F32F58A5D7822EDF304BB4064BF64); /* ToString */
    System__Object_m___ctor0006: CIL_nop();
    System__Object_m___ctor0007: CIL_nop();
    System__Object_m___ctor0008: CIL_nop();
    System__Object_m___ctor0009: CIL_ret();
    CIL_ret();
}
/* System.Object::Equals */
char* mF028F029FE2B7E6C5FC6B76272F2F98668C649C8_sig = "System.Object::Equals(__Object other)";
void *mF028F029FE2B7E6C5FC6B76272F2F98668C649C8(/*__Object other*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.__Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Boolean
    System__Object_m_Equals0000: CIL_nop();
    System__Object_m_Equals0001: CIL_ldarg__0();
    System__Object_m_Equals0002: CIL_ldarg__1();
    System__Object_m_Equals0004: CIL_ceq();
    System__Object_m_Equals0005: CIL_stloc__0();
    System__Object_m_Equals0006: goto System__Object_m_Equals0008;
    System__Object_m_Equals0008: CIL_ldloc__0();
    System__Object_m_Equals0009: CIL_ret();
    CIL_ret();
}
/* System.Object::Equals */
char* m27E26B2717630AA6745AA503DE9E1C9F9FC40636_sig = "System.Object::Equals(__Object objA, __Object objB)";
void *m27E26B2717630AA6745AA503DE9E1C9F9FC40636(/*__Object objA, __Object objB*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.__Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.__Object
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Boolean
    System__Object_m_Equals0000: CIL_nop();
    System__Object_m_Equals0001: CIL_ldarg__0();
    System__Object_m_Equals0002: CIL_ldarg__1();
    System__Object_m_Equals0004: CIL_ceq();
    System__Object_m_Equals0005: CIL_stloc__0();
    System__Object_m_Equals0006: goto System__Object_m_Equals0008;
    System__Object_m_Equals0008: CIL_ldloc__0();
    System__Object_m_Equals0009: CIL_ret();
    CIL_ret();
}
/* System.Object::Finalize */
char* m72555D2152F856160EF44D93DC781F86F5767954_sig = "System.Object::Finalize()";
void *m72555D2152F856160EF44D93DC781F86F5767954(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Object_m_Finalize0000: CIL_nop();
    System__Object_m_Finalize0001: CIL_ret();
    CIL_ret();
}
/* System.Object::GetHashCode */
char* m8958E27C1CE11706E956EA94762D23FD80EB2F8F_sig = "System.Object::GetHashCode()";
void *m8958E27C1CE11706E956EA94762D23FD80EB2F8F(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Int32
    System__Object_m_GetHashCode0000: CIL_nop();
    System__Object_m_GetHashCode0001: CIL_ldc__i4__0();
    System__Object_m_GetHashCode0002: CIL_stloc__0();
    System__Object_m_GetHashCode0003: goto System__Object_m_GetHashCode0005;
    System__Object_m_GetHashCode0005: CIL_ldloc__0();
    System__Object_m_GetHashCode0006: CIL_ret();
    CIL_ret();
}
/* System.Object::GetType */
char* m3AD7669D6B5B2D33720E022E66E577E003E2D15A_sig = "System.Object::GetType()";
void *m3AD7669D6B5B2D33720E022E66E577E003E2D15A(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        const char *type = (const char*)(((struct System__Object*)parameter0)->__CILtype);
        CIL_ldstr(type);
        CIL_newobj(System__Type, mCBE8D294E24BA0AFAB3C8B977360892A2BD95CC8); // System.Type::.ctor(String fullName)
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Object::ToString */
char* m8E6836504E6F32F58A5D7822EDF304BB4064BF64_sig = "System.Object::ToString()";
void *m8E6836504E6F32F58A5D7822EDF304BB4064BF64(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        const char *type = (const char*)(((struct System__Object*)parameter0)->__CILtype);
        CIL_ldstr(type);
        }
    /* END INLINE CODE */
    CIL_ret();
}
// class System.Attribute
/* System.Attribute::.ctor */
char* m457400C5C2A033444F6FEAAFAA62CCD633E19724_sig = "System.Attribute::.ctor()";
void *m457400C5C2A033444F6FEAAFAA62CCD633E19724(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Attribute_m___ctor0000: CIL_ldarg__0();
    System__Attribute_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Attribute";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Attribute__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Attribute__baseclasses_length;
    System__Attribute_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.Runtime.CompilerServices.RuntimeHelpers
/* System.Runtime.CompilerServices.RuntimeHelpers::.ctor */
char* mF7A8F0703658A1A7FF6559D6A1EC428B5660F7A1_sig = "System.Runtime.CompilerServices.RuntimeHelpers::.ctor()";
void *mF7A8F0703658A1A7FF6559D6A1EC428B5660F7A1(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Runtime__CompilerServices__RuntimeHelpers_m___ctor0000: CIL_ldarg__0();
    System__Runtime__CompilerServices__RuntimeHelpers_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Runtime.CompilerServices.RuntimeHelpers";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Runtime__CompilerServices__RuntimeHelpers__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Runtime__CompilerServices__RuntimeHelpers__baseclasses_length;
    System__Runtime__CompilerServices__RuntimeHelpers_m___ctor0006: CIL_ret();
    CIL_ret();
}
/* System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray */
char* mF717B9F9FA5F28945A1EBE020D1524839FD1CEA7_sig = "System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray(Array array, RuntimeFieldHandle fldHandle)";
void *mF717B9F9FA5F28945A1EBE020D1524839FD1CEA7(/*Array array, RuntimeFieldHandle fldHandle*/) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_pointer; // System.RuntimeFieldHandle
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.Array
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
			struct SYSTEM__RUNTIMEFIELDHANDLE_proto *fldHandle = (struct SYSTEM__RUNTIMEFIELDHANDLE_proto *)parameter1;
			int8_t *data = (int8_t *)fldHandle->addr;
			int8_t *arr = (int8_t *)parameter0;
			int arr_length = ((int32_t*)arr)[0];
			int arr_elemsize = ((int32_t*)arr)[1];
			int arr_offset = 8;
			int i = 0;
			for (; i < arr_length * arr_elemsize; i++) { arr[i + arr_offset] = data[i]; }

		}
    /* END INLINE CODE */
    CIL_ret();
}
// class mscorlib.System.RuntimeFieldHandle
/* mscorlib.System.RuntimeFieldHandle::.ctor */
char* m7531E3B8253211639BBBDB1FFB6E188D5A984775_sig = "mscorlib.System.RuntimeFieldHandle::.ctor()";
void *m7531E3B8253211639BBBDB1FFB6E188D5A984775(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    mscorlib__System__RuntimeFieldHandle_m___ctor0000: CIL_ldarg__0();
    mscorlib__System__RuntimeFieldHandle_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"mscorlib.System.RuntimeFieldHandle";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&mscorlib__System__RuntimeFieldHandle__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &mscorlib__System__RuntimeFieldHandle__baseclasses_length;
    mscorlib__System__RuntimeFieldHandle_m___ctor0006: CIL_nop();
    mscorlib__System__RuntimeFieldHandle_m___ctor0007: CIL_nop();
    mscorlib__System__RuntimeFieldHandle_m___ctor0008: CIL_nop();
    mscorlib__System__RuntimeFieldHandle_m___ctor0009: CIL_ret();
    CIL_ret();
}
// class System.__Exception
/* System.Exception::.ctor */
char* mA204A1B81C060A79721F77F23E5FF39E07CC4694_sig = "System.Exception::.ctor()";
void *mA204A1B81C060A79721F77F23E5FF39E07CC4694(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m___ctor0000: CIL_ldarg__0();
    System__Exception_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Exception";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Exception__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Exception__baseclasses_length;
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m4837D4331097DD46CFF401733F414EC14527084B", &mD525625A51E554AA031B4066D3CC34122AD29034); /* get_StackTrace */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", &mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218); /* ToString */
    ((struct System__Exception*)parameter0)->_Message_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_HelpLink_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_HResult_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_InnerException_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_Source_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_StackTrace_k__BackingField = 0;
    System__Exception_m___ctor0006: CIL_nop();
    System__Exception_m___ctor0007: CIL_nop();
    System__Exception_m___ctor0008: CIL_ldarg__0();
    System__Exception_m___ctor0009: CIL_ldstr("(unknown)");
    System__Exception_m___ctor0014: CIL_call(/*instance*/ m77F43EF82837B4FC5B60CC75673D3417EB42A884, "mC40E67F315C5D5BEF5E7C147AE08D120FD65C0C8", 1, 0/* System.Void System.__Exception::set_StackTrace(System.String, ) */);
    System__Exception_m___ctor0019: CIL_nop();
    System__Exception_m___ctor0020: CIL_nop();
    System__Exception_m___ctor0021: CIL_ret();
    CIL_ret();
}
/* System.Exception::.ctor */
char* m58A475D0E06559A6B627989B541434CB08FDE401_sig = "System.Exception::.ctor(String message)";
void *m58A475D0E06559A6B627989B541434CB08FDE401(/*String message*/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m___ctor0000: CIL_ldarg__0();
    System__Exception_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Exception";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Exception__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Exception__baseclasses_length;
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m4837D4331097DD46CFF401733F414EC14527084B", &mD525625A51E554AA031B4066D3CC34122AD29034); /* get_StackTrace */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", &mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218); /* ToString */
    ((struct System__Exception*)parameter0)->_Message_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_HelpLink_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_HResult_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_InnerException_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_Source_k__BackingField = 0;
    ((struct System__Exception*)parameter0)->_StackTrace_k__BackingField = 0;
    System__Exception_m___ctor0006: CIL_nop();
    System__Exception_m___ctor0007: CIL_nop();
    System__Exception_m___ctor0008: CIL_ldarg__0();
    System__Exception_m___ctor0009: CIL_ldstr("(unknown)");
    System__Exception_m___ctor0014: CIL_call(/*instance*/ m77F43EF82837B4FC5B60CC75673D3417EB42A884, "mC40E67F315C5D5BEF5E7C147AE08D120FD65C0C8", 1, 0/* System.Void System.__Exception::set_StackTrace(System.String, ) */);
    System__Exception_m___ctor0019: CIL_nop();
    System__Exception_m___ctor0020: CIL_ldarg__0();
    System__Exception_m___ctor0021: CIL_ldarg__1();
    System__Exception_m___ctor0022: CIL_call(/*instance*/ m662483F326D57E806173A0B8FCD9E10806774771, "m6495D364CE419A6959F4E8054CB23CE0BB20F822", 1, 0/* System.Void System.__Exception::set_Message(System.String, ) */);
    System__Exception_m___ctor0027: CIL_nop();
    System__Exception_m___ctor0028: CIL_nop();
    System__Exception_m___ctor0029: CIL_ret();
    CIL_ret();
}
/* System.Exception::get_Message */
char* mDD5CE437ABC324313102D010746370FB55969A90_sig = "System.Exception::get_Message()";
void *mDD5CE437ABC324313102D010746370FB55969A90(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Exception_m_get_Message0000: CIL_ldarg__0();
    System__Exception_m_get_Message0001: CIL_ldfld(System__Exception, _Message_k__BackingField);
    System__Exception_m_get_Message0006: CIL_stloc__0();
    System__Exception_m_get_Message0007: goto System__Exception_m_get_Message0009;
    System__Exception_m_get_Message0009: CIL_ldloc__0();
    System__Exception_m_get_Message0010: CIL_ret();
    CIL_ret();
}
/* System.Exception::set_Message */
char* m662483F326D57E806173A0B8FCD9E10806774771_sig = "System.Exception::set_Message(String value)";
void *m662483F326D57E806173A0B8FCD9E10806774771(/*String value*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m_set_Message0000: CIL_ldarg__0();
    System__Exception_m_set_Message0001: CIL_ldarg__1();
    System__Exception_m_set_Message0002: CIL_stfld(System__Exception, _Message_k__BackingField);
    System__Exception_m_set_Message0007: CIL_ret();
    CIL_ret();
}
/* System.Exception::get_HelpLink */
char* mC68F08BE35DE057468F1E4DC2E7DAD594708A9EA_sig = "System.Exception::get_HelpLink()";
void *mC68F08BE35DE057468F1E4DC2E7DAD594708A9EA(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Exception_m_get_HelpLink0000: CIL_ldarg__0();
    System__Exception_m_get_HelpLink0001: CIL_ldfld(System__Exception, _HelpLink_k__BackingField);
    System__Exception_m_get_HelpLink0006: CIL_stloc__0();
    System__Exception_m_get_HelpLink0007: goto System__Exception_m_get_HelpLink0009;
    System__Exception_m_get_HelpLink0009: CIL_ldloc__0();
    System__Exception_m_get_HelpLink0010: CIL_ret();
    CIL_ret();
}
/* System.Exception::set_HelpLink */
char* m650102E40BCCFFF3B2463C77BFC562FFCBB9CD3A_sig = "System.Exception::set_HelpLink(String value)";
void *m650102E40BCCFFF3B2463C77BFC562FFCBB9CD3A(/*String value*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m_set_HelpLink0000: CIL_ldarg__0();
    System__Exception_m_set_HelpLink0001: CIL_ldarg__1();
    System__Exception_m_set_HelpLink0002: CIL_stfld(System__Exception, _HelpLink_k__BackingField);
    System__Exception_m_set_HelpLink0007: CIL_ret();
    CIL_ret();
}
/* System.Exception::get_HResult */
char* mAAF13984F5105EAB0DE2D7CCEB9F7697F2FE67DD_sig = "System.Exception::get_HResult()";
void *mAAF13984F5105EAB0DE2D7CCEB9F7697F2FE67DD(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Int32
    System__Exception_m_get_HResult0000: CIL_ldarg__0();
    System__Exception_m_get_HResult0001: CIL_ldfld(System__Exception, _HResult_k__BackingField);
    System__Exception_m_get_HResult0006: CIL_stloc__0();
    System__Exception_m_get_HResult0007: goto System__Exception_m_get_HResult0009;
    System__Exception_m_get_HResult0009: CIL_ldloc__0();
    System__Exception_m_get_HResult0010: CIL_ret();
    CIL_ret();
}
/* System.Exception::set_HResult */
char* mFBE07AB8CABDC02BD80CEF1F1D663245FCEA87C7_sig = "System.Exception::set_HResult(Int32 value)";
void *mFBE07AB8CABDC02BD80CEF1F1D663245FCEA87C7(/*Int32 value*/) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Int32
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m_set_HResult0000: CIL_ldarg__0();
    System__Exception_m_set_HResult0001: CIL_ldarg__1();
    System__Exception_m_set_HResult0002: CIL_stfld(System__Exception, _HResult_k__BackingField);
    System__Exception_m_set_HResult0007: CIL_ret();
    CIL_ret();
}
/* System.Exception::get_InnerException */
char* m0B0A2C3A12F31A31801DB84E7D58F97D9B4B96B2_sig = "System.Exception::get_InnerException()";
void *m0B0A2C3A12F31A31801DB84E7D58F97D9B4B96B2(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.Exception
    System__Exception_m_get_InnerException0000: CIL_ldarg__0();
    System__Exception_m_get_InnerException0001: CIL_ldfld(System__Exception, _InnerException_k__BackingField);
    System__Exception_m_get_InnerException0006: CIL_stloc__0();
    System__Exception_m_get_InnerException0007: goto System__Exception_m_get_InnerException0009;
    System__Exception_m_get_InnerException0009: CIL_ldloc__0();
    System__Exception_m_get_InnerException0010: CIL_ret();
    CIL_ret();
}
/* System.Exception::set_InnerException */
char* m6AEE9E8EC7D23748CA053FB1C9190150EE840A44_sig = "System.Exception::set_InnerException(Exception value)";
void *m6AEE9E8EC7D23748CA053FB1C9190150EE840A44(/*Exception value*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Exception
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m_set_InnerException0000: CIL_ldarg__0();
    System__Exception_m_set_InnerException0001: CIL_ldarg__1();
    System__Exception_m_set_InnerException0002: CIL_stfld(System__Exception, _InnerException_k__BackingField);
    System__Exception_m_set_InnerException0007: CIL_ret();
    CIL_ret();
}
/* System.Exception::get_Source */
char* mA8467B0EF1F0ED7D48D7698A32C9BB1A6A4B238C_sig = "System.Exception::get_Source()";
void *mA8467B0EF1F0ED7D48D7698A32C9BB1A6A4B238C(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Exception_m_get_Source0000: CIL_ldarg__0();
    System__Exception_m_get_Source0001: CIL_ldfld(System__Exception, _Source_k__BackingField);
    System__Exception_m_get_Source0006: CIL_stloc__0();
    System__Exception_m_get_Source0007: goto System__Exception_m_get_Source0009;
    System__Exception_m_get_Source0009: CIL_ldloc__0();
    System__Exception_m_get_Source0010: CIL_ret();
    CIL_ret();
}
/* System.Exception::set_Source */
char* mD76AF19773C892624C3A7D71AA978FF555BCDC97_sig = "System.Exception::set_Source(String value)";
void *mD76AF19773C892624C3A7D71AA978FF555BCDC97(/*String value*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m_set_Source0000: CIL_ldarg__0();
    System__Exception_m_set_Source0001: CIL_ldarg__1();
    System__Exception_m_set_Source0002: CIL_stfld(System__Exception, _Source_k__BackingField);
    System__Exception_m_set_Source0007: CIL_ret();
    CIL_ret();
}
/* System.Exception::get_StackTrace */
char* mD525625A51E554AA031B4066D3CC34122AD29034_sig = "System.Exception::get_StackTrace()";
void *mD525625A51E554AA031B4066D3CC34122AD29034(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Exception_m_get_StackTrace0000: CIL_ldarg__0();
    System__Exception_m_get_StackTrace0001: CIL_ldfld(System__Exception, _StackTrace_k__BackingField);
    System__Exception_m_get_StackTrace0006: CIL_stloc__0();
    System__Exception_m_get_StackTrace0007: goto System__Exception_m_get_StackTrace0009;
    System__Exception_m_get_StackTrace0009: CIL_ldloc__0();
    System__Exception_m_get_StackTrace0010: CIL_ret();
    CIL_ret();
}
/* System.Exception::set_StackTrace */
char* m77F43EF82837B4FC5B60CC75673D3417EB42A884_sig = "System.Exception::set_StackTrace(String value)";
void *m77F43EF82837B4FC5B60CC75673D3417EB42A884(/*String value*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Exception_m_set_StackTrace0000: CIL_ldarg__0();
    System__Exception_m_set_StackTrace0001: CIL_ldarg__1();
    System__Exception_m_set_StackTrace0002: CIL_stfld(System__Exception, _StackTrace_k__BackingField);
    System__Exception_m_set_StackTrace0007: CIL_ret();
    CIL_ret();
}
/* System.Exception::ToString */
char* mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218_sig = "System.Exception::ToString()";
void *mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Exception_m_ToString0000: CIL_nop();
    System__Exception_m_ToString0001: CIL_ldarg__0();
    System__Exception_m_ToString0002: CIL_call(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__Exception_m_ToString0007: CIL_ldstr("\n");
    System__Exception_m_ToString0012: CIL_ldarg__0();
    System__Exception_m_ToString0013: CIL_callvirt(/*instance*/ mD525625A51E554AA031B4066D3CC34122AD29034, "m4837D4331097DD46CFF401733F414EC14527084B", 0, 1/* System.String System.__Exception::get_StackTrace() */);
    System__Exception_m_ToString0018: CIL_call(mEBFE3FA5AAAF9A5D7F5D49848C36C3DDC4F6E1B4, "m0275F44A18CC87BBD5D96945118D5038C7315652", 3, 0/* System.String System.String::Concat(System.String, System.String, System.String, ) */);
    System__Exception_m_ToString0023: CIL_stloc__0();
    System__Exception_m_ToString0024: goto System__Exception_m_ToString0026;
    System__Exception_m_ToString0026: CIL_ldloc__0();
    System__Exception_m_ToString0027: CIL_ret();
    CIL_ret();
}
/* System.Exception::InitStackTrace */
char* m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394_sig = "System.Exception::InitStackTrace()";
void *m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Exception_m_InitStackTrace0000: CIL_nop();
    System__Exception_m_InitStackTrace0001: CIL_call(m71CD3EBF055D1B6753790AA34B603EC59C86F9FC, "m4837D4331097DD46CFF401733F414EC14527084B", 0, 0/* System.String System.Environment::get_StackTrace() */);
    System__Exception_m_InitStackTrace0006: CIL_stloc__0();
    System__Exception_m_InitStackTrace0007: CIL_ldarg__0();
    System__Exception_m_InitStackTrace0008: CIL_ldloc__0();
    System__Exception_m_InitStackTrace0009: CIL_ldloc__0();
    System__Exception_m_InitStackTrace0010: CIL_ldstr("\n");
    System__Exception_m_InitStackTrace0015: CIL_callvirt(/*instance*/ m9080C0A7B04E806CF0B2B4731605A21E78F85C82, "m45BEDBC5A08E6ED9C033830DB4D76F52AAF08119", 1, 0/* System.Int32 System.String::IndexOf(System.String, ) */);
    System__Exception_m_InitStackTrace0020: CIL_ldc__i4__1();
    System__Exception_m_InitStackTrace0021: CIL_add();
    System__Exception_m_InitStackTrace0022: CIL_callvirt(/*instance*/ m35DD150503CB22A5AC8E05A5A6785912945CF6D8, "mC5B5C9656E0D84D23687BC1FDCDB73FD96CC4487", 1, 0/* System.String System.String::Substring(System.Int32, ) */);
    System__Exception_m_InitStackTrace0027: CIL_call(/*instance*/ m77F43EF82837B4FC5B60CC75673D3417EB42A884, "mC40E67F315C5D5BEF5E7C147AE08D120FD65C0C8", 1, 0/* System.Void System.__Exception::set_StackTrace(System.String, ) */);
    System__Exception_m_InitStackTrace0032: CIL_nop();
    System__Exception_m_InitStackTrace0033: CIL_ret();
    CIL_ret();
}
// class System.Console
/* System.Console::.ctor */
char* m9114210D44965BA5EEF18C24C0D9239D4BA05A49_sig = "System.Console::.ctor()";
void *m9114210D44965BA5EEF18C24C0D9239D4BA05A49(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Console_m___ctor0000: CIL_ldarg__0();
    System__Console_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Console";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Console__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Console__baseclasses_length;
    System__Console_m___ctor0006: CIL_ret();
    CIL_ret();
}
/* System.Console::WriteLine */
char* m7B0E65808D2625E9D12D0A5E20CEBAAF2B17DF13_sig = "System.Console::WriteLine(Char value)";
void *m7B0E65808D2625E9D12D0A5E20CEBAAF2B17DF13(/*Char value*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Char
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            printf("%c\n", parameter0);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* m7066EF1436C6E50530DE29D56356D6747108D4DB_sig = "System.Console::WriteLine(Int32 value)";
void *m7066EF1436C6E50530DE29D56356D6747108D4DB(/*Int32 value*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Int32
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            printf("%i\n", parameter0);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* mC813F1CF7B4486925218A3E432C87B902EEDCE78_sig = "System.Console::WriteLine(Int64 value)";
void *mC813F1CF7B4486925218A3E432C87B902EEDCE78(/*Int64 value*/) {
    int64_t parameter0 = pop_value64();
    enum CIL_Type parameter0__type = CIL_int64; // System.Int64
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            printf("%ld\n", parameter0);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* m14A3A560DE8F1AAF097AA8EE0B050C8E7A351957_sig = "System.Console::WriteLine(Byte value)";
void *m14A3A560DE8F1AAF097AA8EE0B050C8E7A351957(/*Byte value*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Byte
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            printf("%i\n", parameter0);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* mEDF138FDB2788EDB35A1D6295E387C5BBB754328_sig = "System.Console::WriteLine(Single value)";
void *mEDF138FDB2788EDB35A1D6295E387C5BBB754328(/*Single value*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_float32; // System.Single
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            float f;
            memcpy(&f, &parameter0, 4);
            printf("%f\n", f);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* m81A1558C8061A0DD195011465F8CB730FF4A5435_sig = "System.Console::WriteLine(Double value)";
void *m81A1558C8061A0DD195011465F8CB730FF4A5435(/*Double value*/) {
    int64_t parameter0 = pop_value64();
    enum CIL_Type parameter0__type = CIL_float64; // System.Double
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            double f;
            memcpy(&f, &parameter0, 8);
            printf("%f\n", f);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* mFC01BFC69714BA2C4F851536872188F62958745F_sig = "System.Console::WriteLine(String value)";
void *mFC01BFC69714BA2C4F851536872188F62958745F(/*String value*/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
            char *str = CIL_getCStringFromSystemString(parameter0);
            printf("%s\n", str);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Console::WriteLine */
char* m089DC9679DF2FA6D9AC17ADC5052F3AF64480A5C_sig = "System.Console::WriteLine(Object value)";
void *m089DC9679DF2FA6D9AC17ADC5052F3AF64480A5C(/*Object value*/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.Object
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Console_m_WriteLine0000: CIL_nop();
    System__Console_m_WriteLine0001: CIL_ldarg__0();
    System__Console_m_WriteLine0002: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__Console_m_WriteLine0007: CIL_call(mFC01BFC69714BA2C4F851536872188F62958745F, "mE87D2D9A8E3434EF942B5DE5040E69ACE80B9427", 1, 0/* System.Void System.Console::WriteLine(System.String, ) */);
    System__Console_m_WriteLine0012: CIL_nop();
    System__Console_m_WriteLine0013: CIL_ret();
    CIL_ret();
}
// class System.__ValueType
/* System.ValueType::.ctor */
char* mEDC8295D0100B7A05696604AA16180D59191E3E6_sig = "System.ValueType::.ctor()";
void *mEDC8295D0100B7A05696604AA16180D59191E3E6(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__ValueType_m___ctor0000: CIL_ldarg__0();
    System__ValueType_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.ValueType";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__ValueType__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__ValueType__baseclasses_length;
    System__ValueType_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.__Int32
/* System.Int32::.ctor */
char* mB8A04E0EDA8614F527912F78289CD1FF9D0A0F81_sig = "System.Int32::.ctor()";
void *mB8A04E0EDA8614F527912F78289CD1FF9D0A0F81(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Int32_m___ctor0000: CIL_ldarg__0();
    System__Int32_m___ctor0001: CIL_call(/*constructor*/ mEDC8295D0100B7A05696604AA16180D59191E3E6, "NONE", 0, 0 /* System.__ValueType::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Int32";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Int32__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Int32__baseclasses_length;
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", &mD87E91119D536242CFBFE243F48FA984876D5163); /* ToString */
    System__Int32_m___ctor0006: CIL_nop();
    System__Int32_m___ctor0007: CIL_nop();
    System__Int32_m___ctor0008: CIL_nop();
    System__Int32_m___ctor0009: CIL_ret();
    CIL_ret();
}
/* System.Int32::ToString */
char* mD87E91119D536242CFBFE243F48FA984876D5163_sig = "System.Int32::ToString()";
void *mD87E91119D536242CFBFE243F48FA984876D5163(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        char buffer[12];
        struct System__Int32 *this = (struct System__Int32*)parameter0;
        itoa(this->value, buffer, 10);
        CIL_ldstr(buffer);
        }
    /* END INLINE CODE */
    CIL_ret();
}
// class System.__ArgumentOutOfRangeException
/* System.ArgumentOutOfRangeException::.ctor */
char* mD81A01BD2EAF4E0554E7E00022DA8393DA63979F_sig = "System.ArgumentOutOfRangeException::.ctor()";
void *mD81A01BD2EAF4E0554E7E00022DA8393DA63979F(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__ArgumentOutOfRangeException_m___ctor0000: CIL_ldarg__0();
    System__ArgumentOutOfRangeException_m___ctor0001: CIL_call(/*constructor*/ mA204A1B81C060A79721F77F23E5FF39E07CC4694, "NONE", 0, 0 /* System.__Exception::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.ArgumentOutOfRangeException";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__ArgumentOutOfRangeException__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__ArgumentOutOfRangeException__baseclasses_length;
    System__ArgumentOutOfRangeException_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.__IndexOutOfRangeException
/* System.IndexOutOfRangeException::.ctor */
char* m3C46C87472BC1C0212B9B21367868D11FCC940BB_sig = "System.IndexOutOfRangeException::.ctor()";
void *m3C46C87472BC1C0212B9B21367868D11FCC940BB(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__IndexOutOfRangeException_m___ctor0000: CIL_ldarg__0();
    System__IndexOutOfRangeException_m___ctor0001: CIL_call(/*constructor*/ mA204A1B81C060A79721F77F23E5FF39E07CC4694, "NONE", 0, 0 /* System.__Exception::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.IndexOutOfRangeException";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__IndexOutOfRangeException__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__IndexOutOfRangeException__baseclasses_length;
    System__IndexOutOfRangeException_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.__InvalidCastException
/* System.InvalidCastException::.ctor */
char* mB71A0D21D024AF44637A268806CE99358D389355_sig = "System.InvalidCastException::.ctor()";
void *mB71A0D21D024AF44637A268806CE99358D389355(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__InvalidCastException_m___ctor0000: CIL_ldarg__0();
    System__InvalidCastException_m___ctor0001: CIL_call(/*constructor*/ mA204A1B81C060A79721F77F23E5FF39E07CC4694, "NONE", 0, 0 /* System.__Exception::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.InvalidCastException";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__InvalidCastException__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__InvalidCastException__baseclasses_length;
    System__InvalidCastException_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.__NullReferenceException
/* System.NullReferenceException::.ctor */
char* m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C_sig = "System.NullReferenceException::.ctor()";
void *m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__NullReferenceException_m___ctor0000: CIL_ldarg__0();
    System__NullReferenceException_m___ctor0001: CIL_call(/*constructor*/ mA204A1B81C060A79721F77F23E5FF39E07CC4694, "NONE", 0, 0 /* System.__Exception::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.NullReferenceException";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__NullReferenceException__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__NullReferenceException__baseclasses_length;
    System__NullReferenceException_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.__NotImplementedException
/* System.NotImplementedException::.ctor */
char* mC78D8B7453D07999B003823809C964A5709EC8C6_sig = "System.NotImplementedException::.ctor()";
void *mC78D8B7453D07999B003823809C964A5709EC8C6(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__NotImplementedException_m___ctor0000: CIL_ldarg__0();
    System__NotImplementedException_m___ctor0001: CIL_call(/*constructor*/ mA204A1B81C060A79721F77F23E5FF39E07CC4694, "NONE", 0, 0 /* System.__Exception::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.NotImplementedException";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__NotImplementedException__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__NotImplementedException__baseclasses_length;
    System__NotImplementedException_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.Environment+StackFrame
/* System.Environment+StackFrame::.ctor */
char* mB60C279DD2E6FD1E17763B0A68D79B5B2154E850_sig = "System.Environment+StackFrame::.ctor()";
void *mB60C279DD2E6FD1E17763B0A68D79B5B2154E850(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Environment_plus_StackFrame_m___ctor0000: CIL_ldarg__0();
    System__Environment_plus_StackFrame_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Environment+StackFrame";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Environment_plus_StackFrame__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Environment_plus_StackFrame__baseclasses_length;
    ((struct System__Environment_plus_StackFrame*)parameter0)->MethodSignature = 0;
    ((struct System__Environment_plus_StackFrame*)parameter0)->FileName = 0;
    ((struct System__Environment_plus_StackFrame*)parameter0)->LineNumber = 0;
    System__Environment_plus_StackFrame_m___ctor0006: CIL_ret();
    CIL_ret();
}
// class System.Environment
/* System.Environment::.ctor */
char* m9C2D6B8FFFDF6638C40874A9AA1FD4210D457DF4_sig = "System.Environment::.ctor()";
void *m9C2D6B8FFFDF6638C40874A9AA1FD4210D457DF4(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Environment_m___ctor0000: CIL_ldarg__0();
    System__Environment_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Environment";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Environment__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Environment__baseclasses_length;
    System__Environment_m___ctor0006: CIL_ret();
    CIL_ret();
}
/* System.Environment::get_StackTrace */
char* m71CD3EBF055D1B6753790AA34B603EC59C86F9FC_sig = "System.Environment::get_StackTrace()";
void *m71CD3EBF055D1B6753790AA34B603EC59C86F9FC(/**/) {
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Environment_m_get_StackTrace0000: CIL_nop();
    System__Environment_m_get_StackTrace0001: CIL_call(m04E907104A79434AA6772B59957D5D9B78CB2F1E, "m6BB020C2B791C916101425CB0032B124192AC811", 0, 0/* System.String System.Environment::GetStackTrace() */);
    System__Environment_m_get_StackTrace0006: CIL_stloc__0();
    System__Environment_m_get_StackTrace0007: goto System__Environment_m_get_StackTrace0009;
    System__Environment_m_get_StackTrace0009: CIL_ldloc__0();
    System__Environment_m_get_StackTrace0010: CIL_ret();
    CIL_ret();
}
/* System.Environment::GetStackFrame */
char* m9594737445D4A66937A33CB4CB57BF0B1E2357E2_sig = "System.Environment::GetStackFrame(Int32 i)";
void *m9594737445D4A66937A33CB4CB57BF0B1E2357E2(/*Int32 i*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Int32
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.Environment+StackFrame
    uintptr_t local1 = 0;
    enum CIL_Type local1__type = CIL_pointer; // System.Environment+StackFrame
    System__Environment_m_GetStackFrame0000: CIL_nop();
    System__Environment_m_GetStackFrame0001: CIL_newobj(System__Environment_plus_StackFrame, mB60C279DD2E6FD1E17763B0A68D79B5B2154E850/* System.Environment+StackFrame::.ctor */);
    System__Environment_m_GetStackFrame0006: CIL_stloc__0();
    System__Environment_m_GetStackFrame0007: CIL_ldloc__0();
    System__Environment_m_GetStackFrame0008: CIL_ldarg__0();
    System__Environment_m_GetStackFrame0009: CIL_call(m5F25EB0EB441F9DA75DEE2BA9BF909461A4FCC67, "m1EF5DD0064550048F488E1814B98D172C68BD4DE", 1, 0/* System.String System.Environment::GetStackFrameMethodSignature(System.Int32, ) */);
    System__Environment_m_GetStackFrame0014: CIL_stfld(System__Environment_plus_StackFrame, MethodSignature);
    System__Environment_m_GetStackFrame0019: CIL_ldloc__0();
    System__Environment_m_GetStackFrame0020: CIL_ldarg__0();
    System__Environment_m_GetStackFrame0021: CIL_call(m9E05B7440A52783C51AC1F8E87E6D7E7E2E5208D, "m0600CC5AA4CE585DE289F99BD6AA1833E8EA681E", 1, 0/* System.String System.Environment::GetStackFrameFileName(System.Int32, ) */);
    System__Environment_m_GetStackFrame0026: CIL_stfld(System__Environment_plus_StackFrame, FileName);
    System__Environment_m_GetStackFrame0031: CIL_ldloc__0();
    System__Environment_m_GetStackFrame0032: CIL_ldarg__0();
    System__Environment_m_GetStackFrame0033: CIL_call(m2CB1E7709800E970609D6D388B8644BE714956DC, "m152CD4298B66D39ABA9E8F392FD136EDCAFFBCE5", 1, 0/* System.Int32 System.Environment::GetStackFrameLineNumber(System.Int32, ) */);
    System__Environment_m_GetStackFrame0038: CIL_stfld(System__Environment_plus_StackFrame, LineNumber);
    System__Environment_m_GetStackFrame0043: CIL_ldloc__0();
    System__Environment_m_GetStackFrame0044: CIL_stloc__1();
    System__Environment_m_GetStackFrame0045: goto System__Environment_m_GetStackFrame0047;
    System__Environment_m_GetStackFrame0047: CIL_ldloc__1();
    System__Environment_m_GetStackFrame0048: CIL_ret();
    CIL_ret();
}
/* System.Environment::GetStackFrameCount */
char* mC6D50132C91F883AA60D6019885C48D34BD7181E_sig = "System.Environment::GetStackFrameCount()";
void *mC6D50132C91F883AA60D6019885C48D34BD7181E(/**/) {
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        push_value32(callstack_size(), CIL_int32);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Environment::GetStackFrameLineNumber */
char* m2CB1E7709800E970609D6D388B8644BE714956DC_sig = "System.Environment::GetStackFrameLineNumber(Int32 i)";
void *m2CB1E7709800E970609D6D388B8644BE714956DC(/*Int32 i*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Int32
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct StackFrame sf = callstack_at(parameter0);
        push_value32(sf.linenumber, CIL_int32);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Environment::GetStackFrameMethodSignature */
char* m5F25EB0EB441F9DA75DEE2BA9BF909461A4FCC67_sig = "System.Environment::GetStackFrameMethodSignature(Int32 i)";
void *m5F25EB0EB441F9DA75DEE2BA9BF909461A4FCC67(/*Int32 i*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Int32
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct StackFrame sf = callstack_at(parameter0);
        CIL_ldstr(sf.MethodSignature);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Environment::GetStackFrameFileName */
char* m9E05B7440A52783C51AC1F8E87E6D7E7E2E5208D_sig = "System.Environment::GetStackFrameFileName(Int32 i)";
void *m9E05B7440A52783C51AC1F8E87E6D7E7E2E5208D(/*Int32 i*/) {
    int32_t parameter0 = pop_value32();
    enum CIL_Type parameter0__type = CIL_int32; // System.Int32
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct StackFrame sf = callstack_at(parameter0);
        CIL_ldstr(sf.filename);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Environment::PrintCallStack */
char* m70091ABF0A9B0C1D7D6EABD63867F1F8AE9C4312_sig = "System.Environment::PrintCallStack()";
void *m70091ABF0A9B0C1D7D6EABD63867F1F8AE9C4312(/**/) {
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        print_callstack();
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.Environment::GetStackTrace */
char* m04E907104A79434AA6772B59957D5D9B78CB2F1E_sig = "System.Environment::GetStackTrace()";
void *m04E907104A79434AA6772B59957D5D9B78CB2F1E(/**/) {
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Int32
    int32_t local2 = 0;
    enum CIL_Type local2__type = CIL_int32; // System.Int32
    uintptr_t local3 = 0;
    enum CIL_Type local3__type = CIL_pointer; // System.Environment+StackFrame
    uintptr_t local4 = 0;
    enum CIL_Type local4__type = CIL_pointer; // System.String
    int32_t local5 = 0;
    enum CIL_Type local5__type = CIL_int32; // System.Boolean
    System__Environment_m_GetStackTrace0000: CIL_nop();
    System__Environment_m_GetStackTrace0001: CIL_ldstr("");
    System__Environment_m_GetStackTrace0006: CIL_stloc__0();
    System__Environment_m_GetStackTrace0007: CIL_call(mC6D50132C91F883AA60D6019885C48D34BD7181E, "m268AE0CEC3FA8BE8BE65E7227FCF1B68F9164322", 0, 0/* System.Int32 System.Environment::GetStackFrameCount() */);
    System__Environment_m_GetStackTrace0012: CIL_ldc__i4__4();
    System__Environment_m_GetStackTrace0013: CIL_sub();
    System__Environment_m_GetStackTrace0014: CIL_stloc__1();
    System__Environment_m_GetStackTrace0015: CIL_ldloc__1();
    System__Environment_m_GetStackTrace0016: CIL_stloc__2();
    System__Environment_m_GetStackTrace0017: goto System__Environment_m_GetStackTrace0055;
    System__Environment_m_GetStackTrace0019: CIL_nop();
    System__Environment_m_GetStackTrace0020: CIL_ldloc__2();
    System__Environment_m_GetStackTrace0021: CIL_call(m9594737445D4A66937A33CB4CB57BF0B1E2357E2, "mC59BBBA64E19358B78EF25383021764A7BB2AF73", 1, 0/* System.Environment+StackFrame System.Environment::GetStackFrame(System.Int32, ) */);
    System__Environment_m_GetStackTrace0026: CIL_stloc__3();
    System__Environment_m_GetStackTrace0027: CIL_ldloc__0();
    System__Environment_m_GetStackTrace0028: CIL_ldstr("  at ");
    System__Environment_m_GetStackTrace0033: CIL_ldloc__3();
    System__Environment_m_GetStackTrace0034: CIL_ldfld(System__Environment_plus_StackFrame, MethodSignature);
    System__Environment_m_GetStackTrace0039: CIL_ldstr("\n");
    System__Environment_m_GetStackTrace0044: CIL_call(m6D004057DAB052B8C56F4E0C7BC60923AA5FE38D, "m5D8FF881EAF239C0E4661460BABC9762B3A7659A", 4, 0/* System.String System.String::Concat(System.String, System.String, System.String, System.String, ) */);
    System__Environment_m_GetStackTrace0049: CIL_stloc__0();
    System__Environment_m_GetStackTrace0050: CIL_nop();
    System__Environment_m_GetStackTrace0051: CIL_ldloc__2();
    System__Environment_m_GetStackTrace0052: CIL_ldc__i4__1();
    System__Environment_m_GetStackTrace0053: CIL_sub();
    System__Environment_m_GetStackTrace0054: CIL_stloc__2();
    System__Environment_m_GetStackTrace0055: CIL_ldloc__2();
    System__Environment_m_GetStackTrace0056: CIL_ldc__i4__0();
    System__Environment_m_GetStackTrace0058: CIL_clt();
    System__Environment_m_GetStackTrace0059: CIL_ldc__i4__0();
    System__Environment_m_GetStackTrace0061: CIL_ceq();
    System__Environment_m_GetStackTrace0062: CIL_stloc__s(5);
    System__Environment_m_GetStackTrace0064: CIL_ldloc__s(5);
    System__Environment_m_GetStackTrace0066: CIL_brtrue__s(System__Environment_m_GetStackTrace0019);
    System__Environment_m_GetStackTrace0068: CIL_ldloc__0();
    System__Environment_m_GetStackTrace0069: CIL_stloc__s(4);
    System__Environment_m_GetStackTrace0071: goto System__Environment_m_GetStackTrace0073;
    System__Environment_m_GetStackTrace0073: CIL_ldloc__s(4);
    System__Environment_m_GetStackTrace0075: CIL_ret();
    CIL_ret();
}
// class System.__String
/* System.String::.ctor */
char* m8D858A38DA1EA05CB64209432DD7505A8FE82943_sig = "System.String::.ctor()";
void *m8D858A38DA1EA05CB64209432DD7505A8FE82943(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__String_m___ctor0000: CIL_ldarg__0();
    System__String_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.String";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__String__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__String__baseclasses_length;
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", &m974A2FF1C77976DC2453909489D91994F089A011); /* ToString */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m75B859EF0005863D5158396CB89114C5BF752DA3", &m21E134FA241A623E1403EB610DBBA2DEDF8EF2A8); /* Equals */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m9B47C032938820269CE9D24A72B299C9D2A50C6C", &mA2B3CE0D9AEA66CFE1F24C3B5FC23A13A5280D5B); /* GetHashCode */
    System__String_m___ctor0006: CIL_nop();
    System__String_m___ctor0007: CIL_nop();
    System__String_m___ctor0008: CIL_nop();
    System__String_m___ctor0009: CIL_ret();
    CIL_ret();
}
/* System.String::.ctor */
char* mEC086807E22379BAD6CFAFA38CE803A4A640AF12_sig = "System.String::.ctor(String str)";
void *mEC086807E22379BAD6CFAFA38CE803A4A640AF12(/*String str*/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct System__String *this = (struct System__String*)parameter0;
        struct System__String *other = (struct System__String*)parameter1;
        this->str = (char*)malloc(strlen(other->str) + 1);
        strcpy(this->str, other->str);
        CIL_ret();
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::Concat */
char* m5F35C1AA2625C561EEFA593979D885EB0763DC43_sig = "System.String::Concat(String str0, String str1)";
void *m5F35C1AA2625C561EEFA593979D885EB0763DC43(/*String str0, String str1*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
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
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::get_Length */
char* mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A_sig = "System.String::get_Length()";
void *mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct System__String *this = (struct System__String*)parameter0;
        push_value32(strlen(this->str), CIL_int32);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::Concat */
char* m5E8E86CD8F17353D6D6BD4C2B993409013D4F70A_sig = "System.String::Concat(Object arg0, Object arg1)";
void *m5E8E86CD8F17353D6D6BD4C2B993409013D4F70A(/*Object arg0, Object arg1*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.Object
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__String_m_Concat0000: CIL_nop();
    System__String_m_Concat0001: CIL_ldarg__0();
    System__String_m_Concat0002: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0007: CIL_ldarg__1();
    System__String_m_Concat0008: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0013: CIL_call(m5F35C1AA2625C561EEFA593979D885EB0763DC43, "mA83B79BB4C763242D6CAA94B987E9339ED17D40F", 2, 0/* System.String System.__String::Concat(System.String, System.String, ) */);
    System__String_m_Concat0018: CIL_stloc__0();
    System__String_m_Concat0019: goto System__String_m_Concat0021;
    System__String_m_Concat0021: CIL_ldloc__0();
    System__String_m_Concat0022: CIL_ret();
    CIL_ret();
}
/* System.String::Concat */
char* m8B053C291B7A1D3C3B910E700C4F9247C1E00320_sig = "System.String::Concat(Object arg0, Object arg1, Object arg2)";
void *m8B053C291B7A1D3C3B910E700C4F9247C1E00320(/*Object arg0, Object arg1, Object arg2*/) {
    uintptr_t parameter2 = pop_pointer();
    enum CIL_Type parameter2__type = CIL_pointer; // System.Object
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.Object
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__String_m_Concat0000: CIL_nop();
    System__String_m_Concat0001: CIL_ldarg__0();
    System__String_m_Concat0002: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0007: CIL_ldarg__1();
    System__String_m_Concat0008: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0013: CIL_ldarg__2();
    System__String_m_Concat0014: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0019: CIL_call(mEBFE3FA5AAAF9A5D7F5D49848C36C3DDC4F6E1B4, "m0275F44A18CC87BBD5D96945118D5038C7315652", 3, 0/* System.String System.__String::Concat(System.String, System.String, System.String, ) */);
    System__String_m_Concat0024: CIL_stloc__0();
    System__String_m_Concat0025: goto System__String_m_Concat0027;
    System__String_m_Concat0027: CIL_ldloc__0();
    System__String_m_Concat0028: CIL_ret();
    CIL_ret();
}
/* System.String::Concat */
char* mEBFE3FA5AAAF9A5D7F5D49848C36C3DDC4F6E1B4_sig = "System.String::Concat(String arg0, String arg1, String arg2)";
void *mEBFE3FA5AAAF9A5D7F5D49848C36C3DDC4F6E1B4(/*String arg0, String arg1, String arg2*/) {
    uintptr_t parameter2 = pop_pointer();
    enum CIL_Type parameter2__type = CIL_pointer; // System.String
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
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
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::Concat */
char* m0FC9495B749D746A06DDED51E1B7DD5BFD159FD9_sig = "System.String::Concat(Object arg0, Object arg1, Object arg2, Object arg3)";
void *m0FC9495B749D746A06DDED51E1B7DD5BFD159FD9(/*Object arg0, Object arg1, Object arg2, Object arg3*/) {
    uintptr_t parameter3 = pop_pointer();
    enum CIL_Type parameter3__type = CIL_pointer; // System.Object
    uintptr_t parameter2 = pop_pointer();
    enum CIL_Type parameter2__type = CIL_pointer; // System.Object
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.Object
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__String_m_Concat0000: CIL_nop();
    System__String_m_Concat0001: CIL_ldarg__0();
    System__String_m_Concat0002: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0007: CIL_ldarg__1();
    System__String_m_Concat0008: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0013: CIL_ldarg__2();
    System__String_m_Concat0014: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0019: CIL_ldarg__3();
    System__String_m_Concat0020: CIL_callvirt(/*instance*/ m8E6836504E6F32F58A5D7822EDF304BB4064BF64, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1/* System.String System.Object::ToString() */);
    System__String_m_Concat0025: CIL_call(m6D004057DAB052B8C56F4E0C7BC60923AA5FE38D, "m5D8FF881EAF239C0E4661460BABC9762B3A7659A", 4, 0/* System.String System.__String::Concat(System.String, System.String, System.String, System.String, ) */);
    System__String_m_Concat0030: CIL_stloc__0();
    System__String_m_Concat0031: goto System__String_m_Concat0033;
    System__String_m_Concat0033: CIL_ldloc__0();
    System__String_m_Concat0034: CIL_ret();
    CIL_ret();
}
/* System.String::Concat */
char* m6D004057DAB052B8C56F4E0C7BC60923AA5FE38D_sig = "System.String::Concat(String arg0, String arg1, String arg2, String arg3)";
void *m6D004057DAB052B8C56F4E0C7BC60923AA5FE38D(/*String arg0, String arg1, String arg2, String arg3*/) {
    uintptr_t parameter3 = pop_pointer();
    enum CIL_Type parameter3__type = CIL_pointer; // System.String
    uintptr_t parameter2 = pop_pointer();
    enum CIL_Type parameter2__type = CIL_pointer; // System.String
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
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
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::ToString */
char* m974A2FF1C77976DC2453909489D91994F089A011_sig = "System.String::ToString()";
void *m974A2FF1C77976DC2453909489D91994F089A011(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        CIL_ldarg__0();
        CIL_ret();
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::op_Equality */
char* m16C5477951DBB9F934C87FF8ADC1C322F099E987_sig = "System.String::op_Equality(__String a, __String b)";
void *m16C5477951DBB9F934C87FF8ADC1C322F099E987(/*__String a, __String b*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.__String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.__String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Boolean
    System__String_m_op_Equality0000: CIL_nop();
    System__String_m_op_Equality0001: CIL_ldarg__0();
    System__String_m_op_Equality0002: CIL_ldarg__1();
    System__String_m_op_Equality0003: CIL_callvirt(/*instance*/ mECE756C5FF4B4460FFCA6138BB624952680B8FD8, "mF9961702BC584C0465F0FF86981882A0DF6B7F16", 1, 0/* System.Boolean System.__String::Equals(System.__String, ) */);
    System__String_m_op_Equality0008: CIL_stloc__0();
    System__String_m_op_Equality0009: goto System__String_m_op_Equality0011;
    System__String_m_op_Equality0011: CIL_ldloc__0();
    System__String_m_op_Equality0012: CIL_ret();
    CIL_ret();
}
/* System.String::op_Inequality */
char* mCF1776B0CAD1B5A27DA229E0EF7FF5955A4EFF32_sig = "System.String::op_Inequality(__String a, __String b)";
void *mCF1776B0CAD1B5A27DA229E0EF7FF5955A4EFF32(/*__String a, __String b*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.__String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer; // System.__String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Boolean
    System__String_m_op_Inequality0000: CIL_nop();
    System__String_m_op_Inequality0001: CIL_ldarg__0();
    System__String_m_op_Inequality0002: CIL_ldarg__1();
    System__String_m_op_Inequality0003: CIL_callvirt(/*instance*/ mECE756C5FF4B4460FFCA6138BB624952680B8FD8, "mF9961702BC584C0465F0FF86981882A0DF6B7F16", 1, 0/* System.Boolean System.__String::Equals(System.__String, ) */);
    System__String_m_op_Inequality0008: CIL_ldc__i4__0();
    System__String_m_op_Inequality0010: CIL_ceq();
    System__String_m_op_Inequality0011: CIL_stloc__0();
    System__String_m_op_Inequality0012: goto System__String_m_op_Inequality0014;
    System__String_m_op_Inequality0014: CIL_ldloc__0();
    System__String_m_op_Inequality0015: CIL_ret();
    CIL_ret();
}
/* System.String::Equals */
char* mECE756C5FF4B4460FFCA6138BB624952680B8FD8_sig = "System.String::Equals(__String other)";
void *mECE756C5FF4B4460FFCA6138BB624952680B8FD8(/*__String other*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.__String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct System__String *this = (struct System__String*)parameter0;
        struct System__String *other = (struct System__String*)parameter1;
        if (strcmp(this->str, other->str) == 0) {
            push_value32(1, CIL_int32);
        } else {
            push_value32(0, CIL_int32);
        }
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::Equals */
char* m21E134FA241A623E1403EB610DBBA2DEDF8EF2A8_sig = "System.String::Equals(Object obj)";
void *m21E134FA241A623E1403EB610DBBA2DEDF8EF2A8(/*Object obj*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Boolean
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Boolean
    System__String_m_Equals0000: CIL_nop();
    System__String_m_Equals0001: CIL_ldarg__1();
    System__String_m_Equals0002: CIL_callvirt(/*instance*/ m3AD7669D6B5B2D33720E022E66E577E003E2D15A, "m8C906D9E0E2439238B3263E087AEE3D98FA86DEA", 0, 0/* System.Type System.Object::GetType() */);
    System__String_m_Equals0007: CIL_ldarg__0();
    System__String_m_Equals0008: CIL_call(/*instance*/ m3AD7669D6B5B2D33720E022E66E577E003E2D15A, "m8C906D9E0E2439238B3263E087AEE3D98FA86DEA", 0, 0/* System.Type System.Object::GetType() */);
    System__String_m_Equals0013: CIL_callvirt(/*instance*/ m6CA9ADDD9E00004369D8E55E354A2CAB80071BE7, "m5E812C3C64800981CCC02963A8512F3AFE9A56BE", 1, 1/* System.Boolean System.Type::Equals(System.Type, ) */);
    System__String_m_Equals0018: CIL_ldc__i4__0();
    System__String_m_Equals0020: CIL_ceq();
    System__String_m_Equals0021: CIL_stloc__1();
    System__String_m_Equals0022: CIL_ldloc__1();
    System__String_m_Equals0023: CIL_brtrue__s(System__String_m_Equals0040);
    System__String_m_Equals0025: CIL_ldarg__0();
    System__String_m_Equals0026: CIL_ldarg__1();
    System__String_m_Equals0027: CIL_castclass(System.String);
    System__String_m_Equals0032: CIL_callvirt(/*instance*/ mF028F029FE2B7E6C5FC6B76272F2F98668C649C8, "m75B859EF0005863D5158396CB89114C5BF752DA3", 1, 1/* System.Boolean System.Object::Equals(System.Object, ) */);
    System__String_m_Equals0037: CIL_stloc__0();
    System__String_m_Equals0038: goto System__String_m_Equals0044;
    System__String_m_Equals0040: CIL_ldc__i4__0();
    System__String_m_Equals0041: CIL_stloc__0();
    System__String_m_Equals0042: goto System__String_m_Equals0044;
    System__String_m_Equals0044: CIL_ldloc__0();
    System__String_m_Equals0045: CIL_ret();
    CIL_ret();
}
/* System.String::GetHashCode */
char* mA2B3CE0D9AEA66CFE1F24C3B5FC23A13A5280D5B_sig = "System.String::GetHashCode()";
void *mA2B3CE0D9AEA66CFE1F24C3B5FC23A13A5280D5B(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct System__String *this = (struct System__String*)parameter0;
        unsigned long hash = 5381;
        int c;
        char* str = this->str;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        push_value32((int32_t)hash, CIL_int32);
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::IndexOf */
char* m9080C0A7B04E806CF0B2B4731605A21E78F85C82_sig = "System.String::IndexOf(String str)";
void *m9080C0A7B04E806CF0B2B4731605A21E78F85C82(/*String str*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Int32
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Int32
    int32_t local2 = 0;
    enum CIL_Type local2__type = CIL_int32; // System.Int32
    int32_t local3 = 0;
    enum CIL_Type local3__type = CIL_int32; // System.Int32
    int32_t local4 = 0;
    enum CIL_Type local4__type = CIL_int32; // System.Int32
    int32_t local5 = 0;
    enum CIL_Type local5__type = CIL_int32; // System.Boolean
    System__String_m_IndexOf0000: CIL_nop();
    System__String_m_IndexOf0001: CIL_ldarg__0();
    System__String_m_IndexOf0002: CIL_call(/*instance*/ mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A, "mA7DEA479C217F8C5F4A44D4803DD23DABD67DBA2", 0, 0/* System.Int32 System.__String::get_Length() */);
    System__String_m_IndexOf0007: CIL_stloc__0();
    System__String_m_IndexOf0008: CIL_ldarg__1();
    System__String_m_IndexOf0009: CIL_callvirt(/*instance*/ mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A, "mA7DEA479C217F8C5F4A44D4803DD23DABD67DBA2", 0, 0/* System.Int32 System.String::get_Length() */);
    System__String_m_IndexOf0014: CIL_stloc__1();
    System__String_m_IndexOf0015: CIL_ldc__i4__0();
    System__String_m_IndexOf0016: CIL_stloc__2();
    System__String_m_IndexOf0017: goto System__String_m_IndexOf0077;
    System__String_m_IndexOf0019: CIL_nop();
    System__String_m_IndexOf0020: CIL_ldc__i4__0();
    System__String_m_IndexOf0021: CIL_stloc__3();
    System__String_m_IndexOf0022: goto System__String_m_IndexOf0048;
    System__String_m_IndexOf0024: CIL_nop();
    System__String_m_IndexOf0025: CIL_ldloc__3();
    System__String_m_IndexOf0026: CIL_ldc__i4__1();
    System__String_m_IndexOf0027: CIL_add();
    System__String_m_IndexOf0028: CIL_stloc__3();
    System__String_m_IndexOf0029: CIL_ldloc__3();
    System__String_m_IndexOf0030: CIL_ldloc__1();
    System__String_m_IndexOf0032: CIL_ceq();
    System__String_m_IndexOf0033: CIL_ldc__i4__0();
    System__String_m_IndexOf0035: CIL_ceq();
    System__String_m_IndexOf0036: CIL_stloc__s(5);
    System__String_m_IndexOf0038: CIL_ldloc__s(5);
    System__String_m_IndexOf0040: CIL_brtrue__s(System__String_m_IndexOf0047);
    System__String_m_IndexOf0042: CIL_ldloc__2();
    System__String_m_IndexOf0043: CIL_stloc__s(4);
    System__String_m_IndexOf0045: goto System__String_m_IndexOf0097;
    System__String_m_IndexOf0047: CIL_nop();
    System__String_m_IndexOf0048: CIL_ldarg__0();
    System__String_m_IndexOf0049: CIL_ldloc__2();
    System__String_m_IndexOf0050: CIL_ldloc__3();
    System__String_m_IndexOf0051: CIL_add();
    System__String_m_IndexOf0052: CIL_call(/*instance*/ mC23D93FF06232BC655DEE27F7F6F9D7E71B35491, "m4DB937F10F89C39CD2BC4631BACAA65843485BF0", 1, 0/* System.Char System.__String::get_Chars(System.Int32, ) */);
    System__String_m_IndexOf0057: CIL_ldarg__1();
    System__String_m_IndexOf0058: CIL_ldloc__3();
    System__String_m_IndexOf0059: CIL_callvirt(/*instance*/ mC23D93FF06232BC655DEE27F7F6F9D7E71B35491, "m4DB937F10F89C39CD2BC4631BACAA65843485BF0", 1, 0/* System.Char System.String::get_Chars(System.Int32, ) */);
    System__String_m_IndexOf0065: CIL_ceq();
    System__String_m_IndexOf0066: CIL_stloc__s(5);
    System__String_m_IndexOf0068: CIL_ldloc__s(5);
    System__String_m_IndexOf0070: CIL_brtrue__s(System__String_m_IndexOf0024);
    System__String_m_IndexOf0072: CIL_nop();
    System__String_m_IndexOf0073: CIL_ldloc__2();
    System__String_m_IndexOf0074: CIL_ldc__i4__1();
    System__String_m_IndexOf0075: CIL_add();
    System__String_m_IndexOf0076: CIL_stloc__2();
    System__String_m_IndexOf0077: CIL_ldloc__2();
    System__String_m_IndexOf0078: CIL_ldloc__0();
    System__String_m_IndexOf0079: CIL_ldloc__1();
    System__String_m_IndexOf0080: CIL_sub();
    System__String_m_IndexOf0082: CIL_cgt();
    System__String_m_IndexOf0083: CIL_ldc__i4__0();
    System__String_m_IndexOf0085: CIL_ceq();
    System__String_m_IndexOf0086: CIL_stloc__s(5);
    System__String_m_IndexOf0088: CIL_ldloc__s(5);
    System__String_m_IndexOf0090: CIL_brtrue__s(System__String_m_IndexOf0019);
    System__String_m_IndexOf0092: CIL_ldc__i4__m1();
    System__String_m_IndexOf0093: CIL_stloc__s(4);
    System__String_m_IndexOf0095: goto System__String_m_IndexOf0097;
    System__String_m_IndexOf0097: CIL_ldloc__s(4);
    System__String_m_IndexOf0099: CIL_ret();
    CIL_ret();
}
/* System.String::IndexOf */
char* m0629A285D432E6C3793ADCFE36AD0DA2956BD074_sig = "System.String::IndexOf(Char c)";
void *m0629A285D432E6C3793ADCFE36AD0DA2956BD074(/*Char c*/) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Char
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Int32
    int32_t local1 = 0;
    enum CIL_Type local1__type = CIL_int32; // System.Int32
    int32_t local2 = 0;
    enum CIL_Type local2__type = CIL_int32; // System.Int32
    int32_t local3 = 0;
    enum CIL_Type local3__type = CIL_int32; // System.Boolean
    System__String_m_IndexOf0000: CIL_nop();
    System__String_m_IndexOf0001: CIL_ldarg__0();
    System__String_m_IndexOf0002: CIL_call(/*instance*/ mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A, "mA7DEA479C217F8C5F4A44D4803DD23DABD67DBA2", 0, 0/* System.Int32 System.__String::get_Length() */);
    System__String_m_IndexOf0007: CIL_stloc__0();
    System__String_m_IndexOf0008: CIL_ldc__i4__0();
    System__String_m_IndexOf0009: CIL_stloc__1();
    System__String_m_IndexOf0010: goto System__String_m_IndexOf0039;
    System__String_m_IndexOf0012: CIL_nop();
    System__String_m_IndexOf0013: CIL_ldarg__0();
    System__String_m_IndexOf0014: CIL_ldloc__1();
    System__String_m_IndexOf0015: CIL_call(/*instance*/ mC23D93FF06232BC655DEE27F7F6F9D7E71B35491, "m4DB937F10F89C39CD2BC4631BACAA65843485BF0", 1, 0/* System.Char System.__String::get_Chars(System.Int32, ) */);
    System__String_m_IndexOf0020: CIL_ldarg__1();
    System__String_m_IndexOf0022: CIL_ceq();
    System__String_m_IndexOf0023: CIL_ldc__i4__0();
    System__String_m_IndexOf0025: CIL_ceq();
    System__String_m_IndexOf0026: CIL_stloc__3();
    System__String_m_IndexOf0027: CIL_ldloc__3();
    System__String_m_IndexOf0028: CIL_brtrue__s(System__String_m_IndexOf0034);
    System__String_m_IndexOf0030: CIL_ldloc__1();
    System__String_m_IndexOf0031: CIL_stloc__2();
    System__String_m_IndexOf0032: goto System__String_m_IndexOf0051;
    System__String_m_IndexOf0034: CIL_nop();
    System__String_m_IndexOf0035: CIL_ldloc__1();
    System__String_m_IndexOf0036: CIL_ldc__i4__1();
    System__String_m_IndexOf0037: CIL_add();
    System__String_m_IndexOf0038: CIL_stloc__1();
    System__String_m_IndexOf0039: CIL_ldloc__1();
    System__String_m_IndexOf0040: CIL_ldloc__0();
    System__String_m_IndexOf0042: CIL_clt();
    System__String_m_IndexOf0043: CIL_stloc__3();
    System__String_m_IndexOf0044: CIL_ldloc__3();
    System__String_m_IndexOf0045: CIL_brtrue__s(System__String_m_IndexOf0012);
    System__String_m_IndexOf0047: CIL_ldc__i4__m1();
    System__String_m_IndexOf0048: CIL_stloc__2();
    System__String_m_IndexOf0049: goto System__String_m_IndexOf0051;
    System__String_m_IndexOf0051: CIL_ldloc__2();
    System__String_m_IndexOf0052: CIL_ret();
    CIL_ret();
}
/* System.String::Substring */
char* m35DD150503CB22A5AC8E05A5A6785912945CF6D8_sig = "System.String::Substring(Int32 start)";
void *m35DD150503CB22A5AC8E05A5A6785912945CF6D8(/*Int32 start*/) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Int32
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
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
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::Substring */
char* m45AA36C8D31BBDDFDD56C822F9789F490B4A4E17_sig = "System.String::Substring(Int32 start, Int32 length)";
void *m45AA36C8D31BBDDFDD56C822F9789F490B4A4E17(/*Int32 start, Int32 length*/) {
    int32_t parameter2 = pop_value32();
    enum CIL_Type parameter2__type = CIL_int32; // System.Int32
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Int32
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
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
        }
    /* END INLINE CODE */
    CIL_ret();
}
/* System.String::get_Chars */
char* mC23D93FF06232BC655DEE27F7F6F9D7E71B35491_sig = "System.String::get_Chars(Int32 i)";
void *mC23D93FF06232BC655DEE27F7F6F9D7E71B35491(/*Int32 i*/) {
    int32_t parameter1 = pop_value32();
    enum CIL_Type parameter1__type = CIL_int32; // System.Int32
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    /* INLINE CODE */
{
        struct System__String *this = (struct System__String*)parameter0;
        int i = parameter1;
        if (i < 0 || i > strlen(this->str) - 1) {
            throw_IndexOutOfRangeException();
        }
        char c = this->str[i];
        push_value32((int32_t)c, CIL_int32);
        }
    /* END INLINE CODE */
    CIL_ret();
}
// class System.Type
/* System.Type::.ctor */
char* mCBE8D294E24BA0AFAB3C8B977360892A2BD95CC8_sig = "System.Type::.ctor(String fullName)";
void *mCBE8D294E24BA0AFAB3C8B977360892A2BD95CC8(/*String fullName*/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Type_m___ctor0000: CIL_ldarg__0();
    System__Type_m___ctor0001: CIL_call(/*constructor*/ m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16, "NONE", 0, 0 /* System.Object::.ctor() */);
    ((struct System__Object*)parameter0)->__CILtype = (intptr_t)"System.Type";
    ((struct System__Object*)parameter0)->__CILbaseclasses = (intptr_t)&System__Type__baseclasses;
    ((struct System__Object*)parameter0)->__CILbaseclasses_length = &System__Type__baseclasses_length;
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m68BA1259C9E4CD877B3F4E9E6D3008295D1561CD", &m471812BAA2AA3BC55129B509A2F1EE2354782771); /* IsSubclassOf */
    hashmap_put(((struct System__Object*)parameter0)->__CILsymboltable, "m8B2F1DE3D2341E58163B68EAE5298BE13D957E85", &m8FEAD892E91559B4B066AA112218678D0F7DC4E4); /* IsInstanceOfType */
    ((struct System__Type*)parameter0)->_FullName_k__BackingField = 0;
    System__Type_m___ctor0006: CIL_nop();
    System__Type_m___ctor0007: CIL_nop();
    System__Type_m___ctor0008: CIL_ldarg__0();
    System__Type_m___ctor0009: CIL_ldarg__1();
    System__Type_m___ctor0010: CIL_call(/*instance*/ m7782966344AAB1DE5CEF6BB9C206CBAB76F71903, "m54D29172FE843F6CA9A2D6A88B8240732CF8B2F5", 1, 0/* System.Void System.Type::set_FullName(System.String, ) */);
    System__Type_m___ctor0015: CIL_nop();
    System__Type_m___ctor0016: CIL_nop();
    System__Type_m___ctor0017: CIL_ret();
    CIL_ret();
}
/* System.Type::get_FullName */
char* m615E6B2B0668333A85B347BF17D5E0A60CBE3B53_sig = "System.Type::get_FullName()";
void *m615E6B2B0668333A85B347BF17D5E0A60CBE3B53(/**/) {
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    uintptr_t local0 = 0;
    enum CIL_Type local0__type = CIL_pointer; // System.String
    System__Type_m_get_FullName0000: CIL_ldarg__0();
    System__Type_m_get_FullName0001: CIL_ldfld(System__Type, _FullName_k__BackingField);
    System__Type_m_get_FullName0006: CIL_stloc__0();
    System__Type_m_get_FullName0007: goto System__Type_m_get_FullName0009;
    System__Type_m_get_FullName0009: CIL_ldloc__0();
    System__Type_m_get_FullName0010: CIL_ret();
    CIL_ret();
}
/* System.Type::set_FullName */
char* m7782966344AAB1DE5CEF6BB9C206CBAB76F71903_sig = "System.Type::set_FullName(String value)";
void *m7782966344AAB1DE5CEF6BB9C206CBAB76F71903(/*String value*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.String
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Type_m_set_FullName0000: CIL_ldarg__0();
    System__Type_m_set_FullName0001: CIL_ldarg__1();
    System__Type_m_set_FullName0002: CIL_stfld(System__Type, _FullName_k__BackingField);
    System__Type_m_set_FullName0007: CIL_ret();
    CIL_ret();
}
/* System.Type::Equals */
char* m6CA9ADDD9E00004369D8E55E354A2CAB80071BE7_sig = "System.Type::Equals(Type other)";
void *m6CA9ADDD9E00004369D8E55E354A2CAB80071BE7(/*Type other*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Type
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    int32_t local0 = 0;
    enum CIL_Type local0__type = CIL_int32; // System.Boolean
    System__Type_m_Equals0000: CIL_nop();
    System__Type_m_Equals0001: CIL_ldarg__0();
    System__Type_m_Equals0002: CIL_call(/*instance*/ m615E6B2B0668333A85B347BF17D5E0A60CBE3B53, "mE1A383ECC717163F310DB59C92367DF1CC9DD2AE", 0, 0/* System.String System.Type::get_FullName() */);
    System__Type_m_Equals0007: CIL_ldarg__1();
    System__Type_m_Equals0008: CIL_callvirt(/*instance*/ m615E6B2B0668333A85B347BF17D5E0A60CBE3B53, "mE1A383ECC717163F310DB59C92367DF1CC9DD2AE", 0, 0/* System.String System.Type::get_FullName() */);
    System__Type_m_Equals0013: CIL_call(m16C5477951DBB9F934C87FF8ADC1C322F099E987, "m994E8A3E45914623F3B0F59986509D1EDC00EB01", 2, 0/* System.Boolean System.String::op_Equality(System.String, System.String, ) */);
    System__Type_m_Equals0018: CIL_stloc__0();
    System__Type_m_Equals0019: goto System__Type_m_Equals0021;
    System__Type_m_Equals0021: CIL_ldloc__0();
    System__Type_m_Equals0022: CIL_ret();
    CIL_ret();
}
/* System.Type::IsSubclassOf */
char* m471812BAA2AA3BC55129B509A2F1EE2354782771_sig = "System.Type::IsSubclassOf(Type c)";
void *m471812BAA2AA3BC55129B509A2F1EE2354782771(/*Type c*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Type
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Type_m_IsSubclassOf0000: CIL_nop();
    System__Type_m_IsSubclassOf0001: CIL_newobj(System__NotImplementedException, mC78D8B7453D07999B003823809C964A5709EC8C6/* System.NotImplementedException::.ctor */);
    System__Type_m_IsSubclassOf0006: CIL_throw();
    CIL_ret();
}
/* System.Type::IsInstanceOfType */
char* m8FEAD892E91559B4B066AA112218678D0F7DC4E4_sig = "System.Type::IsInstanceOfType(Object o)";
void *m8FEAD892E91559B4B066AA112218678D0F7DC4E4(/*Object o*/) {
    uintptr_t parameter1 = pop_pointer();
    enum CIL_Type parameter1__type = CIL_pointer; // System.Object
    uintptr_t parameter0 = pop_pointer();
    enum CIL_Type parameter0__type = CIL_pointer;
    int entryStackSize = stack_size();
    int boundExceptions = 0;
    System__Type_m_IsInstanceOfType0000: CIL_nop();
    System__Type_m_IsInstanceOfType0001: CIL_newobj(System__NotImplementedException, mC78D8B7453D07999B003823809C964A5709EC8C6/* System.NotImplementedException::.ctor */);
    System__Type_m_IsInstanceOfType0006: CIL_throw();
    CIL_ret();
}
void init_mscorlib() {

}

