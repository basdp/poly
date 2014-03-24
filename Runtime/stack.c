#include "stack.h"
#include "polyruntime.h"
#include <string.h>
#include <stdio.h>

#define MAXSTACK 1000
#define EMPTYSTACK 0
static int top = EMPTYSTACK;
static char items[MAXSTACK];
static int ttop = EMPTYSTACK;
static enum CIL_Type types[MAXSTACK];

// TODO: checks on push and pop for size of type

void push_value32(int32_t c, enum CIL_Type type) {
	memcpy(items + top, &c, 4);
	top += 4;
	types[ttop++] = type;
}

void push_value64(int64_t c, enum CIL_Type type) {
	memcpy(items + top, &c, 8);
	top += 8;
	types[ttop++] = type;
}

void push_pointer(uintptr_t c) {
	memcpy(items + top, &c, sizeof(uintptr_t));
	top += sizeof(uintptr_t);
	types[ttop++] = CIL_pointer;
}

void push_valuetypepointer(uintptr_t c) {
	memcpy(items + top, &c, sizeof(uintptr_t));
	top += sizeof(uintptr_t);
	types[ttop++] = CIL_valuetype;
}

void push_arraypointer(uintptr_t c) {
	memcpy(items + top, &c, sizeof(uintptr_t));
	top += sizeof(uintptr_t);
	types[ttop++] = CIL_array;
}

int32_t pop_value32() {
	int32_t r = *((int32_t*)(items + top - sizeof(int32_t)));
	top -= 4;
	ttop--;
	return r;
}

int64_t pop_value64() {
	int64_t r = *((int64_t*)(items + top - sizeof(int64_t)));
	top -= 8;
	ttop--;
	return r;
}

uintptr_t pop_pointer() {
	uintptr_t r = *((uintptr_t*)(items + top - sizeof(uintptr_t)));
	top -= sizeof(uintptr_t);
	ttop--;
	return r;
}

void pop() {
	top -= stack_top_size();
	ttop--;
}

extern void exit(int);
void stack_shrink(int size) {
	if (ttop < size) {
		// TODO: exception
		printf("stack_shrink: %d is bigger than the current stack size (%d)\n", size, top);
		exit(1);
	}
	while (ttop > size) pop();
}

uintptr_t peek_pointer(unsigned int offset) {
	unsigned int t, i;
	uintptr_t r;
	t = top;
	for (i = 0; i <= offset; i++) {
		int size = 0;
		if (types[ttop - i - 1] == CIL_int32) {
			size = 4;
		} else if (types[ttop - i - 1] == CIL_int64) {
			size = 8;
		} else if (types[ttop - i - 1] == CIL_native) {
			size = sizeof(int);
		} else if (types[ttop - i - 1] == CIL_pointer) {
			size = sizeof(intptr_t);
		} else if (types[ttop - i - 1] == CIL_valuetype) {
			size = sizeof(intptr_t);
		} else if (types[ttop - i - 1] == CIL_array) {
			size = sizeof(intptr_t);
		} else if (types[ttop - i - 1] == CIL_float32) {
			size = 4;
		} else if (types[ttop - i - 1] == CIL_float64) {
			size = 8;
		}
		t -= size;	
	}
	r = *((uintptr_t*)(items + t));
	return r;
}

enum CIL_Type stack_top_type() {
	return types[ttop - 1];
}

int stack_top_type_is_float() {
	enum CIL_Type stt = stack_top_type();
	if (stt == CIL_float32) return 1;
	if (stt == CIL_float64) return 1;
	return 0;
}

int stack_top_type_is_integer() {
	enum CIL_Type stt = stack_top_type();
	if (stt == CIL_int32) return 1;
	if (stt == CIL_int64) return 1;
	if (stt == CIL_native) return 1;
	return 0;
}

enum CIL_Type stack_offset_type(int offset) {
	return types[ttop - 1 - offset];
}

int stack_top_size() {
	return (cil_type_size(stack_top_type()));
}

void stack_duplicate_top() {
	enum CIL_Type top_type = stack_top_type();
	switch (top_type) {
	case CIL_float32:
	case CIL_int32: {
		int32_t v = pop_value32();
		push_value32(v, top_type);
		push_value32(v, top_type); }
		break;
	case CIL_float64:
	case CIL_int64: {
		int64_t v = pop_value64();
		push_value64(v, top_type);
		push_value64(v, top_type); }
		break;
	case CIL_pointer:
	case CIL_valuetype:
	case CIL_array: {
		intptr_t v = pop_pointer();
		push_pointer(v);
		push_pointer(v); }
		break;

	case CIL_native: {
			int v = pop_native();
			push_native(v);
			push_native(v);
		}
	}
}

int full()  {
	return top+1 >= MAXSTACK;
}

int empty()  {
	return top <= EMPTYSTACK;
}

int stack_size() {
	return ttop;
}

void print_stack() {
	int t = 0;
	int i;
	printf("Stack: (size: %d)\n", top);
	for (i = 0; i < ttop; i++) {
		int size = 0;
		printf("%d\t", i);
		if (types[i] == CIL_int32) {
			int32_t v = *((int32_t*)(items + t));
			printf("int32\t\t");
			printf("%i", v);
			t += sizeof(int32_t);
		} else if (types[i] == CIL_int64) {
			long long int v = *((int64_t*)(items + t));
			printf("int64\t\t"); 
			printf("%lld", v);
			t += sizeof(int64_t);
		}  else if (types[i] == CIL_float32) {
			int32_t v = *((int32_t*)(items + t));
			float f;
			memcpy(&f, &v, 4);
			printf("float32\t\t"); 
			printf("%f", f);
			t += sizeof(int32_t);
		}  else if (types[i] == CIL_float64) {
			int64_t v = *((int64_t*)(items + t));
			double d;
			memcpy(&d, &v, 8);
			printf("float64\t\t"); 
			printf("%.14f", d);
			t += sizeof(int64_t);
		}  else if (types[i] == CIL_native) {
			int v = *((int*)(items + t));
			printf("native\t\t"); 
			printf("%i", v);
			t += sizeof(int);
		} else if (types[i] == CIL_pointer) {
			intptr_t v = *((intptr_t*)(items + t));
			unsigned int vi = (unsigned int)v;
			printf("pointer\t\t");
			printf("0x%x\t", vi);
			/*if (v != 0) {
				printf("%s", (char*)((struct SYSTEM__OBJECT_proto *)v)->__CILtype);
			}*/
			t += sizeof(intptr_t);
		} else if (types[i] == CIL_valuetype) {
			intptr_t v = *((intptr_t*)(items + t));
			unsigned int vi = (unsigned int)v;
			printf("value type\t"); 
			printf("0x%x\t", vi);
			printf("%s", (char*)((struct SYSTEM__OBJECT_proto *)v)->__CILtype);
			t += sizeof(intptr_t);
		} else if (types[i] == CIL_array) {
			intptr_t v = *((intptr_t*)(items + t));
			unsigned int vi = (unsigned int)v;
			printf("array\t\t"); 
			printf("0x%x\t", vi);
			int32_t len = ((int32_t*)v)[0];
			printf("length: %d", len);
			t += sizeof(intptr_t);
		}
		printf("\n");
	}
	printf("\n");
}
