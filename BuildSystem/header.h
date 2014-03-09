#pragma once
#include "polyruntime.h"
#include "mscorlib.h"

// module C:\Users\Bas\Documents\GitHub\poly\BCL\mscorlib\bin\Debug\mscorlib.dll

// class System.__Object
struct System__Object {

    map_t __CILsymboltable;
    intptr_t __CILtype;
    intptr_t __CILbaseclasses;
    int* __CILbaseclasses_length;
    };
extern char* System__Object__baseclasses[1];
// class System.Attribute
struct System__Attribute {
  struct System__Object __base; // base class
};
extern char* System__Attribute__baseclasses[1];
// class System.Runtime.CompilerServices.RuntimeHelpers
struct System__Runtime__CompilerServices__RuntimeHelpers {
  struct System__Object __base; // base class
};
extern char* System__Runtime__CompilerServices__RuntimeHelpers__baseclasses[1];
// class mscorlib.System.RuntimeFieldHandle
struct mscorlib__System__RuntimeFieldHandle {
  struct System__Object __base; // base class
intptr_t addr;
    enum CIL_Type type;
    int size;};
extern char* mscorlib__System__RuntimeFieldHandle__baseclasses[1];
// class System.__Exception
struct System__Exception {
  struct System__Object __base; // base class
    uintptr_t _Message_k__BackingField; //67108868
    uintptr_t _HelpLink_k__BackingField; //67108869
    int32_t _HResult_k__BackingField; // 67108870
    uintptr_t _InnerException_k__BackingField; //67108871
    uintptr_t _Source_k__BackingField; //67108872
    uintptr_t _StackTrace_k__BackingField; //67108873
};
extern char* System__Exception__baseclasses[1];
extern enum CIL_Type System__Exception_f__Message_k__BackingField__type;
extern enum CIL_Type System__Exception_f__HelpLink_k__BackingField__type;
extern enum CIL_Type System__Exception_f__HResult_k__BackingField__type;
extern enum CIL_Type System__Exception_f__InnerException_k__BackingField__type;
extern enum CIL_Type System__Exception_f__Source_k__BackingField__type;
extern enum CIL_Type System__Exception_f__StackTrace_k__BackingField__type;
// class System.Console
struct System__Console {
  struct System__Object __base; // base class
};
extern char* System__Console__baseclasses[1];
// class System.__ValueType
struct System__ValueType {
  struct System__Object __base; // base class
};
extern char* System__ValueType__baseclasses[1];
// class System.__Int32
struct System__Int32 {
  struct System__ValueType __base; // base class
int32_t value;
    };
extern char* System__Int32__baseclasses[2];
// class System.__ArgumentOutOfRangeException
struct System__ArgumentOutOfRangeException {
  struct System__Exception __base; // base class
};
extern char* System__ArgumentOutOfRangeException__baseclasses[2];
// class System.__IndexOutOfRangeException
struct System__IndexOutOfRangeException {
  struct System__Exception __base; // base class
};
extern char* System__IndexOutOfRangeException__baseclasses[2];
// class System.__InvalidCastException
struct System__InvalidCastException {
  struct System__Exception __base; // base class
};
extern char* System__InvalidCastException__baseclasses[2];
// class System.__NullReferenceException
struct System__NullReferenceException {
  struct System__Exception __base; // base class
};
extern char* System__NullReferenceException__baseclasses[2];
// class System.__NotImplementedException
struct System__NotImplementedException {
  struct System__Exception __base; // base class
};
extern char* System__NotImplementedException__baseclasses[2];
// class System.Environment+StackFrame
struct System__Environment_plus_StackFrame {
  struct System__Object __base; // base class
    uintptr_t MethodSignature; //67108865
    uintptr_t FileName; //67108866
    int32_t LineNumber; // 67108867
};
extern char* System__Environment_plus_StackFrame__baseclasses[1];
extern enum CIL_Type System__Environment_plus_StackFrame_f_MethodSignature__type;
extern enum CIL_Type System__Environment_plus_StackFrame_f_FileName__type;
extern enum CIL_Type System__Environment_plus_StackFrame_f_LineNumber__type;
// class System.Environment
struct System__Environment {
  struct System__Object __base; // base class
};
extern char* System__Environment__baseclasses[1];
// class System.__String
struct System__String {
  struct System__Object __base; // base class
char *str;
    };
