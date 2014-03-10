#define _CRT_SECURE_NO_WARNINGS

#include "opcodes.h"
#include "stack.h"
#include "hashmap.h"
#include "polyruntime.h"
#include <stdio.h>
#include <string.h>

void CIL_ldc__i4__s(int8_t s) { push_value32(s, CIL_int32); }
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

void CIL_conv__i4() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		// conversion to itself, do nothing
		return;
	}
	else if (type == CIL_float32) {
		int32_t v = pop_value32();
		float f;
		memcpy(&f, &v, 4);
		v = (int32_t)f;
		push_value32(v, CIL_int32);
		return;
	}
	else if (type == CIL_int64) {
		int64_t v = pop_value64();
		int32_t r = (int32_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		int32_t r = (int32_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		memcpy(&d, &v, 8);
		int32_t i = (int32_t)d;
		push_value32(i, CIL_int32);
		return;
	}
	fprintf(stderr, "Error: conv.i4 is not supported on operand");
}

void CIL_conv__i() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		intptr_t r = (intptr_t)v;
		push_pointer(r);
		return;
	}
	else if (type == CIL_float32) {
		int32_t v = pop_value32();
		float f;
		memcpy(&f, &v, 4);
		intptr_t r = (intptr_t)f;
		push_pointer(r);
		return;
	}
	else if (type == CIL_int64) {
		int64_t v = pop_value64();
		intptr_t r = (intptr_t)v;
		push_pointer(r);
		return;
	}
	else if (type == CIL_native) {
		// conversion to itself, do nothing
		return;
	}
	else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		memcpy(&d, &v, 8);
		intptr_t r = (intptr_t)d;
		push_pointer(r);
		return;
	}
	fprintf(stderr, "Error: conv.i4 is not supported on operand");
}

void CIL_conv__i1() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		int8_t r = (int8_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_float32) {
		int32_t v = pop_value32();
		float f;
		memcpy(&f, &v, 4);
		int8_t r = (int8_t)f;
		v = r;
		push_value32(v, CIL_int32);
		return;
	}
	else if (type == CIL_int64) {
		int64_t v = pop_value64();
		int32_t r = (int8_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		int32_t r = (int8_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		memcpy(&d, &v, 8);
		int8_t r = (int8_t)d;
		int32_t i = r;
		push_value32(i, CIL_int32);
		return;
	}
	fprintf(stderr, "Error: conv.i4 is not supported on operand");
}

void CIL_conv__i2() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		int16_t r = (int16_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_float32) {
		int32_t v = pop_value32();
		float f;
		memcpy(&f, &v, 4);
		int16_t r = (int16_t)f;
		v = r;
		push_value32(v, CIL_int32);
		return;
	}
	else if (type == CIL_int64) {
		int64_t v = pop_value64();
		int32_t r = (int16_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		int32_t r = (int16_t)v;
		push_value32(r, CIL_int32);
		return;
	}
	else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		memcpy(&d, &v, 8);
		int16_t r = (int16_t)d;
		int32_t i = r;
		push_value32(i, CIL_int32);
		return;
	}
	fprintf(stderr, "Error: conv.i4 is not supported on operand");
}

void CIL_conv__i8() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		int64_t r = (int64_t)v;
		push_value64(r, CIL_int64);
		return;
	}
	else if (type == CIL_float32) {
		int32_t v = pop_value32();
		float f;
		memcpy(&f, &v, 4);
		int64_t r = (int64_t)f;
		push_value64(r, CIL_int64);
		return;
	}
	else if (type == CIL_int64) {
		// conversion to itself, do nothing
		return;
	}
	else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		int64_t r = (int64_t)v;
		push_value64(r, CIL_int64);
		return;
	}
	else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		memcpy(&d, &v, 8);
		v = (intptr_t)d;
		push_value64(v, CIL_int64);
		return;
	}
	fprintf(stderr, "Error: conv.i4 is not supported on operand");
}

void CIL_conv__r4() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		float f = (float)v;
		memcpy(&v, &f, 4);
		push_value32(v, CIL_float32);
		return;
	}
	else if (type == CIL_float32) {
		// conversion to itself, do nothing
		return;
	}
	else if (type == CIL_int64) {
		int64_t v = pop_value64();
		float f = (float)v;
		int32_t r;
		memcpy(&r, &f, 4);
		push_value32(r, CIL_float32);
		return;
	}
	else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		float f = (float)v;
		int32_t r;
		memcpy(&r, &f, 4);
		push_value32(r, CIL_float32);
		return;
	}
	else if (type == CIL_float64) {
		int64_t v = pop_value64();
		double d;
		float f;
		int32_t r;
		memcpy(&d, &v, 8);
		f = (float)d;
		memcpy(&r, &f, 4);
		push_value32(r, CIL_float32);
		return;
	}
	fprintf(stderr, "Error: conv.r4 is not supported on operand");
}

