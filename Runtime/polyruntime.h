#pragma once
#include "hashmap.h"
#include "opcodes.h"

struct SYSTEM__OBJECT_proto {
	map_t __CILsymboltable;
	intptr_t __CILtype;
};

#define SYSTEM__STRING_ctor m8D858A38DA1EA05CB64209432DD7505A8FE82943
extern void *SYSTEM__STRING_ctor();
struct SYSTEM__STRING_proto {
	struct SYSTEM__OBJECT_proto __base;
	char *str;
};

struct SYSTEM__VALUETYPE_proto {
	struct SYSTEM__OBJECT_proto __base;
};

#define SYSTEM__INT32_ctor mB8A04E0EDA8614F527912F78289CD1FF9D0A0F81
extern void *SYSTEM__INT32_ctor();
struct SYSTEM__INT32_proto {
	struct SYSTEM__VALUETYPE_proto __base;
	int32_t value;
};