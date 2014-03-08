#include "exceptions.h"
#include <string.h>
#include <stdio.h>

#define MAXSTACK 1000
#define EMPTYSTACK 0
static int top = EMPTYSTACK;
static struct ExceptionHandler items[MAXSTACK];
<<<<<<< HEAD
struct SYSTEM__OBJECT_proto *lastThrownException = 0;
=======
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019

void exceptionstack_push(struct ExceptionHandler eh) {
	items[top++] = eh;
}

struct ExceptionHandler exceptionstack_pop() {
	return items[top-- - 1];
}

int exceptionstack_size() {
	return top;
}

struct ExceptionHandler exceptionstack_peek(unsigned int offset) {
	return items[top - 1 - offset];
}

void print_exceptionstack() {
	int i;
	printf("Exception Stack: (size: %d)\n", top);
	for (i = 0; i < top; i++) {
		int size = 0;
		if (items[i].handlerType == HANDLERTYPE_CATCH) {
			printf("%d\t%p\t%d\t%s\n", i, items[i].labelAddress, items[i].stackSize, items[i].typeName);
		}
		else if (items[i].handlerType == HANDLERTYPE_FINALLY) {
			printf("%d\t%p\t \t(finally)\n", i, items[i].labelAddress);
		}
		else {
			printf("(unknown)\n", i, items[i].labelAddress);
		}
	}
	printf("\n");
}

<<<<<<< HEAD
// System.Exception::ToString()
extern void * mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218();
extern char * mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218_sig;
// System.Exception::InitStackTrace()
extern char* m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394_sig;;
extern void *m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394();


void* throw_dispatch(int boundExceptions, int* removedBoundExceptions, int initStackTrace) {
	*removedBoundExceptions = 0;
	struct SYSTEM__OBJECT_proto *exception = (struct SYSTEM__OBJECT_proto *)pop_pointer();
	lastThrownException = exception;

#if DEBUG_EXCEPTIONS == 1
	printf("Exception thrown: %s\n", exception->__CILtype);
	printf("Bound ExceptionHandlers: %d\n", boundExceptions);
	print_exceptionstack();
	print_callstack();
#endif

	if (initStackTrace) {
#if DEBUG_EXCEPTIONS == 1
		printf("(re)initialize the stack trace\n");
#endif
		push_pointer((uintptr_t)exception);
		CIL_call(m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394, "m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394", 0, 0);
	}
=======
extern void * mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218();
extern char * mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218_sig;

void* throw_dispatch(int boundExceptions) {
	struct SYSTEM__OBJECT_proto *exception = (struct SYSTEM__OBJECT_proto *)pop_pointer();

	//printf("Exception thrown: %s\n", exception->__CILtype);
	//printf("Bound ExceptionHandlers: %d\n", boundExceptions);
	//print_exceptionstack();
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019

	struct ExceptionHandler eh;
	int i = 0;

	// Pass 1
	while (1) {
		if (exceptionstack_size() <= i) {
			printf("Uncaught Exception: ");

			push_pointer((uintptr_t)exception);
			CIL_callvirt_unsafe(mFA7CAC02617528CA7AC2E4A268BEF2AA5656C218, "m1DBC7385BADBFDA548FB27E2160A33CF32C0F545", 0, 1); // Exception.ToString();
			char *excmess = CIL_getCStringFromSystemString(pop_pointer());
			printf("%s\n", excmess);
			// TODO: should probably execute all finally blocks
			exit(1);
		}
		eh = exceptionstack_peek(i++);

<<<<<<< HEAD
		if (eh.handlerType == HANDLERTYPE_CATCH && object_is_type_or_subtype(exception, eh.typeName) ||
			eh.handlerType == HANDLERTYPE_FINALLY)
=======
		if (eh.handlerType == HANDLERTYPE_CATCH && object_is_type_or_subtype(exception, eh.typeName))
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
		{
			break;
		}
	}

<<<<<<< HEAD
#if DEBUG_EXCEPTIONS == 1
	printf("Exception level: %d\n", i);
	printf("Current Handler: %s\n", eh.typeName);
#endif
=======
	//printf("Exception level: %d\n", i);
	//printf("Current Handler: %s\n", eh.typeName);
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019

	// Pass 2
	for (; i > 0; i--) {
		if (i > boundExceptions) {
			// this is a handler outside of this method
			push_pointer((uintptr_t)exception);
			return 0;
		}
		else {
<<<<<<< HEAD
			exceptionstack_pop();

			// this is a handler in this method
			if (eh.handlerType == HANDLERTYPE_FINALLY) {
#if DEBUG_EXCEPTIONS == 1
				printf("INTERMEDIATE FINALLY\n");
				print_exceptionstack();
#endif
				push_pointer((uintptr_t)exception);
				push_pointer((uintptr_t)eh.labelAddress);
				return (void*)1;

=======
			// this is a handler in this method
			struct ExceptionHandler eh3 = exceptionstack_pop();
			if (eh3.handlerType == HANDLERTYPE_FINALLY) {
				printf("SKIPPED FINALLY\n");
				// TODO: Exception: this should not be skipped.. :(

				//void* p; STORE_LABEL_ADDRESS(p, label);
				//push_pointer((uintptr_t)p);
				//GOTO_LABEL_ADDRESS(eh.labelAddress);
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
			}
		}
	}

<<<<<<< HEAD
	// remove all other catches that are bound to this try block from the exception stack
	struct ExceptionHandler eh2 = exceptionstack_peek(0);
	while (eh2.tryAddress == eh.tryAddress && eh2.tryLength == eh.tryLength) {
#if DEBUG_EXCEPTIONS == 1
		printf("Removed alternative %s from exception stack\n", eh2.typeName);
#endif
		*removedBoundExceptions += 1;
=======
	// remove all other Exception Handlers that are bound to this try block from the exception stack
	struct ExceptionHandler eh2 = exceptionstack_peek(0);
	while (eh2.tryAddress == eh.tryAddress && eh2.tryLength == eh.tryLength) {
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
		exceptionstack_pop();
		eh2 = exceptionstack_peek(0);
	}

<<<<<<< HEAD
#if DEBUG_EXCEPTIONS == 1
	printf("dispatch catch\n");
#endif
	stack_shrink(eh.stackSize);
	push_pointer((uintptr_t)exception);
	
	*removedBoundExceptions += 1;
=======
	stack_shrink(eh.stackSize);
	push_pointer((uintptr_t)exception);
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019

	return eh.labelAddress;
}
