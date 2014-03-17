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
void linkedlist_free(struct LinkedList*);
void linkedlist_prepend(struct LinkedList*, uintptr_t ptr);
void linkedlist_append(struct LinkedList*, uintptr_t ptr);
void linkedlist_insertAfter(struct LinkedList*, struct Node*, uintptr_t ptr);
void linkedlist_remove(struct LinkedList*, struct Node*);
void linkedlist_removeValue(struct LinkedList*, uintptr_t ptr);
int linkedlist_tryRemoveValue(struct LinkedList* list, uintptr_t ptr);
void linkedlist_removeFirst(struct LinkedList*);
void linkedlist_removeLast(struct LinkedList*);
int linkedlist_contains(struct LinkedList* list, uintptr_t ptr);
struct Node *linkedlist_getNode(struct LinkedList* list, uintptr_t ptr);