void CIL_conv__r8() {
	enum CIL_Type type = stack_top_type();
	if (type == CIL_int32) {
		int32_t v = pop_value32();
		double f = (double)v;
		int64_t v2;
		memcpy(&v2, &f, 8);
		push_value64(v2, CIL_float64);
		return;
	}
	else if (type == CIL_float32) {
		int32_t v = pop_value32();
		double d;
		float f;
		int64_t r;
		memcpy(&f, &v, 4);
		d = f;
		memcpy(&r, &d, 8);
		push_value64(r, CIL_float64);
		return;
	}
	else if (type == CIL_int64) {
		int64_t v = pop_value64();
		double f = (double)v;
		memcpy(&v, &f, 8);
		push_value64(v, CIL_float64);
		return;
	}
	else if (type == CIL_native) {
		intptr_t v = pop_pointer();
		double d = (double)v;
		int64_t r;
		memcpy(&r, &d, 8);
		push_value64(r, CIL_float64);
		return;
	}
	else if (type == CIL_float64) {
		return;
	}
	fprintf(stderr, "Error: conv.r8 is not supported on operand");
}


int CIL_call_dispatch(void* (*func)()) {
	// TODO: callstack_push() should be only called from here
	//       We need to create a hashtable from function pointers to signature strings that this
	//       function can use to get the right signature.
	//       Now, the signature of the base class is displayed on virtual functions.
	int res = (int)func();
	return res;
}

int CIL_callvirt_dispatch(const char *symbol, unsigned int nparams, void* (*func)(), int isvirtual) {
	uintptr_t object;
	map_t symboltable;
	int ret;

	if (!isvirtual) { return CIL_call_dispatch(func); }

	object = peek_pointer(nparams);

	symboltable = *((map_t*)object);
	ret = hashmap_get(symboltable, symbol, (any_t*)&func);
	if (ret == MAP_MISSING) {
		fprintf(stderr, "Could not find symbol in symboltable!\n");
		exit(1);
	}
	return CIL_call_dispatch(func);
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

#define OPERATOR_INT(name, op) void CIL_ ## name () {\
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
}\
	fprintf(stderr, "Error: " #name " is not supported on these operands");\
}

OPERATOR(add, +);
OPERATOR(sub, -);
OPERATOR(mul, *);
OPERATOR(div, /);
OPERATOR_INT(rem, %);

/*
void CIL_ceq() {
int32_t value2 = pop_value32();
int32_t value1 = pop_value32();
if (value1 == value2) {
push_value32(1, CIL_int32);
}
else {
push_value32(0, CIL_int32);
}

// TODO: For floating-point numbers, ceq will return 0 if the numbers are unordered (either or both are NaN). The infinite values are equal to themselves.
}*/


#define COMPARER(name, op) void CIL_ ## name () {\
enum CIL_Type typeb = stack_top_type();\
	if (typeb == CIL_int32) {\
	int32_t b = pop_value32();\
enum CIL_Type typea = stack_top_type();\
	if (typea == CIL_int32) {\
	int32_t a = pop_value32();\
	push_value32(a op b ? 1 : 0, CIL_int32);\
	return;\
	} else if (typea == CIL_native) {\
	intptr_t a = pop_pointer();\
	push_value32(a op b ? 1 : 0, CIL_int32);\
	return;\
	}\
	} else if (typeb == CIL_int64) {\
	int64_t b = pop_value64();\
enum CIL_Type typea = stack_top_type();\
	if (typea == CIL_int64) {\
	int64_t a = pop_value64();\
	push_value32(a op b ? 1 : 0, CIL_int32);\
	return;\
	}\
	} else if (typeb == CIL_native) {\
	int32_t b = pop_value32();\
enum CIL_Type typea = stack_top_type();\
	if (typea == CIL_int32) {\
	int32_t a = pop_value32();\
	push_value32(a op b ? 1 : 0, CIL_int32);\
	return;\
	} else if (typea == CIL_native) {\
	intptr_t a = pop_pointer();\
	push_value32(a op b ? 1 : 0, CIL_int32);\
	return;\
	}\
} else if (typeb == CIL_float32) {\
	int32_t b = pop_value32();\
enum CIL_Type typea = stack_top_type();\
	float bf; memcpy(&bf, &b, 4);\
	if (typea == CIL_float32) {\
	int32_t a = pop_value32();\
	float af; memcpy(&af, &a, 4);\
	push_value32(af op bf ? 1 : 0, CIL_int32);\
	return;\
	}\
} else if (typeb == CIL_float64) {\
	int64_t b = pop_value64();\
enum CIL_Type typea = stack_top_type();\
	double bd; memcpy(&bd, &b, 8);\
	if (typea == CIL_float64) {\
	int64_t a = pop_value64();\
	double ad; memcpy(&ad, &a, 8);\
	push_value32(ad op bd ? 1 : 0, CIL_int32);\
	return;\
	}\
} else if (typeb == CIL_pointer) {\
	intptr_t b = pop_pointer();\
enum CIL_Type typea = stack_top_type();\
	if (typea == CIL_pointer) {\
	intptr_t a = pop_pointer();\
	push_value32(a op b ? 1 : 0, CIL_int32);\
	return;\
	}\
}\
	fprintf(stderr, "Error: " #name " is not supported on these operands");\
}

