#include "linkedlist.h"
#include <string.h>
#include <stdio.h>

struct LinkedList linkedlist_new() {
	struct LinkedList ll;
	ll.first = NULL;
	ll.last = NULL;
	ll.length = 0;
	return ll;
}

void linkedlist_free(struct LinkedList* list) {
	struct Node *node = list->first;
	while (node != 0) {
		struct Node *oldNode = node;
		node = node->next;
		free(oldNode);
	}
}

void linkedlist_prepend(struct LinkedList* list, uintptr_t ptr) {
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode == 0) { printf("Out of memory\n"); exit(1); }
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
	if (newNode == 0) { printf("Out of memory\n"); exit(1); }
	newNode->next = 0;
	newNode->prev = list->last;
	newNode->ptr = ptr;
	if (list->last != 0) list->last->next = newNode;
	list->last = newNode;
	if (list->first == 0) list->first = newNode;
	list->length++;
}

void linkedlist_insertAfter(struct LinkedList* list, struct Node* node, uintptr_t ptr) {
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode == 0) { printf("Out of memory\n"); exit(1); }
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
	if (list == 0 || node == 0) {
		printf("linkedlist_remove: list or node is null!\n"); exit(1);
	}

	if (list->first == node) {
		list->first = node->next;
	}

	if (list->last == node) {
		list->last = node->prev;
	}

	if (node->prev != 0) node->prev->next = node->next;
	if (node->next != 0) node->next->prev = node->prev;

	free(node);
	list->length--;
}

void linkedlist_removeValue(struct LinkedList* list, uintptr_t ptr) {
	linkedlist_remove(list, linkedlist_getNode(list, ptr));
}

int linkedlist_tryRemoveValue(struct LinkedList* list, uintptr_t ptr) {
	struct Node * node = linkedlist_getNode(list, ptr);
	if (node != 0) {
		linkedlist_remove(list, node);
		return 1;
	}
	else {
		return 0;
	}
}

void linkedlist_removeFirst(struct LinkedList* list) {
	struct Node *node = list->first;
	list->first = node->next;
	if (list->last == node) list->last = 0;
	free(node);
	list->length--;
}

void linkedlist_removeLast(struct LinkedList* list) {
	struct Node *node = list->last;
	list->last = node->prev;
	if (list->first == node) list->first = 0;
	free(node);
	list->length--;
}

int linkedlist_contains(struct LinkedList* list, uintptr_t ptr) {
	struct Node *node = list->first;
	while (node != 0) {
		if (node->ptr == ptr) {
			return 1;
		}
		node = node->next;
	}
	return 0;
}

struct Node *linkedlist_getNode(struct LinkedList* list, uintptr_t ptr) {
	struct Node *node = list->first;
	while (node != 0) {
		if (node->ptr == ptr) {
			return node;
		}
		node = node->next;
	}
	return 0;
}