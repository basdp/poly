#include "stack.h"
<<<<<<< HEAD
#include "polyruntime.h"
=======
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
#include <string.h>
#include <stdio.h>

#define MAXSTACK 1000
#define EMPTYSTACK 0
static int top = EMPTYSTACK;
static char items[MAXSTACK];
static int ttop = EMPTYSTACK;
static enum CIL_Type types[MAXSTACK];

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
			size = sizeof(intptr_t);
		} else if (types[ttop - i - 1] == CIL_pointer) {
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

enum CIL_Type stack_offset_type(int offset) {
	return types[ttop - 1 - offset];
}

int stack_top_size() {
	switch (stack_top_type()) {
	case CIL_float32:
	case CIL_int32:
		return 4;
	case CIL_float64:
	case CIL_int64:
		return 8;
	case CIL_pointer:
	case CIL_native:
		return sizeof(intptr_t);
	default: return 0;
	}
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
	case CIL_native: {
		intptr_t v = pop_pointer();
		push_pointer(v);
		push_pointer(v); }
		break;
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
			int64_t v = *((int64_t*)(items + t));
			printf("int64\t\t"); 
			printf("%i", v);
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
			printf("%f", d);
			t += sizeof(int64_t);
		}  else if (types[i] == CIL_native) {
			intptr_t v = *((intptr_t*)(items + t));
			printf("native\t\t"); 
			printf("%i", v);
			t += sizeof(intptr_t);
		} else if (types[i] == CIL_pointer) {
			intptr_t v = *((intptr_t*)(items + t));
			printf("pointer\t\t"); 
<<<<<<< HEAD
			printf("0x%x\t", v);
			printf("%s", ((struct SYSTEM__OBJECT_proto *)v)->__CILtype);
=======
			printf("0x%x", v);
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
			t += sizeof(intptr_t);
		}		 
		printf("\n");
	}
	printf("\n");
}