COMPARER(ceq, ==);
COMPARER(clt, <);
COMPARER(cgt, >);

#define UNARY_INT(name, op) void CIL_ ## name() { \
	enum CIL_Type type = stack_top_type(); \
	if (type == CIL_int32) { \
		int32_t v = pop_value32(); \
		v = op v; \
		push_value32(v, CIL_int32); \
		return; \
	} \
	else if (type == CIL_int64) { \
		int64_t v = pop_value64(); \
		v = op v; \
		push_value64(v, CIL_int64); \
		return; \
	} \
	else if (type == CIL_pointer) { \
		intptr_t v = pop_pointer(); \
		v = op v; \
		push_pointer(v); \
		return; \
	} \
	else if (type == CIL_native) { \
		intptr_t v = pop_pointer(); \
		v = op v; \
		push_pointer(v); \
		return; \
	} \
	fprintf(stderr, "Error: " #name " is not supported on these operands"); \
}

UNARY_INT(not, ~);
UNARY_INT(neg, -); // TODO: neg kan ook op float


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
	else if (strcmp(type, "System.Char") == 0) {
		struct SYSTEM__CHAR_proto *obj;
		int32_t val = pop_value32();
		CIL_newobj(SYSTEM__CHAR_proto, SYSTEM__CHAR_ctor);
		obj = (struct SYSTEM__CHAR_proto *)peek_pointer(0);
		obj->value = (uint16_t)val;
		return;
	}
	else {
		// box a valuetype
		return;
	}

	fprintf(stderr, "Error: Can not box to type %s!\n", type);
	exit(1);
}

void CIL_newarr_dispatch(const char* type) {
	/* TODO: Garbage collect */

	int32_t numElems = pop_value32();
	if (strcmp(type, "System.Int32") == 0 ||
		strcmp(type, "System.Byte") == 0 ||
		strcmp(type, "System.Int16") == 0 ||
		strcmp(type, "System.IntSByte") == 0 ||
		strcmp(type, "System.UInt16") == 0 ||
		strcmp(type, "System.Char") == 0 ||
		strcmp(type, "System.Short") == 0 ||
		strcmp(type, "System.UShort") == 0 ||
		strcmp(type, "System.UInt32") == 0 ||
		strcmp(type, "System.Boolean") == 0
		) {
		intptr_t arr = (intptr_t)calloc(numElems + 2, 4);
		((int32_t*)arr)[0] = numElems;
		((int32_t*)arr)[1] = 4; // size
		push_pointer(arr);
		return;
	}
	else if (strcmp(type, "System.Int64") == 0 ||
		strcmp(type, "System.UInt64") == 0 ||
		strcmp(type, "System.Long") == 0 ||
		strcmp(type, "System.ULong") == 0
		) {
		intptr_t arr = (intptr_t)calloc(numElems + 1, 8);
		((int32_t*)arr)[0] = numElems;
		((int32_t*)arr)[1] = 8; // size
		push_pointer(arr);
		return;
	}
	else if (strcmp(type, "System.Single") == 0) {
		intptr_t arr = (intptr_t)calloc(numElems + 2, 4);
		((int32_t*)arr)[0] = numElems;
		((int32_t*)arr)[1] = 4; // size
		push_pointer(arr);
		return;
	}
	else if (strcmp(type, "System.Double") == 0) {
		intptr_t arr = (intptr_t)calloc(numElems + 1, 8);
		((int32_t*)arr)[0] = numElems;
		((int32_t*)arr)[1] = 8; // size
		push_pointer(arr);
		return;
	}
	else {
		// Object
		intptr_t arr = (intptr_t)calloc(numElems + 2, sizeof(intptr_t));
		((int32_t*)arr)[0] = numElems;
		((int32_t*)arr)[1] = sizeof(intptr_t); // size
		push_pointer(arr);
		return;
	}

	// TODO: exception
	//fprintf(stderr, "Error: Can not create array of type %s!\n", type);
	//exit(1);
}

