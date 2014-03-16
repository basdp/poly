#include "runtime.h"
#include "stack.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cil_type_size(enum CIL_Type type) {
	switch (type) {
	case CIL_float32:
	case CIL_int32:
		return 4;
	case CIL_float64:
	case CIL_int64:
		return 8;
	case CIL_pointer:
	case CIL_native:
	case CIL_array:
		return sizeof(intptr_t);
	default: return 0;
	}
}

void push_default_value(enum CIL_Type type) {
	switch (type) {
	case CIL_float32:
	{
		int32_t v;
		float f = 0.0f;
		memcpy(&v, &f, 4);
		push_value32(v, CIL_float32);
		break;
	}
	case CIL_int32:
	{
		int32_t v = 0;
		push_value32(v, CIL_int32);
		break;
	}
	case CIL_float64:
	{
		int64_t v;
		double f = 0.0;
		memcpy(&v, &f, 8);
		push_value64(v, CIL_float64);
		break;
	}
	case CIL_int64:
	{
		int64_t v = 0;
		push_value64(v, CIL_int64);
		break;
	}
	case CIL_pointer:
	case CIL_native:
	{
		uintptr_t v = 0;
		push_pointer(v);
		break;
	}
	default:
		fprintf(stderr, "No default type for type id %d\n", type);
		exit(1);
	}
}

const char* cil_type_to_string(enum CIL_Type type) {
	switch (type) {
	case CIL_float32:
		return "CIL_float32";
	case CIL_int32:
		return "CIL_int32";
	case CIL_float64:
		return "CIL_float64";
	case CIL_int64:
		return "CIL_int64";
	case CIL_pointer:
		return "CIL_pointer";
	case CIL_native:
		return "CIL_native";
	case CIL_valuetype:
		return "CIL_valuetype";
	case CIL_array:
		return "CIL_array";
	default: 
		return "(unknown)";
	}
}