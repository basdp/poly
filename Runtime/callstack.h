#pragma once

struct StackFrame {
	char* MethodSignature;
	char* filename;
	int linenumber;
};

void callstack_pushframe(struct StackFrame eh);
void callstack_push(char* sig, char* filename, int linenumber);
struct StackFrame callstack_pop();
int callstack_size();
struct StackFrame callstack_peek(unsigned int offset);
struct StackFrame callstack_at(unsigned int index);
void print_callstack();
char* callstack_createString();