void CIL_stelem__i() {
	intptr_t value = pop_pointer();
	int32_t index = pop_value32() + 2;
	intptr_t* array = (intptr_t*)pop_pointer();
	array[index] = value;
}

void CIL_stelem__i4() {
	int32_t value = pop_value32();
	int32_t index = pop_value32() + 2;
	int32_t* array = (int32_t*)pop_pointer();
	array[index] = value;
}

void CIL_stelem__i1() { CIL_stelem__i4(); }
void CIL_stelem__i2() { CIL_stelem__i4(); }

void CIL_stelem__i8() {
	int64_t value = pop_value64();
	int32_t index = pop_value32() + 1;
	int64_t* array = (int64_t*)pop_pointer();
	array[index] = value;
}

void CIL_stelem__r4() {
	int32_t value = pop_value32();
	int32_t index = pop_value32() + 2;
	int32_t* array = (int32_t*)pop_pointer();
	array[index] = value;
}

void CIL_stelem__r8() {
	int64_t value = pop_value64();
	int32_t index = pop_value32() + 1;
	int64_t* array = (int64_t*)pop_pointer();
	array[index] = value;
}

void CIL_stelem__ref() {
	intptr_t value = pop_pointer();
	int32_t index = pop_value32() + 2;
	intptr_t* array = (intptr_t*)pop_pointer();
	array[index] = value;
}

void CIL_ldelem__i() {
	int32_t index = pop_value32() + 2;
	intptr_t* array = (intptr_t*)pop_pointer();
	push_pointer(array[index]);
}

void CIL_ldelem__i4() {
	int32_t index = pop_value32() + 2;
	int32_t* array = (int32_t*)pop_pointer();
	push_value32(array[index], CIL_int32);
}

void CIL_ldelem__i1() { CIL_ldelem__i4(); }
void CIL_ldelem__i2() { CIL_ldelem__i4(); }

void CIL_ldelem__i8() {
	int32_t index = pop_value32() + 1;
	int64_t* array = (int64_t*)pop_pointer();
	push_value64(array[index], CIL_int64);
}

void CIL_ldelem__r4() {
	int32_t index = pop_value32() + 2;
	int32_t* array = (int32_t*)pop_pointer();
	push_value32(array[index], CIL_float32);
}

void CIL_ldelem__r8() {
	int32_t index = pop_value32() + 1;
	int64_t* array = (int64_t*)pop_pointer();
	push_value64(array[index], CIL_float64);
}

void CIL_ldelem__ref() {
	int32_t index = pop_value32();
	intptr_t* array = (intptr_t*)pop_pointer();
	int32_t numElems = ((int32_t*)array)[0];
	if (index >= numElems) {
		fprintf(stderr, "System.IndexOutOfRangeException\n");
		exit(1);
	}
	push_pointer(array[index + 2]);
}

void CIL_ldelem__u1() { CIL_ldelem__i4(); }
void CIL_ldelem__u2() { CIL_ldelem__i4(); }
void CIL_ldelem__u4() { CIL_ldelem__i4(); }
void CIL_ldelem__u8() { CIL_ldelem__i8(); }

void CIL_ldelema_dispatch(const char* type) {
	if (strcmp(type, "System.Int32") == 0) {
		CIL_ldelem__i4();
		CIL_box_dispatch(type);
		return;
	}

	fprintf(stderr, "Error: ldelema: Can not load address of type %s!\n", type);
	exit(1);
}

void CIL_ldlen() {
	uintptr_t arr = pop_pointer();
	push_value32(((int32_t*)arr)[0], CIL_native);
}

void CIL_ldtoken_static_field_dispatch(void* addr, enum CIL_Type type, int size) {
	struct SYSTEM__RUNTIMEFIELDHANDLE_proto *obj;

	CIL_newobj(SYSTEM__RUNTIMEFIELDHANDLE_proto, SYSTEM__RUNTIMEFIELDHANDLE_ctor);
	obj = (struct SYSTEM__RUNTIMEFIELDHANDLE_proto *)peek_pointer(0);
	obj->addr = (intptr_t)addr;
	obj->type = type;
	obj->size = size;
}

int CIL_castclass_dispatch(const char* type) {
	uintptr_t obj = pop_pointer();
	if (object_is_type_or_subtype((struct SYSTEM__OBJECT_proto*)obj, type)) {
		push_pointer(obj);
		return 1;
	}
	else {
		return 0;
	}
}
