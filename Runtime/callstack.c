#include "callstack.h"
#include <string.h>
#include <stdio.h>

#define MAXSTACK 1000
#define EMPTYSTACK 0
static int top = EMPTYSTACK;
static struct StackFrame items[MAXSTACK];

void callstack_pushframe(struct StackFrame eh) {
	items[top++] = eh;
}

void callstack_push(char* sig, char* filename, int linenumber) {
	struct StackFrame sf;
	sf.filename = filename;
	sf.linenumber = linenumber;
	sf.MethodSignature = sig;
	items[top++] = sf;

	//printf("stack push: %s\n", sig);
}

struct StackFrame callstack_pop() {
	//printf("stack pop: %s\n", items[top - 1].MethodSignature);
	return items[top-- - 1];
}

int callstack_size() {
	return top;
}

struct StackFrame callstack_peek(unsigned int offset) {
	return items[top - 1 - offset];
}

struct StackFrame callstack_at(unsigned int index) {
	return items[index];
}

void print_callstack() {
	int i;
	printf("Stack Trace: (size: %d)\n", top);
	for (i = top - 1; i >= 0; i--) {
		printf("at %s in %s:line %d\n", items[i].MethodSignature, items[i].filename, items[i].linenumber);
	}
	printf("\n");
}
