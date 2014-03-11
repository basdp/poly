#pragma once
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "hashmap.h"
#include "stack.h"
#include "shims.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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


struct SYSTEM__OBJECT_proto {
	map_t __CILsymboltable;
	intptr_t __CILtype;
	intptr_t __CILbaseclasses;
	int* __CILbaseclasses_length;
	intptr_t __CILbaseinterfaces;
	int* __CILbaseinterfaces_length;
	int __CILisgeneric;
	enum CIL_Type* __CILgenerictypelist;
	int _CILgenerictypelist_length;
};

#define SYSTEM__STRING_ctor m8D858A38DA1EA05CB64209432DD7505A8FE82943
#define SYSTEM__STRING_ctor_sig "System.String::.ctor()"
extern void *SYSTEM__STRING_ctor();
struct SYSTEM__STRING_proto {
	struct SYSTEM__OBJECT_proto __base;
	char *str;
};

struct SYSTEM__VALUETYPE_proto {
	struct SYSTEM__OBJECT_proto __base;
};

#define SYSTEM__INT32_ctor mB8A04E0EDA8614F527912F78289CD1FF9D0A0F81
#define SYSTEM__INT32_ctor_sig "System.Int32::.ctor()"
extern void *SYSTEM__INT32_ctor();
struct SYSTEM__INT32_proto {
	struct SYSTEM__VALUETYPE_proto __base;
	int32_t value;
};

#define SYSTEM__INT64_ctor mBBB2828E3A63B7480D3D6CC62773B26F4691CA33
#define SYSTEM__INT64_ctor_sig "System.Int64::.ctor()"
extern void *SYSTEM__INT64_ctor();
struct SYSTEM__INT64_proto {
	struct SYSTEM__VALUETYPE_proto __base;
	int64_t value;
};

#define SYSTEM__CHAR_ctor mF3EA68989C5CDF2CD019A151716D4F3CCDB873A6
#define SYSTEM__CHAR_ctor_sig "System.Char::.ctor()"
extern void *SYSTEM__CHAR_ctor();
struct SYSTEM__CHAR_proto {
	struct SYSTEM__VALUETYPE_proto __base;
	uint16_t value;
};

#define SYSTEM__RUNTIMEFIELDHANDLE_ctor mFA12ADB043C58D9F4954F097AB47D79F03BE8E23
#define SYSTEM__RUNTIMEFIELDHANDLE_ctor_sig "System.RuntimeFieldHandle::.ctor()" 
extern void *SYSTEM__RUNTIMEFIELDHANDLE_ctor();
struct SYSTEM__RUNTIMEFIELDHANDLE_proto {
	struct SYSTEM__OBJECT_proto __base;
	intptr_t addr;
	enum CIL_Type type;
	int size;
};

#include "opcodes.h"
#include "exceptions.h"
#include "callstack.h"