#include "stdint.h"
#include "stack.h"
#include "hashmap.h"
#include "exceptions.h"
#include <stdlib.h>
#include <stdio.h>

#define CIL_call(func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	int res = CIL_call_dispatch(&func);\
	if (res == 1) {\
		/* exception has been thrown*/\
		if (DEBUG_EXCEPTIONS) { printf("Func " #func " threw an exception\n"); }\
		exception_throw_withInitStackTrace(0);\
	}\
}

#define CIL_callvirt(func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	intptr_t object = peek_pointer(nparams);\
	if (object == 0) { throw_NullReferenceException(); } else { \
		int res = CIL_callvirt_dispatch(name, nparams, &func, isvirtual);\
		if (res == 1) {\
			if (DEBUG_EXCEPTIONS) { printf("Func " name " threw an exception\n"); }\
			/* exception has been thrown*/\
			exception_throw_withInitStackTrace(0);\
		}\
	}\
}
#define CIL_callvirt_unsafe(func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	int res = CIL_callvirt_dispatch(name, nparams, &func, isvirtual);\
	if (res == 1) {\
		if (DEBUG_EXCEPTIONS) { printf("Unsafe func " name " threw an exception\n"); }\
		/* exception has been thrown */\
		exception_throw_withInitStackTrace(0);\
	}\
}
int CIL_call_dispatch(void* (*func)());
int CIL_callvirt_dispatch(const char *symbol, unsigned int nparams, void* (*func)(), int isvirtual);
void CIL_add();
void CIL_sub();
void CIL_div();
void CIL_mul();
void CIL_rem();

void CIL_ldc__i4__0();
void CIL_ldc__i4__1();
void CIL_ldc__i4__2();
void CIL_ldc__i4__3();
void CIL_ldc__i4__4();
void CIL_ldc__i4__5();
void CIL_ldc__i4__6();
void CIL_ldc__i4__7();
void CIL_ldc__i4__8();
void CIL_ldc__i4__m1();
void CIL_ldc__i4__M1();
void CIL_ldc__i4__s(int8_t);
void CIL_ldc__i4(int32_t);
void CIL_ldc__i8(int64_t);
void CIL_ldc__r4(float);
void CIL_ldc__r8(double);

void CIL_conv__i();
void CIL_conv__i1();
void CIL_conv__i2();
void CIL_conv__i8();
void CIL_conv__i4();

void CIL_conv__r4();
void CIL_conv__r8();

void CIL_ceq();
void CIL_clt();
void CIL_cgt();

void CIL_not();
void CIL_neg();

char *CIL_getCStringFromSystemString(intptr_t object);
void CIL_ldstr(const char*);

#define CIL_undefined() { fprintf(stderr, __FILE__":%d\tError: a CIL opcode has not been implemented\n", __LINE__); exit(404); }

