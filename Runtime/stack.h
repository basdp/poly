#pragma once 

#include "stdint.h"
#include "runtime.h"

void push_value32(int32_t, enum CIL_Type type);
void push_value64(int64_t, enum CIL_Type type);
void push_pointer(uintptr_t);
int32_t pop_value32();
int64_t pop_value64();
uintptr_t pop_pointer();
uintptr_t peek_pointer(unsigned int offset);
enum CIL_Type stack_top_type();
int stack_top_size();
int empty();
int full();
void print_stack();
void stack_duplicate_top();