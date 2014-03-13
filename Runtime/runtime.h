#pragma once

enum CIL_Type {
	//CIL_unknown,
	CIL_pointer,
	CIL_valuetype,
	//CIL_object,
	CIL_int32,
	CIL_int64,
	CIL_native,
	CIL_float32,
	CIL_float64
};

int cil_type_size(enum CIL_Type type);
void push_default_value(enum CIL_Type type);
