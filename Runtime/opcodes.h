#pragma once

#include "runtime.h"
#include "stdint.h"
#include "stack.h"
#include "hashmap.h"
#include "exceptions.h"
#include "garbagecollection.h"
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

#define CIL_call_unsafe(func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	CIL_call_dispatch(&func);\
}

#define CIL_call_base(ptr, func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	int res = CIL_call_base_dispatch(ptr, &func);\
	if (res == 1) {\
	/* exception has been thrown*/\
	if (DEBUG_EXCEPTIONS) { printf("Func " #func " threw an exception\n"); }\
	exception_throw_withInitStackTrace(0);\
	}\
}

#define CIL_call_generic(base_typelist_length, base_typelist, func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	int res = CIL_call_generic_dispatch(base_typelist_length, base_typelist, &func);\
	if (res == 1) {\
	/* exception has been thrown*/\
	if (DEBUG_EXCEPTIONS) { printf("Func " #func " threw an exception\n"); }\
	exception_throw_withInitStackTrace(0);\
	}\
}

#define CIL_call_generic_ctor(base_typelist_length, base_typelist, func, name, nparams, isvirtual) {\
	callstack_push(func ## _sig, "(unknown)", 0);\
	int res = CIL_call_generic_ctor_dispatch(base_typelist_length, base_typelist, &func);\
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
		} else if (res == 2) {\
			fprintf(stderr, __FILE__":%d\tError: a virtual function has not been found\n", __LINE__);\
			exit(1);\
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
int CIL_call_base_dispatch(uintptr_t, void* (*func)());
int CIL_call_generic_dispatch(int generictypelist_length, enum CIL_Type* generictypelist, void* (*func)(int, enum CIL_Type*));
int CIL_call_generic_ctor_dispatch(int generictypelist_length, enum CIL_Type* generictypelist, void* (*func)(int, enum CIL_Type*));

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

#define CIL_undefined() { fprintf(stderr, __FILE__":%d\tError: a CIL opcode has not been implemented\n", __LINE__); exit(44); }

#define CIL_add__ovf() CIL_undefined()
#define CIL_add__ovf__un() CIL_undefined()
#define CIL_and() CIL_undefined()
#define CIL_arglist() CIL_undefined()
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
#define CIL_jmp(...) CIL_undefined()
#define CIL_ldftn(...) CIL_undefined()
#define CIL_ldsflda(...) CIL_undefined()
#define CIL_ldvirtftn(...) CIL_undefined()
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
#define CIL_stobj(...) CIL_undefined()
#define CIL_sub__ovf(...) CIL_undefined()
#define CIL_sub__ovf__un(...) CIL_undefined()
#define CIL_switch(...) CIL_undefined()
#define CIL_xor(...) CIL_undefined()

#define CIL_nop() 
#define CIL_break() 
#define CIL_constrained__(type) // don't know for sure if this is okay to ignore in the Poly implementation...

#define CIL_br(label) goto label
#define CIL_blt(target) { CIL_clt(); CIL_brtrue(target); }
#define CIL_blt__s(target) CIL_blt(target)
#define CIL_beq(target) { CIL_ceq(); CIL_brtrue(target); }
#define CIL_beq__s(target) CIL_beq(target)

#define CIL_bge(target) { if (stack_top_type_is_float()) { CIL_clt__un(); CIL_brfalse(target); } else { CIL_clt(); CIL_brfalse(target); } }
#define CIL_bge__s(target) CIL_bge(target)
#define CIL_bge__un(target) { CIL_clt__un(); CIL_brfalse(target); }
#define CIL_bge__un__s(target) CIL_bge__un(target)
#define CIL_bgt(target) { CIL_cgt(); CIL_brtrue(target); }
#define CIL_bgt__s(target) CIL_bgt(target)
#define CIL_bgt__un(target) { CIL_cgt__un(); CIL_brtrue(target); }
#define CIL_bgt__un__s(target) CIL_bgt__un(target)
#define CIL_ble(target) { CIL_cgt(); CIL_brfalse(target); } // TODO: cgt.un if stack operands are floating point
#define CIL_ble__s(target) CIL_ble(target)
#define CIL_ble__un(target) { CIL_cgt(); CIL_brfalse(target); } // TODO: cgt if stack operands are floating point
#define CIL_ble__un__s(target) CIL_ble__un(target)
#define CIL_blt__un(target) { CIL_clt__un(); CIL_brtrue(target); }
#define CIL_blt__un__s(target) CIL_blt__un(target)

#define CIL_pop() pop()

#define CIL_ldfld(type, name) { intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } \
							else if (type ## _f_ ## name ## __type == CIL_array) { push_arraypointer((uintptr_t)(((struct type*)self)->name)); } \
							else if (type ## _f_ ## name ## __type == CIL_native) { push_native((int)(((struct type*)self)->name)); } \
							else if (sizeof(((struct type*)self)->  name) == 4) { push_value32( ((struct type*)self)-> name, type ## _f_ ## name ## __type ); }  \
							else if (sizeof(((struct type*)self)->  name) == 8) { push_value64( ((struct type*)self)-> name, type ## _f_ ## name ## __type ); }  \
							else if (type ## _f_ ## name ## __type == CIL_valuetype) { push_valuetypepointer((uintptr_t)&(((struct type*)self)-> name)); } \
							else { push_pointer((((struct type*)self)-> name)); } \
}

#define CIL_ldfld_valuetype(type, name) { intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } \
	push_valuetypepointer((uintptr_t)&(((struct type*)self)-> name)); \
}

#define CIL_ldfld_generic(type, name)  {intptr_t self = pop_pointer(); \
	if (self == 0) { throw_NullReferenceException(); } \
	enum CIL_Type t = ((struct type*)self)->name ## __type; \
	int ts = cil_type_size(t); \
	if (t == CIL_array) {\
	uintptr_t v; \
	memcpy(&v, (void*)&((struct type*)self)->name, sizeof(uintptr_t)); \
	push_arraypointer(v); \
	} else if (t == CIL_native) { \
		int v; \
		memcpy(&v, (void*)&((struct type*)self)->name, sizeof(int)); \
		push_native(v);\ \
	} else if (ts == 4) { \
		int32_t v; \
		memcpy(&v, (void*)&((struct type*)self)->name, 4); \
		push_value32(v, t);\
	} else if (ts == 8) {\
		int64_t v; \
		memcpy(&v, (void*)&((struct type*)self)->name, 8); \
		push_value64(v, t);\
	}\
	else {\
		if (t == CIL_valuetype) {\
			uintptr_t v;\
			memcpy(&v, (void*)&((struct type*)self)->name, sizeof(uintptr_t)); \
			push_valuetypepointer(v);\
		}\
		else {\
			fprintf(stderr, "CIL_ldfld_generic: value size is not 4 or 8??? %d\n", ts);\
			exit(1);\
		}\
	}\
}

#define CIL_ldflda(type, name) { intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } \
	 push_pointer((intptr_t)&(((struct type*)self)-> name)); \
}

#define CIL_stfld(type, name) { \
	uintptr_t self = peek_pointer(1); \
	if (self == 0) { throw_NullReferenceException(); } \
	CIL_stfld_dispatch(self, &(((struct type*)self)->name), sizeof(((struct type*)self)->name)); \
}
#define CIL_stfld_generic(type, name) { \
	uintptr_t self = peek_pointer(1); \
	if (self == 0) { throw_NullReferenceException(); } \
	CIL_stfld_generic_dispatch(self, &(((struct type*)self)->name), ((struct type*)self)->name ## __type); \
}
int CIL_stfld_dispatch(uintptr_t self, void* field, int size);
int CIL_stfld_generic_dispatch(uintptr_t, void*, enum CIL_Type);

/*#define CIL_stfld_old(type, name) { \
	if stack_top_size() == 4) { int32_t value = pop_value32(); intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } else ((struct type*)self)-> name = value; } \
	else if (stack_top_size() == 8) { int64_t value = pop_value64(); intptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } else ((struct type*)self)-> name = value; } \
	else if (type ## _sf_ ## name ## __type == CIL_valuetype) { push_valuetypepointer(&(((struct type*)self)->name)); } \
	else { intptr_t value = pop_pointer(); uintptr_t self = pop_pointer(); if (self == 0) { throw_NullReferenceException(); } else ((struct type*)self)-> name = value; } }*/

#define CIL_ldsfld(type, name) { type ## __cctor_init();  \
	if (type ## _sf_ ## name ## __type == CIL_array) { push_arraypointer((uintptr_t)&(type ## _sf_ ## name)); } \
	else if (cil_type_size(type ## _sf_ ## name ## __type) == 4) { push_value32( (type ## _sf_ ## name), (type ## _sf_ ## name ## __type) ); }  \
	else if (cil_type_size(type ## _sf_ ## name ## __type) == 8) { push_value64( (type ## _sf_ ## name), (type ## _sf_ ## name ## __type) ); }  \
	else if (type ## _sf_ ## name ## __type == CIL_valuetype) { push_valuetypepointer((uintptr_t)&(type ## _sf_ ## name)); } \
	else { push_pointer(type ## _sf_ ## name); } \
}

#define CIL_stsfld(type, name) { type ## __cctor_init();\
	if (stack_top_type() == CIL_pointer || stack_top_type() == CIL_array) { gc_retain(0, peek_pointer(0)); gc_release(0, type ## _sf_ ## name); } \
	if (stack_top_size() == 4) { int32_t value = pop_value32(); (type ## _sf_ ## name) = value; } \
	else if (stack_top_size() == 8) { int64_t value = pop_value64(); (type ## _sf_ ## name) = value; } \
	else if (stack_top_type() == CIL_valuetype) { intptr_t vt = pop_pointer(); memcpy(&(type ## _sf_ ## name), (void*)vt, sizeof(type ## _sf_ ## name)); } \
	else { intptr_t value = pop_pointer(); (type ## _sf_ ## name) = value; } }

#define CIL_ret() { \
	struct Node *gcNode = gcList.first;\
	while (gcNode != 0) { \
		gc_release(0, *(uintptr_t*)gcNode->ptr); \
		gcNode = gcNode->next; \
	}\
	linkedlist_free(&gcList); \
	callstack_pop(); \
	return 0; \
}

#define CIL_ldarg(n) {  \
	if (parameter ## n ## __type == CIL_array) { push_arraypointer((uintptr_t)(parameter ## n)); } \
	else if (cil_type_size(parameter ## n ## __type) == 4) push_value32((int32_t)parameter ## n, parameter ## n ## __type); \
	else if (cil_type_size(parameter ## n ## __type) == 8) push_value64((int64_t)parameter ## n, parameter ## n ## __type); \
	else if (parameter ## n ## __type == CIL_valuetype) { push_valuetypepointer((uintptr_t)&(parameter ## n)); } \
	else push_pointer((uintptr_t)parameter ## n); }

#define CIL_ldarg__0() CIL_ldarg(0)

#define CIL_ldarg__1() CIL_ldarg(1)

#define CIL_ldarg__2() CIL_ldarg(2)

#define CIL_ldarg__3() CIL_ldarg(3)

#define CIL_ldarg__s(s) CIL_ldarg(s)

#define CIL_ldarga(i) push_pointer((uintptr_t)&parameter ## i)
#define CIL_ldarga__s(i) CIL_ldarga(i)

#define CIL_starg(n) {  \
	if (stack_top_type() == CIL_pointer || stack_top_type() == CIL_array) { gc_retain(0, peek_pointer(0)); gc_release(0, (uintptr_t)parameter ## n); } \
	if (sizeof(parameter ## n) > 8 && parameter ## n ## __type == CIL_valuetype) { memcpy(&parameter ## n, (void*)pop_pointer(), sizeof(parameter ## n)); } \
	else if (parameter ## n ## __type == CIL_array) { uintptr_t *tmp = (uintptr_t*)&parameter ## n; *tmp = pop_pointer(); } \
	else if (cil_type_size(parameter ## n ## __type) == 4) { int32_t *tmp = (int32_t*)&parameter ## n; *tmp = pop_value32(); } \
	else if (cil_type_size(parameter ## n ## __type) == 8) { int64_t *tmp = (int64_t*)&parameter ## n; *tmp = pop_value64(); } \
	else if (parameter ## n ## __type == CIL_valuetype) { uintptr_t *tmp = (uintptr_t*)&parameter ## n; *tmp = pop_pointer(); } \
	else printf("starg: error\n"); }
#define CIL_starg__s(num) CIL_starg(num)

#define CIL_ldloc(n) { \
	if (sizeof(local ## n) > 8 && local ## n ## __type == CIL_valuetype) { uintptr_t v = (uintptr_t)malloc(sizeof(local ## n)); memcpy((void*)v, &local ## n, sizeof(local ## n)); push_valuetypepointer(v); } \
	else if (local ## n ## __type == CIL_array) { push_arraypointer((uintptr_t)local ## n); } \
	else if (cil_type_size(local ## n ## __type) == 4) { push_value32((int32_t)local ## n, local ## n ## __type); } \
	else if (cil_type_size(local ## n ## __type) == 8) { push_value64((int64_t)local ## n, local ## n ## __type); } \
	else if (local ## n ## __type == CIL_valuetype) { push_valuetypepointer((uintptr_t)local ## n); } \
	else { printf("ldloc: error\n"); } \
}

#define CIL_ldloc__0() CIL_ldloc(0)

#define CIL_ldloc__1() CIL_ldloc(1)

#define CIL_ldloc__2() CIL_ldloc(2)

#define CIL_ldloc__3() CIL_ldloc(3)

#define CIL_ldloc__s(s) CIL_ldloc(s)

#define CIL_ldloca(i) { \
	if (local ## i ## __type == CIL_pointer) {\
		push_pointer((uintptr_t)local ## i);\
	} else if (local ## i ## __type == CIL_array) { \
		push_arraypointer((uintptr_t)&local ## i);\
	} else if (local ## i ## __type == CIL_valuetype) { \
		push_valuetypepointer((uintptr_t)&local ## i);\
	} else { \
		push_pointer((uintptr_t)&local ## i);\
	} \
}

#define CIL_ldloca__s(i) CIL_ldloca(i)

#define CIL_stloc(n) { \
	if (stack_top_type() == CIL_pointer || stack_top_type() == CIL_array) { gc_retain(0, peek_pointer(0)); gc_release(0, (uintptr_t)local ## n); } \
	if (sizeof(local ## n) > 8 && local ## n ## __type == CIL_valuetype) { memcpy(&local ## n, (void*)pop_pointer(), sizeof(local ## n)); } \
	else if (local ## n ## __type == CIL_array) { uintptr_t *tmp = (uintptr_t*)&local ## n; *tmp = pop_pointer(); } \
	else if (cil_type_size(local ## n ## __type) == 4) { int32_t *tmp = (int32_t*)&local ## n; *tmp = pop_value32(); } \
	else if (cil_type_size(local ## n ## __type) == 8) { int64_t *tmp = (int64_t*)&local ## n; *tmp = pop_value64(); } \
	else if (local ## n ## __type == CIL_valuetype) { uintptr_t *tmp = (uintptr_t*)&local ## n; *tmp = pop_pointer(); } \
	else printf("stloc: error stloc\n"); }

#define CIL_stloc__0() CIL_stloc(0)

#define CIL_stloc__1() CIL_stloc(1)

#define CIL_stloc__2() CIL_stloc(2)

#define CIL_stloc__3() CIL_stloc(3)

#define CIL_stloc__s(s) CIL_stloc(s)


#define CIL_ldind__i() CIL_undefined()
#define CIL_ldind__i1() CIL_undefined()
#define CIL_ldind__i2() CIL_undefined()
#define CIL_ldind__i4() push_value32(*((int32_t*)pop_pointer()), CIL_int32)
#define CIL_ldind__i8() push_value64(*((int64_t*)pop_pointer()), CIL_int64)
#define CIL_ldind__r4() CIL_undefined()
#define CIL_ldind__r8() CIL_undefined()
#define CIL_ldind__ref() CIL_undefined()
#define CIL_ldind__u1() CIL_undefined()
#define CIL_ldind__u2() CIL_undefined()
#define CIL_ldind__u4() CIL_undefined()

#define CIL_stind__i() CIL_undefined()
#define CIL_stind__i1() CIL_undefined()
#define CIL_stind__i2() CIL_undefined()
#define CIL_stind__i4() { int32_t val = pop_value32(); *((int32_t*)pop_pointer()) = val; }
#define CIL_stind__i8() { int64_t val = pop_value64(); *((int64_t*)pop_pointer()) = val; }
#define CIL_stind__r4() CIL_undefined()
#define CIL_stind__r8() CIL_undefined()
#define CIL_stind__ref() CIL_undefined()


#define CIL_newobj(type, ctor) { \
	uintptr_t pointer = gc_alloc(sizeof(struct type)); \
	push_pointer(pointer); \
	callstack_push(ctor ## _sig, "(unknown)", 0);\
	ctor(); \
	gc_new(pointer); \
	push_pointer(pointer); \
} 

#define CIL_newobj_generic(type, ctor, typelist_length, typelist) { \
	uintptr_t pointer = gc_alloc(sizeof(struct type)); \
	push_pointer(pointer); \
	callstack_push(ctor ## _sig, "(unknown)", 0);\
	ctor(typelist_length, typelist); \
	gc_new(pointer); \
	push_pointer(pointer); \
} 

#define CIL_initobj(type) {\
	uintptr_t pointer = pop_pointer(); \
	/* TODO: Garbage collect */ \
	memset((void*)pointer, 0, sizeof(struct type));\
	push_pointer(pointer);\
	type ## __init();\
}

#define CIL_initobj_generic(type, typelist_length, typelist) {\
	uintptr_t pointer = pop_pointer(); \
	/* TODO: Garbage collect */ \
	memset((void*)pointer, 0, sizeof(struct type));\
	push_pointer(pointer);\
	type ## __init(typelist_length, typelist);\
}

#define CIL_box(type) CIL_box_dispatch(#type)
void CIL_box_dispatch(const char*);
#define CIL_box_ciltype(type) CIL_box_ciltype_dispatch(type)
void CIL_box_ciltype_dispatch(enum CIL_Type);
#define CIL_box_generic(type) CIL_box_generic_dispatch()
void CIL_box_generic_dispatch();

#define CIL_unbox_ciltype(type) wrap_exception_handling(CIL_unbox_ciltype_dispatch(type))
int CIL_unbox_ciltype_dispatch(enum CIL_Type);
#define CIL_unbox(type) wrap_exception_handling(CIL_unbox_dispatch(#type))
int CIL_unbox_dispatch(const char*);
#define CIL_unbox__any(type) { CIL_unbox(type); CIL_ldobj(type); }

#define CIL_ldobj(type) // do nothing (for now), as we do this under the hood

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

#define CIL_brtrue(target) { int value = pop_native(); if (value != 0) goto target; }
#define CIL_brtrue__s(target) CIL_brtrue(target)
#define CIL_brfalse(target) { int value = pop_native(); if (value == 0) goto target; }
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
#define CIL_leave(label) exception_leave(label)
#define CIL_leave__s(label) exception_leave(label)
#define CIL_endfinally() exception_endfinally()

#define CIL_castclass(type) { if (!CIL_castclass_dispatch(#type)) { throw_InvalidCastException(); } }
int CIL_castclass_dispatch(const char*);

#define CIL_isinst(type) CIL_isinst_dispatch(# type)
int CIL_isinst_dispatch(const char* type);
