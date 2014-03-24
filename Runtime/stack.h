#pragma once 

#include <limits.h>
#include <stdint.h>
#include "runtime.h"

void push_value32(int32_t, enum CIL_Type type);
void push_value64(int64_t, enum CIL_Type type);
void push_pointer(uintptr_t);
void push_valuetypepointer(uintptr_t);
void push_arraypointer(uintptr_t);
int32_t pop_value32();
int64_t pop_value64();
uintptr_t pop_pointer();
void pop();
uintptr_t peek_pointer(unsigned int offset);
enum CIL_Type stack_top_type();
enum CIL_Type stack_offset_type(int offset);
int stack_top_size();
int empty();
int full();
int stack_size();
void print_stack();
void stack_duplicate_top();
void stack_shrink(int size);
int stack_top_type_is_integer();
int stack_top_type_is_float();

#if POLY_INTSIZE == 32
#define push_native(val) push_value32((int32_t)val, CIL_native)
#define pop_native() pop_value32()
#elif POLY_INTSIZE == 64
#define push_native(val) push_value64((int64_t)val, CIL_native)
#define pop_native() pop_value64()
#else
#error Only 32 and 64 bits integer sizes are supported
#endif