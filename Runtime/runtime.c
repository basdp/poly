#include "runtime.h"
#include <stdint.h>

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
		return sizeof(intptr_t);
	default: return 0;
	}
}