extern char* System__String__baseclasses[1];
// class System.Type
struct System__Type {
  struct System__Object __base; // base class
    uintptr_t _FullName_k__BackingField; //67108874
};
extern char* System__Type__baseclasses[1];
extern enum CIL_Type System__Type_f__FullName_k__BackingField__type;
/* System.__Object::.ctor */
extern char* m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16_sig;
void *m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16(/**/);
/* System.__Object::Equals */
extern char* mF028F029FE2B7E6C5FC6B76272F2F98668C649C8_sig;
void *mF028F029FE2B7E6C5FC6B76272F2F98668C649C8(/*__Object other*/);
/* System.__Object::Equals */
extern char* m27E26B2717630AA6745AA503DE9E1C9F9FC40636_sig;
void *m27E26B2717630AA6745AA503DE9E1C9F9FC40636(/*__Object objA, __Object objB*/);
/* System.__Object::Finalize */
extern char* m72555D2152F856160EF44D93DC781F86F5767954_sig;
void *m72555D2152F856160EF44D93DC781F86F5767954(/**/);
/* System.__Object::GetHashCode */
extern char* m8958E27C1CE11706E956EA94762D23FD80EB2F8F_sig;
void *m8958E27C1CE11706E956EA94762D23FD80EB2F8F(/**/);
/* System.__Object::GetType */
extern char* m3AD7669D6B5B2D33720E022E66E577E003E2D15A_sig;
void *m3AD7669D6B5B2D33720E022E66E577E003E2D15A(/**/);
/* System.__Object::ToString */
extern char* m8E6836504E6F32F58A5D7822EDF304BB4064BF64_sig;
void *m8E6836504E6F32F58A5D7822EDF304BB4064BF64(/**/);
/* System.Attribute::.ctor */
extern char* m457400C5C2A033444F6FEAAFAA62CCD633E19724_sig;
void *m457400C5C2A033444F6FEAAFAA62CCD633E19724(/**/);
/* System.Runtime.CompilerServices.RuntimeHelpers::.ctor */
extern char* mF7A8F0703658A1A7FF6559D6A1EC428B5660F7A1_sig;
void *mF7A8F0703658A1A7FF6559D6A1EC428B5660F7A1(/**/);
/* System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray */
extern char* mF717B9F9FA5F28945A1EBE020D1524839FD1CEA7_sig;
void *mF717B9F9FA5F28945A1EBE020D1524839FD1CEA7(/*Array array, RuntimeFieldHandle fldHandle*/);
/* mscorlib.System.RuntimeFieldHandle::.ctor */
extern char* m7531E3B8253211639BBBDB1FFB6E188D5A984775_sig;
void *m7531E3B8253211639BBBDB1FFB6E188D5A984775(/**/);
/* System.__Exception::.ctor */
extern char* mA204A1B81C060A79721F77F23E5FF39E07CC4694_sig;
void *mA204A1B81C060A79721F77F23E5FF39E07CC4694(/**/);
/* System.__Exception::.ctor */
extern char* m58A475D0E06559A6B627989B541434CB08FDE401_sig;
void *m58A475D0E06559A6B627989B541434CB08FDE401(/*String message*/);
/* System.__Exception::get_Message */
extern char* mDD5CE437ABC324313102D010746370FB55969A90_sig;
void *mDD5CE437ABC324313102D010746370FB55969A90(/**/);
/* System.__Exception::set_Message */
extern char* m662483F326D57E806173A0B8FCD9E10806774771_sig;
void *m662483F326D57E806173A0B8FCD9E10806774771(/*String value*/);
/* System.__Exception::get_HelpLink */
extern char* mC68F08BE35DE057468F1E4DC2E7DAD594708A9EA_sig;
void *mC68F08BE35DE057468F1E4DC2E7DAD594708A9EA(/**/);
/* System.__Exception::set_HelpLink */
extern char* m650102E40BCCFFF3B2463C77BFC562FFCBB9CD3A_sig;
void *m650102E40BCCFFF3B2463C77BFC562FFCBB9CD3A(/*String value*/);
/* System.__Exception::get_HResult */
extern char* mAAF13984F5105EAB0DE2D7CCEB9F7697F2FE67DD_sig;
void *mAAF13984F5105EAB0DE2D7CCEB9F7697F2FE67DD(/**/);
/* System.__Exception::set_HResult */
extern char* mFBE07AB8CABDC02BD80CEF1F1D663245FCEA87C7_sig;
void *mFBE07AB8CABDC02BD80CEF1F1D663245FCEA87C7(/*Int32 value*/);
/* System.__Exception::get_InnerException */
extern char* m0B0A2C3A12F31A31801DB84E7D58F97D9B4B96B2_sig;
void *m0B0A2C3A12F31A31801DB84E7D58F97D9B4B96B2(/**/);
/* System.__Exception::set_InnerException */
extern char* m6AEE9E8EC7D23748CA053FB1C9190150EE840A44_sig;
void *m6AEE9E8EC7D23748CA053FB1C9190150EE840A44(/*Exception value*/);
/* System.__Exception::get_Source */
extern char* mA8467B0EF1F0ED7D48D7698A32C9BB1A6A4B238C_sig;
void *mA8467B0EF1F0ED7D48D7698A32C9BB1A6A4B238C(/**/);
/* System.__Exception::set_Source */
extern char* mD76AF19773C892624C3A7D71AA978FF555BCDC97_sig;
void *mD76AF19773C892624C3A7D71AA978FF555BCDC97(/*String value*/);
/* System.__Exception::get_StackTrace */
extern char* mD525625A51E554AA031B4066D3CC34122AD29034_sig;
void *mD525625A51E554AA031B4066D3CC34122AD29034(/**/);
/* System.__Exception::set_StackTrace */
extern char* m77F43EF82837B4FC5B60CC75673D3417EB42A884_sig;
void *m77F43EF82837B4FC5B60CC75673D3417EB42A884(/*String value*/);
/* System.__Exception::ToString */
extern char* mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218_sig;
void *mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218(/**/);
/* System.__Exception::InitStackTrace */
extern char* m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394_sig;
void *m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394(/**/);
/* System.Console::.ctor */
extern char* m9114210D44965BA5EEF18C24C0D9239D4BA05A49_sig;
void *m9114210D44965BA5EEF18C24C0D9239D4BA05A49(/**/);
/* System.Console::WriteLine */
extern char* m7B0E65808D2625E9D12D0A5E20CEBAAF2B17DF13_sig;
void *m7B0E65808D2625E9D12D0A5E20CEBAAF2B17DF13(/*Char value*/);
/* System.Console::WriteLine */
extern char* m7066EF1436C6E50530DE29D56356D6747108D4DB_sig;
void *m7066EF1436C6E50530DE29D56356D6747108D4DB(/*Int32 value*/);
/* System.Console::WriteLine */
extern char* mC813F1CF7B4486925218A3E432C87B902EEDCE78_sig;
void *mC813F1CF7B4486925218A3E432C87B902EEDCE78(/*Int64 value*/);
/* System.Console::WriteLine */
extern char* m14A3A560DE8F1AAF097AA8EE0B050C8E7A351957_sig;
void *m14A3A560DE8F1AAF097AA8EE0B050C8E7A351957(/*Byte value*/);
/* System.Console::WriteLine */
extern char* mEDF138FDB2788EDB35A1D6295E387C5BBB754328_sig;
void *mEDF138FDB2788EDB35A1D6295E387C5BBB754328(/*Single value*/);
/* System.Console::WriteLine */
extern char* m81A1558C8061A0DD195011465F8CB730FF4A5435_sig;
void *m81A1558C8061A0DD195011465F8CB730FF4A5435(/*Double value*/);
/* System.Console::WriteLine */
extern char* mFC01BFC69714BA2C4F851536872188F62958745F_sig;
void *mFC01BFC69714BA2C4F851536872188F62958745F(/*String value*/);
/* System.Console::WriteLine */
extern char* m089DC9679DF2FA6D9AC17ADC5052F3AF64480A5C_sig;
void *m089DC9679DF2FA6D9AC17ADC5052F3AF64480A5C(/*Object value*/);
/* System.__ValueType::.ctor */
extern char* mEDC8295D0100B7A05696604AA16180D59191E3E6_sig;
void *mEDC8295D0100B7A05696604AA16180D59191E3E6(/**/);
/* System.__Int32::.ctor */
extern char* mB8A04E0EDA8614F527912F78289CD1FF9D0A0F81_sig;
void *mB8A04E0EDA8614F527912F78289CD1FF9D0A0F81(/**/);
/* System.__Int32::ToString */
extern char* mD87E91119D536242CFBFE243F48FA984876D5163_sig;
void *mD87E91119D536242CFBFE243F48FA984876D5163(/**/);
/* System.__ArgumentOutOfRangeException::.ctor */
extern char* mD81A01BD2EAF4E0554E7E00022DA8393DA63979F_sig;
void *mD81A01BD2EAF4E0554E7E00022DA8393DA63979F(/**/);
/* System.__IndexOutOfRangeException::.ctor */
extern char* m3C46C87472BC1C0212B9B21367868D11FCC940BB_sig;
void *m3C46C87472BC1C0212B9B21367868D11FCC940BB(/**/);
/* System.__InvalidCastException::.ctor */
extern char* mB71A0D21D024AF44637A268806CE99358D389355_sig;
void *mB71A0D21D024AF44637A268806CE99358D389355(/**/);
/* System.__NullReferenceException::.ctor */
extern char* m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C_sig;
void *m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C(/**/);
/* System.__NotImplementedException::.ctor */
extern char* mC78D8B7453D07999B003823809C964A5709EC8C6_sig;
void *mC78D8B7453D07999B003823809C964A5709EC8C6(/**/);
/* System.Environment+StackFrame::.ctor */
extern char* mB60C279DD2E6FD1E17763B0A68D79B5B2154E850_sig;
void *mB60C279DD2E6FD1E17763B0A68D79B5B2154E850(/**/);
/* System.Environment::.ctor */
extern char* m9C2D6B8FFFDF6638C40874A9AA1FD4210D457DF4_sig;
void *m9C2D6B8FFFDF6638C40874A9AA1FD4210D457DF4(/**/);
/* System.Environment::get_StackTrace */
extern char* m71CD3EBF055D1B6753790AA34B603EC59C86F9FC_sig;
void *m71CD3EBF055D1B6753790AA34B603EC59C86F9FC(/**/);
/* System.Environment::GetStackFrame */
extern char* m9594737445D4A66937A33CB4CB57BF0B1E2357E2_sig;
void *m9594737445D4A66937A33CB4CB57BF0B1E2357E2(/*Int32 i*/);
/* System.Environment::GetStackFrameCount */
extern char* mC6D50132C91F883AA60D6019885C48D34BD7181E_sig;
void *mC6D50132C91F883AA60D6019885C48D34BD7181E(/**/);
/* System.Environment::GetStackFrameLineNumber */
extern char* m2CB1E7709800E970609D6D388B8644BE714956DC_sig;
void *m2CB1E7709800E970609D6D388B8644BE714956DC(/*Int32 i*/);
/* System.Environment::GetStackFrameMethodSignature */
extern char* m5F25EB0EB441F9DA75DEE2BA9BF909461A4FCC67_sig;
void *m5F25EB0EB441F9DA75DEE2BA9BF909461A4FCC67(/*Int32 i*/);
/* System.Environment::GetStackFrameFileName */
extern char* m9E05B7440A52783C51AC1F8E87E6D7E7E2E5208D_sig;
void *m9E05B7440A52783C51AC1F8E87E6D7E7E2E5208D(/*Int32 i*/);
/* System.Environment::PrintCallStack */
extern char* m70091ABF0A9B0C1D7D6EABD63867F1F8AE9C4312_sig;
void *m70091ABF0A9B0C1D7D6EABD63867F1F8AE9C4312(/**/);
/* System.Environment::GetStackTrace */
extern char* m04E907104A79434AA6772B59957D5D9B78CB2F1E_sig;
void *m04E907104A79434AA6772B59957D5D9B78CB2F1E(/**/);
/* System.__String::.ctor */
extern char* m8D858A38DA1EA05CB64209432DD7505A8FE82943_sig;
void *m8D858A38DA1EA05CB64209432DD7505A8FE82943(/**/);
/* System.__String::.ctor */
extern char* mEC086807E22379BAD6CFAFA38CE803A4A640AF12_sig;
void *mEC086807E22379BAD6CFAFA38CE803A4A640AF12(/*String str*/);
/* System.__String::Concat */
extern char* m5F35C1AA2625C561EEFA593979D885EB0763DC43_sig;
void *m5F35C1AA2625C561EEFA593979D885EB0763DC43(/*String str0, String str1*/);
/* System.__String::get_Length */
extern char* mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A_sig;
void *mE1ECD8FA68D3252ED348ED7BFCE8B484503FC33A(/**/);
/* System.__String::Concat */
extern char* m5E8E86CD8F17353D6D6BD4C2B993409013D4F70A_sig;
void *m5E8E86CD8F17353D6D6BD4C2B993409013D4F70A(/*Object arg0, Object arg1*/);
/* System.__String::Concat */
extern char* m8B053C291B7A1D3C3B910E700C4F9247C1E00320_sig;
void *m8B053C291B7A1D3C3B910E700C4F9247C1E00320(/*Object arg0, Object arg1, Object arg2*/);
/* System.__String::Concat */
extern char* mEBFE3FA5AAAF9A5D7F5D49848C36C3DDC4F6E1B4_sig;
void *mEBFE3FA5AAAF9A5D7F5D49848C36C3DDC4F6E1B4(/*String arg0, String arg1, String arg2*/);
/* System.__String::Concat */
extern char* m0FC9495B749D746A06DDED51E1B7DD5BFD159FD9_sig;
void *m0FC9495B749D746A06DDED51E1B7DD5BFD159FD9(/*Object arg0, Object arg1, Object arg2, Object arg3*/);
/* System.__String::Concat */
extern char* m6D004057DAB052B8C56F4E0C7BC60923AA5FE38D_sig;
void *m6D004057DAB052B8C56F4E0C7BC60923AA5FE38D(/*String arg0, String arg1, String arg2, String arg3*/);
/* System.__String::ToString */
extern char* m974A2FF1C77976DC2453909489D91994F089A011_sig;
void *m974A2FF1C77976DC2453909489D91994F089A011(/**/);
/* System.__String::op_Equality */
extern char* m16C5477951DBB9F934C87FF8ADC1C322F099E987_sig;
void *m16C5477951DBB9F934C87FF8ADC1C322F099E987(/*__String a, __String b*/);
/* System.__String::op_Inequality */
extern char* mCF1776B0CAD1B5A27DA229E0EF7FF5955A4EFF32_sig;
void *mCF1776B0CAD1B5A27DA229E0EF7FF5955A4EFF32(/*__String a, __String b*/);
/* System.__String::Equals */
extern char* mECE756C5FF4B4460FFCA6138BB624952680B8FD8_sig;
void *mECE756C5FF4B4460FFCA6138BB624952680B8FD8(/*__String other*/);
/* System.__String::Equals */
extern char* m21E134FA241A623E1403EB610DBBA2DEDF8EF2A8_sig;
void *m21E134FA241A623E1403EB610DBBA2DEDF8EF2A8(/*Object obj*/);
/* System.__String::GetHashCode */
extern char* mA2B3CE0D9AEA66CFE1F24C3B5FC23A13A5280D5B_sig;
void *mA2B3CE0D9AEA66CFE1F24C3B5FC23A13A5280D5B(/**/);
/* System.__String::IndexOf */
extern char* m9080C0A7B04E806CF0B2B4731605A21E78F85C82_sig;
void *m9080C0A7B04E806CF0B2B4731605A21E78F85C82(/*String str*/);
/* System.__String::IndexOf */
extern char* m0629A285D432E6C3793ADCFE36AD0DA2956BD074_sig;
void *m0629A285D432E6C3793ADCFE36AD0DA2956BD074(/*Char c*/);
/* System.__String::Substring */
extern char* m35DD150503CB22A5AC8E05A5A6785912945CF6D8_sig;
void *m35DD150503CB22A5AC8E05A5A6785912945CF6D8(/*Int32 start*/);
/* System.__String::Substring */
extern char* m45AA36C8D31BBDDFDD56C822F9789F490B4A4E17_sig;
void *m45AA36C8D31BBDDFDD56C822F9789F490B4A4E17(/*Int32 start, Int32 length*/);
/* System.__String::get_Chars */
extern char* mC23D93FF06232BC655DEE27F7F6F9D7E71B35491_sig;
void *mC23D93FF06232BC655DEE27F7F6F9D7E71B35491(/*Int32 i*/);
/* System.Type::.ctor */
extern char* mCBE8D294E24BA0AFAB3C8B977360892A2BD95CC8_sig;
void *mCBE8D294E24BA0AFAB3C8B977360892A2BD95CC8(/*String fullName*/);
/* System.Type::get_FullName */
extern char* m615E6B2B0668333A85B347BF17D5E0A60CBE3B53_sig;
void *m615E6B2B0668333A85B347BF17D5E0A60CBE3B53(/**/);
/* System.Type::set_FullName */
extern char* m7782966344AAB1DE5CEF6BB9C206CBAB76F71903_sig;
void *m7782966344AAB1DE5CEF6BB9C206CBAB76F71903(/*String value*/);
/* System.Type::Equals */
extern char* m6CA9ADDD9E00004369D8E55E354A2CAB80071BE7_sig;
void *m6CA9ADDD9E00004369D8E55E354A2CAB80071BE7(/*Type other*/);
/* System.Type::IsSubclassOf */
extern char* m471812BAA2AA3BC55129B509A2F1EE2354782771_sig;
void *m471812BAA2AA3BC55129B509A2F1EE2354782771(/*Type c*/);
/* System.Type::IsInstanceOfType */
extern char* m8FEAD892E91559B4B066AA112218678D0F7DC4E4_sig;
void *m8FEAD892E91559B4B066AA112218678D0F7DC4E4(/*Object o*/);
