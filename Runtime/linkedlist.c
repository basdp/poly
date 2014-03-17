#include "linkedlist.h"
#include <string.h>
#include <stdio.h>

struct LinkedList linkedlist_new() {
	struct LinkedList ll;
	ll.first = 0;
	ll.last = 0;
	ll.length = 0;
	return ll;
}

void linkedlist_prepend(struct LinkedList* list, uintptr_t ptr) {
	struct Node *newNode = malloc(sizeof(struct Node));
	if (list->first != 0) list->first->prev = newNode;
	newNode->next = list->first;
	newNode->prev = 0;
	newNode->ptr = ptr;
	list->first = newNode;
	if (list->last == 0) list->last = newNode;
	list->length++;
}

void linkedlist_append(struct LinkedList* list, uintptr_t ptr) {
	struct Node *newNode = malloc(sizeof(struct Node));
	if (list->last != 0) list->last->next = newNode;
	newNode->next = 0;
	newNode->prev = list->last;
	newNode->ptr = ptr;
	list->last = newNode;
	if (list->first == 0) list->first = newNode;
	list->length++;
}

void linkedlist_insertAfter(struct LinkedList* list, struct Node* node, uintptr_t ptr) {
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->next = node->next;
	newNode->prev = node;
	newNode->ptr = ptr;
	node->next = newNode;

	if (list->last == node) {
		list->last = newNode;
	}

	list->length++;
}

void linkedlist_remove(struct LinkedList* list, struct Node* node) {
	if (list->first == node) {
		list->first = node->next;
	}
	else if (list->last == node) {
		list->last = node->prev;
	}
	if (node->prev != 0) node->prev->next = node->next;
	if (node->next != 0) node->next->prev = node->prev;

	free(node);
	list->length--;
}

void linkedlist_removeFirst(struct LinkedList* list) {
	struct Node *node = list->first;
	list->first = node->next;
	free(node);
	list->length--;
}

void linkedlist_removeLast(struct LinkedList* list) {
	struct Node *node = list->last;
	list->last = node->prev;
	free(node);
	list->length--;
}
