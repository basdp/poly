#pragma once

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

//#define uregister_catch(type_name) exceptionstack_pop();

#ifdef _MSC_VER
#define STORE_LABEL_ADDRESS(var, label) __asm { mov [var], offset label }
#define GOTO_LABEL_ADDRESS(var) __asm { jmp var }
#endif

#ifndef STORE_LABEL_ADDRESS
#error STORE_LABEL_ADDRESS needs to be defined for this compiler
// TODO: GCC http://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html
//#  define STORE_ADDRESS(index,label) data[index] = &&label
//#  define JUMP_TO_IP() goto **(ip++)
#endif

void exceptionstack_push(struct ExceptionHandler eh);
struct ExceptionHandler exceptionstack_pop();
int exceptionstack_size();
struct ExceptionHandler exceptionstack_peek(unsigned int offset);
void print_exceptionstack();