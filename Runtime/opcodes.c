#include "opcodes.h"
#include "stack.h"
#include "hashmap.h"
#include "polyruntime.h"
#include <stdio.h>
#include <string.h>

void CIL_ldc__i4__s(int8_t s) {	push_value32(s, CIL_int32); }
void CIL_ldc__i4__0() { push_value32(0, CIL_int32); }
void CIL_ldc__i4__1() { push_value32(1, CIL_int32); }
void CIL_ldc__i4__2() { push_value32(2, CIL_int32); }
void CIL_ldc__i4__3() { push_value32(3, CIL_int32); }
void CIL_ldc__i4__4() { push_value32(4, CIL_int32); }
void CIL_ldc__i4__5() { push_value32(5, CIL_int32); }
void CIL_ldc__i4__6() { push_value32(6, CIL_int32); }
void CIL_ldc__i4__7() { push_value32(7, CIL_int32); }
void CIL_ldc__i4__8() { push_value32(8, CIL_int32); }
void CIL_ldc__i4__m1() { push_value32(-1, CIL_int32); }
void CIL_ldc__i4__M1() { push_value32(-1, CIL_int32); }
void CIL_ldc__i4(int32_t i) { push_value32(i, CIL_int32); }
void CIL_ldc__i8(int64_t i) { push_value64(i, CIL_int64); }
void CIL_ldc__r4(float f) { int32_t v; memcpy(&v, &f, 4); push_value32(v, CIL_float32); }
void CIL_ldc__r8(double d) { int64_t v; memcpy(&v, &d, 8); push_value64(v, CIL_float64); }

void CIL_conv__r4() { 
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		float f = v;
		memcpy(&v, &f, 4);
		push_value32(v, CIL_float32);
		return;
	} else if (type == CIL_float32) {
		// conversion to itself, do nothing
		return;
	} else if (type == CIL_int64) {
		int64_t v = pop_value64();
		float f = v;
		int32_t r;
		memcpy(&r, &f, 4);
		push_value32(r, CIL_float32);
		return;
	} else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		float f = v;
		int32_t r;
		memcpy(&r, &f, 4);
		push_value32(r, CIL_float32);
		return;
	} else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		float f;
		int32_t r;
		memcpy(&d, &v, 8);
		f = d;
		memcpy(&r, &f, 4);
		push_value32(r, CIL_float32);
		return;
	}
	fprintf(stderr, "Error: conv.r4 is not supported on operand");
}

void CIL_call_dispatch(void* (*func)()) {
	func();
}

void CIL_callvirt_dispatch(const char *symbol, unsigned int nparams, void* (*func)(), int isvirtual) {
	uintptr_t object; 
	map_t symboltable;
	int ret;

	if (!isvirtual) { func(); return; }

	object = peek_pointer(nparams);
	symboltable = *((map_t*)object);
	ret = hashmap_get(symboltable, symbol, (any_t*)&func);
	if (ret == MAP_MISSING) {
		fprintf(stderr, "Could not find symbol in symboltable!\n");
		exit(1);
	}
	func();
}

#define OPERATOR(name, op) void CIL_ ## name () {\
	enum CIL_Type typeb = stack_top_type();\
	if (typeb == CIL_int32) {\
		int32_t b = pop_value32();\
		enum CIL_Type typea = stack_top_type();\
		if (typea == CIL_int32) {\
			int32_t a = pop_value32();\
			push_value32(a op b, CIL_int32);\
			return;\
		} else if (typea == CIL_native) {\
			intptr_t a = pop_pointer();\
			push_pointer(a op b);\
			return;\
		}\
	} else if (typeb == CIL_int64) {\
		int64_t b = pop_value64();\
		enum CIL_Type typea = stack_top_type();\
		if (typea == CIL_int64) {\
			int64_t a = pop_value64();\
			push_value64(a op b, CIL_int64);\
			return;\
		}\
	} else if (typeb == CIL_native) {\
		int32_t b = pop_value32();\
		enum CIL_Type typea = stack_top_type();\
		if (typea == CIL_int32) {\
			int32_t a = pop_value32();\
			push_pointer(a op b);\
			return;\
		} else if (typea == CIL_native) {\
			intptr_t a = pop_pointer();\
			push_pointer(a op b);\
			return;\
		}\
	} else if (typeb == CIL_float32) {\
		int32_t b = pop_value32();\
		enum CIL_Type typea = stack_top_type();\
		float bf; memcpy(&bf, &b, 4);\
		if (typea == CIL_float32) {\
			int32_t a = pop_value32();\
			float af; memcpy(&af, &a, 4);\
			af = af op bf;\
			memcpy(&a, &af, 4);\
			push_value32(a, CIL_float32);\
			return;\
		}\
	} else if (typeb == CIL_float64) {\
		int64_t b = pop_value64();\
		enum CIL_Type typea = stack_top_type();\
		double bd; memcpy(&bd, &b, 8);\
		if (typea == CIL_float64) {\
			int64_t a = pop_value64();\
			double ad; memcpy(&ad, &a, 8);\
			ad = ad op bd;\
			memcpy(&a, &ad, 8);\
			push_value64(a, CIL_float64);\
			return;\
		}\
	}\
	fprintf(stderr, "Error: " #name " is not supported on these operands");\
}

OPERATOR(add, +);
OPERATOR(sub, -);
OPERATOR(mul, *);
OPERATOR(div, /);

void CIL_ceq() {
	int32_t value2 = pop_value32();
	int32_t value1 = pop_value32();
	if (value1 == value2) {
		push_value32(1, CIL_int32);
	} else {
		push_value32(0, CIL_int32);
	}

	// TODO: For floating-point numbers, ceq will return 0 if the numbers are unordered (either or both are NaN). The infinite values are equal to themselves. 
}

void CIL_ldstr(const char* str) {
	struct SYSTEM__STRING_proto *strobj;
	CIL_newobj(SYSTEM__STRING_proto, SYSTEM__STRING_ctor);
	strobj = (struct SYSTEM__STRING_proto *)peek_pointer(0);
	strobj->str = (char*)malloc(strlen(str) + 1);
	strcpy(strobj->str, str);
}

char *CIL_getCStringFromSystemString(intptr_t object) {
	struct SYSTEM__STRING_proto *strobj = (struct SYSTEM__STRING_proto*)object;
	return strobj->str;
}

void CIL_box_dispatch(const char* type) {
	if (strcmp(type, "System.Int32") == 0) {
		struct SYSTEM__INT32_proto *obj;
		int32_t val = pop_value32();
		CIL_newobj(SYSTEM__INT32_proto, SYSTEM__INT32_ctor);
		obj = (struct SYSTEM__INT32_proto *)peek_pointer(0);
		obj->value = val;
		return;
	}

	fprintf(stderr, "Error: Can not box to type %s!\n", type);
	exit(1);
}