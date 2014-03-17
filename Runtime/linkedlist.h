#pragma once

#include <stdlib.h>
#include <stdio.h>

struct Node {
	struct Node* next;
	struct Node* prev;
	uintptr_t ptr;
};

struct LinkedList {
	struct Node* first;
	struct Node* last;
	int length;
};

struct LinkedList linkedlist_new();
void linkedlist_prepend(struct LinkedList*, uintptr_t ptr);
void linkedlist_append(struct LinkedList*, uintptr_t ptr);
void linkedlist_insertAfter(struct LinkedList*, struct Node*, uintptr_t ptr);
void linkedlist_remove(struct LinkedList*, struct Node*);
void linkedlist_removeFirst(struct LinkedList*);
void linkedlist_removeLast(struct LinkedList*);