#define CIL_add__ovf() CIL_undefined()
#define CIL_add__ovf__un() CIL_undefined()
#define CIL_and() CIL_undefined()
#define CIL_arglist() CIL_undefined()
#define CIL_beq(...) CIL_undefined()
#define CIL_beq__s(...) CIL_undefined()
#define CIL_bge__un(...) CIL_undefined()
#define CIL_bge__un__s(...) CIL_undefined()
#define CIL_bgt(...) CIL_undefined()
#define CIL_bgt__s(...) CIL_undefined()
#define CIL_bgt__un(...) CIL_undefined()
#define CIL_bgt__un__s(...) CIL_undefined()
#define CIL_ble(...) CIL_undefined()
#define CIL_ble__s(...) CIL_undefined()
#define CIL_ble__un(...) CIL_undefined()
#define CIL_ble__un__s(...) CIL_undefined()
#define CIL_blt(...) CIL_undefined()
#define CIL_blt__s(...) CIL_undefined()
#define CIL_blt__un(...) CIL_undefined()
#define CIL_blt__un__s(...) CIL_undefined()
#define CIL_bne(...) CIL_undefined()
#define CIL_bne__s(...) CIL_undefined()
#define CIL_brinst(...) CIL_undefined()
#define CIL_brinst__s(...) CIL_undefined()
#define CIL_calli(...) CIL_undefined()
#define CIL_castcall(...) CIL_undefined()
#define CIL_cgt__un(...) CIL_undefined()
#define CIL_ckfinite(...) CIL_undefined()
#define CIL_clt__un(...) CIL_undefined()
#define CIL_conv__ovf__i(...) CIL_undefined()
#define CIL_conv__ovf__i1(...) CIL_undefined()
#define CIL_conv__ovf__i2(...) CIL_undefined()
#define CIL_conv__ovf__i4(...) CIL_undefined()
#define CIL_conv__ovf__i8(...) CIL_undefined()
#define CIL_conv__ovf__i__un(...) CIL_undefined()
#define CIL_conv__ovf__i1__un(...) CIL_undefined()
#define CIL_conv__ovf__i2__un(...) CIL_undefined()
#define CIL_conv__ovf__i4__un(...) CIL_undefined()
#define CIL_conv__ovf__i8__un(...) CIL_undefined()
#define CIL_conv__u(...) CIL_undefined()
#define CIL_conv__u1(...) CIL_undefined()
#define CIL_conv__u2(...) CIL_undefined()
#define CIL_conv__u4(...) CIL_undefined()
#define CIL_conv__u8(...) CIL_undefined()
#define CIL_conv__ovf__u(...) CIL_undefined()
#define CIL_conv__ovf__u1(...) CIL_undefined()
#define CIL_conv__ovf__u2(...) CIL_undefined()
#define CIL_conv__ovf__u4(...) CIL_undefined()
#define CIL_conv__ovf__u8(...) CIL_undefined()
#define CIL_conv__ovf__u__un(...) CIL_undefined()
#define CIL_conv__ovf__u1__un(...) CIL_undefined()
#define CIL_conv__ovf__u2__un(...) CIL_undefined()
#define CIL_conv__ovf__u4__un(...) CIL_undefined()
#define CIL_conv__ovf__u8__un(...) CIL_undefined()
#define CIL_conv__r__un(...) CIL_undefined()
#define CIL_cpblk(...) CIL_undefined()
#define CIL_cpobj(...) CIL_undefined()
#define CIL_div__un(...) CIL_undefined()
#define CIL_endfault(...) CIL_undefined()
#define CIL_endfilter(...) CIL_undefined()
#define CIL_idind__u8(...) CIL_undefined()
#define CIL_initblk(...) CIL_undefined()
#define CIL_isinst(...) CIL_undefined()
#define CIL_jmp(...) CIL_undefined()
#define CIL_ldflda(...) CIL_undefined()
#define CIL_ldftn(...) CIL_undefined()
#define CIL_ldind__i(...) CIL_undefined()
#define CIL_ldind__i1(...) CIL_undefined()
#define CIL_ldind__i2(...) CIL_undefined()
#define CIL_ldind__i4(...) CIL_undefined()
#define CIL_ldind__i8(...) CIL_undefined()
#define CIL_ldind__r4(...) CIL_undefined()
#define CIL_ldind__r8(...) CIL_undefined()
#define CIL_ldind__ref(...) CIL_undefined()
#define CIL_ldind__u1(...) CIL_undefined()
#define CIL_ldind__u2(...) CIL_undefined()
#define CIL_ldind__u4(...) CIL_undefined()
#define CIL_ldobj(...) CIL_undefined()
#define CIL_ldsflda(...) CIL_undefined()
#define CIL_ldvirtftn(...) CIL_undefined()
#define CIL_leave(...) CIL_undefined()
#define CIL_localloc(...) CIL_undefined()
#define CIL_mkrefany(...) CIL_undefined()
#define CIL_mul__ovf(...) CIL_undefined()
#define CIL_mul__ovf__un(...) CIL_undefined()
#define CIL_no__typecheck(...) CIL_undefined()
#define CIL_no__rangecheck(...) CIL_undefined()
#define CIL_no__nullcheck(...) CIL_undefined()
#define CIL_or(...) CIL_undefined()
#define CIL_refanytype(...) CIL_undefined()
#define CIL_refanyval(...) CIL_undefined()
#define CIL_rem__un(...) CIL_undefined()
#define CIL_shl(...) CIL_undefined()
#define CIL_shr(...) CIL_undefined()
#define CIL_shr__un(...) CIL_undefined()
#define CIL_sizeof(...) CIL_undefined()
#define CIL_starg(...) CIL_undefined()
#define CIL_starg__s(...) CIL_undefined()
#define CIL_stind__i(...) CIL_undefined()
#define CIL_stind__i1(...) CIL_undefined()
#define CIL_stind__i2(...) CIL_undefined()
#define CIL_stind__i4(...) CIL_undefined()
#define CIL_stind__i8(...) CIL_undefined()
#define CIL_stind__r4(...) CIL_undefined()
#define CIL_stind__r8(...) CIL_undefined()
#define CIL_stind__ref(...) CIL_undefined()
#define CIL_stobj(...) CIL_undefined()
#define CIL_sub__ovf(...) CIL_undefined()
#define CIL_sub__ovf__un(...) CIL_undefined()
#define CIL_switch(...) CIL_undefined()
#define CIL_unbox(...) CIL_undefined()
#define CIL_unbox__any(...) CIL_undefined()
#define CIL_xor(...) CIL_undefined()

