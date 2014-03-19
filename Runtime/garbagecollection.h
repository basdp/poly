#pragma once

#include "polyruntime.h"

void gc_init();
uintptr_t gc_alloc(size_t size);
void gc_new(uintptr_t obj);
void gc_new_arr(uintptr_t arr);
void gc_new_valuearray(uintptr_t arr);
void gc_retain(uintptr_t self, uintptr_t ref);
void gc_release(uintptr_t self, uintptr_t ref);
void gc_cycle();
void print_heap();
int heap_size();