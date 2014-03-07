#include "exceptions.h"
#include <string.h>
#include <stdio.h>

#define MAXSTACK 1000
#define EMPTYSTACK 0
static int top = EMPTYSTACK;
static struct ExceptionHandler items[MAXSTACK];

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
