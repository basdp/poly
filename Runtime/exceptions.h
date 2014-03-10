#pragma once
#include "opcodes.h"
#include "object.h"

#define DEBUG_EXCEPTIONS 0

enum HandlerType {
	HANDLERTYPE_CATCH,
	HANDLERTYPE_FINALLY,
	HANDLERTYPE_FAULT,
	HANDLERTYPE_FILTER
};

struct ExceptionHandler {
	enum HandlerType handlerType;
	char* typeName;
	void* labelAddress;
	void* tryAddress;
	int tryLength;
	int stackSize;
};

#define register_catch(type_name, label_address, try_address, try_length, stack_size) { \
	boundExceptions++;\
	struct ExceptionHandler h;\
	h.handlerType = HANDLERTYPE_CATCH; \
	STORE_LABEL_ADDRESS(h.labelAddress, label_address); \
	h.typeName = type_name;\
	h.stackSize = stack_size; \
	STORE_LABEL_ADDRESS(h.tryAddress, try_address); \
	h.tryLength = try_length; \
	exceptionstack_push(h); \
}

#define register_finally(label_address, try_address, try_length) { \
	boundExceptions++;\
	struct ExceptionHandler h;\
	h.handlerType = HANDLERTYPE_FINALLY; \
	STORE_LABEL_ADDRESS(h.labelAddress, label_address); \
	STORE_LABEL_ADDRESS(h.tryAddress, try_address); \
	h.tryLength = try_length; \
	h.typeName = ""; \
	exceptionstack_push(h); \
}

#ifdef _MSC_VER
#define STORE_LABEL_ADDRESS(var, label) __asm { mov [var], offset label }
#define GOTO_LABEL_ADDRESS(var) __asm { jmp var }
#endif

#ifdef __GNUC__
#define STORE_LABEL_ADDRESS(var, label) var = &&label
#define GOTO_LABEL_ADDRESS(var) goto *(var)
#endif

#ifndef STORE_LABEL_ADDRESS
#error STORE_LABEL_ADDRESS needs to be defined for this compiler
#endif

extern struct SYSTEM__OBJECT_proto *lastThrownException;

#define exception_throw() exception_throw_withInitStackTrace(1)
#define exception_rethrow() { push_pointer((uintptr_t)lastThrownException); exception_throw_withInitStackTrace(0) }

#define exception_throw_withInitStackTrace(initStackTrace) { \
	if (DEBUG_EXCEPTIONS) { printf("in %s -> %s:%d\n", __FUNCTION__, __FILE__, __LINE__); } \
	int removedBoundExceptions; \
	void* lbl = throw_dispatch(boundExceptions, &removedBoundExceptions, initStackTrace); \
	if (DEBUG_EXCEPTIONS && removedBoundExceptions > 0) printf("Removed %d from bound exceptions\n", removedBoundExceptions);\
	boundExceptions -= removedBoundExceptions; \
	if (lbl == 0) { \
		/* continue with exception in previous method */ \
		callstack_pop(); \
		return (void*)1; \
	} else if (lbl == (void*)1) { \
		/* continue with finally in THIS method */\
		if (DEBUG_EXCEPTIONS) printf("continue with finally in this method\n");\
		boundExceptions--; \
		uintptr_t finallyAddr = pop_pointer(); \
		push_pointer(0);\
		GOTO_LABEL_ADDRESS(finallyAddr); \
	} else {\
	GOTO_LABEL_ADDRESS(lbl); \
	} \
}

#define exception_leave(label) {\
	if (DEBUG_EXCEPTIONS) printf("exception_leave %d\n", entryStackSize);\
	stack_shrink(entryStackSize); \
	if (boundExceptions > 0) {\
		struct ExceptionHandler eh = exceptionstack_pop();\
		boundExceptions--;\
		if (eh.handlerType == HANDLERTYPE_FINALLY) { \
			void* p; STORE_LABEL_ADDRESS(p, label);\
			push_pointer((uintptr_t)p);\
			GOTO_LABEL_ADDRESS(eh.labelAddress);\
		} else if (eh.handlerType == HANDLERTYPE_CATCH) {\
			struct ExceptionHandler eh2 = exceptionstack_peek(0);\
			while (eh2.handlerType == HANDLERTYPE_CATCH && eh2.tryAddress == eh.tryAddress && eh2.tryLength == eh.tryLength) {\
				exceptionstack_pop();\
				boundExceptions--;\
				eh2 = exceptionstack_peek(0);\
			}\
		}\
	}\
	goto label;\
}

#define exception_endfinally() {\
	if (DEBUG_EXCEPTIONS) { printf("endfinally\n"); } \
	uintptr_t p = pop_pointer(); \
	if (p == 0) {\
	if (DEBUG_EXCEPTIONS) { printf("return was 0\n");print_stack(); }\
		exception_throw_withInitStackTrace(0);\
	}\
	GOTO_LABEL_ADDRESS(p); \
}

// System.NullReferenceException
extern void* m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C();
extern char* m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C_sig;
#define throw_NullReferenceException() { CIL_newobj(System__NullReferenceException, m7478BF6EC5F04E0D28F88AAD2CE7EF9EDB108B0C); CIL_throw(); } 

// System.InvalidCastException
extern void* mB71A0D21D024AF44637A268806CE99358D389355();
extern char* mB71A0D21D024AF44637A268806CE99358D389355_sig;
#define throw_InvalidCastException() { CIL_newobj(System__InvalidCastException, mB71A0D21D024AF44637A268806CE99358D389355); CIL_throw(); } 

// System.IndexOutOfRangeException
extern void* m3C46C87472BC1C0212B9B21367868D11FCC940BB();
extern char* m3C46C87472BC1C0212B9B21367868D11FCC940BB_sig;
#define throw_IndexOutOfRangeException() { CIL_newobj(System__IndexOutOfRangeException, m3C46C87472BC1C0212B9B21367868D11FCC940BB); CIL_throw(); } 

// System.ArgumentOutOfRangeException
extern void* mD81A01BD2EAF4E0554E7E00022DA8393DA63979F();
extern char* mD81A01BD2EAF4E0554E7E00022DA8393DA63979F_sig;
#define throw_ArgumentOutOfRangeException() { CIL_newobj(System__ArgumentOutOfRangeException, mD81A01BD2EAF4E0554E7E00022DA8393DA63979F); CIL_throw(); } 

void* throw_dispatch(int, int*, int);
void exceptionstack_push(struct ExceptionHandler eh);
struct ExceptionHandler exceptionstack_pop();
int exceptionstack_size();
struct ExceptionHandler exceptionstack_peek(unsigned int offset);
void print_exceptionstack();