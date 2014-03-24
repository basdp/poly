#pragma once

#include <limits.h>
#include <stdint.h>

enum CIL_Type {
	//CIL_unknown,
	CIL_pointer,
	CIL_valuetype,
	//CIL_object,
	CIL_int32,
	CIL_int64,
	CIL_native,
	CIL_float32,
	CIL_float64,
	CIL_array
};

int cil_type_size(enum CIL_Type type);
void push_default_value(enum CIL_Type type);
const char* cil_type_to_string(enum CIL_Type type);

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define POLY64
#else
#define POLY32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define POLY64
#else
#define POLY32
#endif
#endif

#if UINT_MAX == UINT16_MAX
#define POLY_INTSIZE 16
#elif UINT_MAX == UINT32_MAX
#define POLY_INTSIZE 32
#elif UINT_MAX == UINT64_MAX
#define POLY_INTSIZE 64
#else
#define POLY_INTSIZE 0
#endif
