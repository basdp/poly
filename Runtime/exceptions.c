#include "exceptions.h"
#include <string.h>
#include <stdio.h>

#define MAXSTACK 1000
#define EMPTYSTACK 0
static int top = EMPTYSTACK;
static struct ExceptionHandler items[MAXSTACK];
struct SYSTEM__OBJECT_proto *lastThrownException = 0;

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
			printf("(unknown)\n");
		}
	}
	printf("\n");
}

// System.Exception::ToString()
extern void * mAF915A59A72145069E6562E6C996D1A7DE3D1BBC();
extern char * mAF915A59A72145069E6562E6C996D1A7DE3D1BBC_sig;
// System.Exception::InitStackTrace()
extern char* mCD4230286DD9DEFCC5EFCF854EBB6049454ED123_sig;;
extern void *mCD4230286DD9DEFCC5EFCF854EBB6049454ED123();


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
		CIL_call_unsafe(mCD4230286DD9DEFCC5EFCF854EBB6049454ED123, "m38EAC9CEA38B341E4916A3737AB09F8E8CCC0394", 0, 0);
	}

	struct ExceptionHandler eh;
	int i = 0;

	// Pass 1
	while (1) {
		if (exceptionstack_size() <= i) {
			printf("Uncaught Exception: ");

			push_pointer((uintptr_t)exception);
			CIL_callvirt_unsafe(mAF915A59A72145069E6562E6C996D1A7DE3D1BBC, "m67927A3071253D828DCB5EC9A1AE8B0967E45059", 0, 1); // Exception.ToString();
			char *excmess = CIL_getCStringFromSystemString(pop_pointer());
			printf("%s\n", excmess);
			// TODO: should probably execute all finally blocks
			exit(1);
		}
		eh = exceptionstack_peek(i++);

		if (eh.handlerType == HANDLERTYPE_CATCH && object_is_type_or_subtype(exception, eh.typeName) ||
			eh.handlerType == HANDLERTYPE_FINALLY)
		{
			break;
		}
	}

#if DEBUG_EXCEPTIONS == 1
	printf("Exception level: %d\n", i);
	printf("Current Handler: %s\n", eh.typeName);
#endif

	// Pass 2
	for (; i > 0; i--) {
		if (i > boundExceptions) {
			// this is a handler outside of this method
			push_pointer((uintptr_t)exception);
			return 0;
		}
		else {
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

			}
		}
	}

	// remove all other catches that are bound to this try block from the exception stack
	struct ExceptionHandler eh2 = exceptionstack_peek(0);
	while (eh2.tryAddress == eh.tryAddress && eh2.tryLength == eh.tryLength) {
#if DEBUG_EXCEPTIONS == 1
		printf("Removed alternative %s from exception stack\n", eh2.typeName);
#endif
		*removedBoundExceptions += 1;
		exceptionstack_pop();
		eh2 = exceptionstack_peek(0);
	}

#if DEBUG_EXCEPTIONS == 1
	printf("dispatch catch\n");
#endif
	stack_shrink(eh.stackSize);
	push_pointer((uintptr_t)exception);
	
	*removedBoundExceptions += 1;

	return eh.labelAddress;
}