#define CIL_nop() 
#define CIL_break() 

#define CIL_br(label) goto label

#define CIL_pop() pop()

#define CIL_ldfld(type, name) { intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } \
	else if (sizeof(((struct type*)self)->  name) == 4) { push_value32( ((struct type*)self)-> name, type ## _f_ ## name ## __type ); }  \
							else if (sizeof(((struct type*)self)->  name) == 8) { push_value64( ((struct type*)self)-> name, type ## _f_ ## name ## __type ); }  \
							else { push_pointer((((struct type*)self)-> name)); } \
}

#define CIL_stfld(type, name) {    if (stack_top_size() == 4) { int32_t value = pop_value32(); intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } else ((struct type*)self)-> name = value; } \
				 else if (stack_top_size() == 8) { int64_t value = pop_value64(); intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } else ((struct type*)self)-> name = value; } \
				 else { intptr_t value = pop_pointer(); uintptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } else ((struct type*)self)-> name = value; } }

#define CIL_ldsfld(type, name) { type ## __cctor_init();  \
	            if (sizeof(type ## _sf_ ## name) == 4) { push_value32( (type ## _sf_ ## name), (type ## _sf_ ## name ## __type) ); }  \
				else if (sizeof(type ## _sf_ ## name) == 8) { push_value64( (type ## _sf_ ## name), (type ## _sf_ ## name ## __type) ); }  \
				else { push_pointer(type ## _sf_ ## name); } \
}

#define CIL_stsfld(type, name) { type ## __cctor_init();\
	            if (stack_top_size() == 4) { int32_t value = pop_value32(); (type ## _sf_ ## name) = value; } \
				else if (stack_top_size() == 8) { int64_t value = pop_value64(); (type ## _sf_ ## name) = value; } \
				else { intptr_t value = pop_pointer(); (type ## _sf_ ## name) = value; } }

#define CIL_ret() callstack_pop(); return 0;

#define CIL_ldarg(n) {    if (sizeof(parameter ## n) == 4) push_value32((int32_t)parameter ## n, parameter ## n ## __type); \
				 else if (sizeof(parameter ## n) == 8) push_value64((int64_t)parameter ## n, parameter ## n ## __type); \
				 else push_pointer((uintptr_t)parameter ## n); }

#define CIL_ldarg__0() CIL_ldarg(0)

#define CIL_ldarg__1() CIL_ldarg(1)

#define CIL_ldarg__2() CIL_ldarg(2)

#define CIL_ldarg__3() CIL_ldarg(3)

#define CIL_ldarg__s(s) CIL_ldarg(s)

#define CIL_ldarga(i) push_pointer((uintptr_t)&parameter ## i)
#define CIL_ldarga__s(i) CIL_ldarga(i)

#define CIL_ldloc(n) { if (local ## n ## __type == CIL_valuetype) { push_pointer((uintptr_t)&local ## n); } \
                 else if (sizeof(local ## n) == 4) push_value32((int32_t)local ## n, local ## n ## __type); \
				 else if (sizeof(local ## n) == 8) push_value64((int64_t)local ## n, local ## n ## __type); \
				 else printf("ldloc: error\n"); }

#define CIL_ldloc__0() CIL_ldloc(0)

#define CIL_ldloc__1() CIL_ldloc(1)

#define CIL_ldloc__2() CIL_ldloc(2)

#define CIL_ldloc__3() CIL_ldloc(3)

#define CIL_ldloc__s(s) CIL_ldloc(s)

#define CIL_ldloca(i) push_pointer((uintptr_t)&local ## i)
#define CIL_ldloca__s(i) CIL_ldloca(i)

#define CIL_stloc(n) { if (sizeof(local ## n) > 8 && local ## n ## __type == CIL_valuetype) { memcpy(&local ## 0, (void*)pop_pointer(), sizeof(local ## 0)); } \
                 else if (sizeof(local ## n) == 4) { int32_t *tmp = (int32_t*)&local ## n; *tmp = pop_value32(); } \
				 else if (sizeof(local ## n) == 8) { int64_t *tmp = (int64_t*)&local ## n; *tmp = pop_value64(); } \
				 else printf("stloc: error\n"); }

#define CIL_stloc__0() CIL_stloc(0)

#define CIL_stloc__1() CIL_stloc(1)

#define CIL_stloc__2() CIL_stloc(2)

#define CIL_stloc__3() CIL_stloc(3)

#define CIL_stloc__s(s) CIL_stloc(s)

#define CIL_newobj(type, ctor) { \
	void* pointer = calloc(1, sizeof(struct type)); \
	/* TODO: Garbage collect */ \
	push_pointer((uintptr_t)pointer); \
	callstack_push(ctor ## _sig, "(unknown)", 0);\
	ctor(); \
	push_pointer((uintptr_t)pointer); \
} 

#define CIL_initobj(type) {\
	uintptr_t pointer = pop_pointer(); \
	/* TODO: Garbage collect */ \
	memset((void*)pointer, 0, sizeof(struct type));\
	push_pointer(pointer);\
	type ## __init();\
}

#define CIL_box(type) CIL_box_dispatch(#type)
void CIL_box_dispatch(const char*);

#define CIL_newarr(type) CIL_newarr_dispatch(#type)
void CIL_newarr_dispatch(const char*);

#define CIL_stelem(...) CIL_undefined()
void CIL_stelem__i();
void CIL_stelem__i1();
void CIL_stelem__i2();
void CIL_stelem__i4();
void CIL_stelem__i8();
void CIL_stelem__r4();
void CIL_stelem__r8();
void CIL_stelem__ref();

#define CIL_ldelem(type) CIL_undefined() /* #type */
void CIL_ldelem__i(); 
void CIL_ldelem__i1();
void CIL_ldelem__i2();
void CIL_ldelem__i4();
void CIL_ldelem__i8();
void CIL_ldelem__r4();
void CIL_ldelem__r8();
void CIL_ldelem__ref();
void CIL_ldelem__u1();
void CIL_ldelem__u2();
void CIL_ldelem__u4();
void CIL_ldelem__u8();
#define CIL_ldelema(type) CIL_ldelema_dispatch(#type)
void CIL_ldelema_dispatch(const char*);
void CIL_ldlen();

#define CIL_ldtoken(type, clas, id, offset, size) CIL_ldtoken_ ## type (clas, id, offset, size)

void CIL_ldtoken_static_field_dispatch(void*, enum CIL_Type, int);
#define CIL_ldtoken_static_field(clas, id, offset, size) CIL_ldtoken_static_field_dispatch(& (clas ## _sf_ ## id), clas ## _sf_ ## id ## __type, size)

#define CIL_dup() stack_duplicate_top()

// TODO: for 64 bit: should check the size of the top value on the stack for 64 bit
#define CIL_brtrue(target) { int32_t value = pop_value32(); if (value != 0) goto target; }
#define CIL_brtrue__s(target) CIL_brtrue(target)
#define CIL_brfalse(target) { int32_t value = pop_value32(); if (value == 0) goto target; }
#define CIL_brfalse__s(target) CIL_brfalse(target)
#define CIL_brnull(target) CIL_brfalse(target)
#define CIL_brnull__s(target) CIL_brfalse(target)
#define CIL_brzero(target) CIL_brfalse(target)
#define CIL_brzero__s(target) CIL_brfalse(target)
#define CIL_bne__un(target) { CIL_ceq(); CIL_brfalse(target); }
#define CIL_bne__un__s(target) CIL_bne__un(target)

#define CIL_ldnull(...) push_pointer(0)

//exceptions
#define CIL_throw() exception_throw()
#define CIL_rethrow(...) exception_rethrow()
#define CIL_leave__s(label) exception_leave(label)
#define CIL_endfinally() exception_endfinally()

#define CIL_castclass(type) { if (!CIL_castclass_dispatch(#type)) { throw_InvalidCastException(); } }
int CIL_castclass_dispatch(const char*);