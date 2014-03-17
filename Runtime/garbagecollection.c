#include "garbagecollection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static struct LinkedList root_scope;

void gc_init() {
	root_scope = linkedlist_new();
}

uintptr_t gc_alloc(size_t size) {
	uintptr_t p = (uintptr_t)calloc(1, size);
	//printf("alloc %p (%i bytes)\n", p, size);
	return p;
}

void gc_new(uintptr_t o) {
	struct SYSTEM__OBJECT_proto* obj = (struct SYSTEM__OBJECT_proto*)o;
	printf("new %s (%p)\n", obj->__CILtype, obj);
	// TODO: place object in white set
}

void gc_retain(uintptr_t s, uintptr_t ref) {
	struct SYSTEM__OBJECT_proto* self = (struct SYSTEM__OBJECT_proto*)s;
	struct LinkedList *list;
	if (self == 0) {
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("root scope retains %p (%s)\n", reference, reference->__CILtype);
		list = &root_scope;
	}
	else {
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("%p (%s) retains %p (%s)\n", self, self->__CILtype, ref, reference->__CILtype);
		list = &self->__CILreferences;
	}

	linkedlist_append(list, ref);
}

void gc_release(uintptr_t s, uintptr_t ref) {
	if (ref == 0) return;
	struct SYSTEM__OBJECT_proto* self = (struct SYSTEM__OBJECT_proto*)s;

	struct LinkedList *list;
	if (self == 0) {
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("root scope releases %p (%s)\n", ref, reference->__CILtype);
		list = &root_scope;
	}
	else {
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("%p (%s) releases %p (%s)\n", self, self->__CILtype, ref, reference->__CILtype);
		list = &self->__CILreferences;
	}	

	struct Node *node = list->first;
	while (node != 0) {
		if (node->ptr == ref) {
			linkedlist_remove(list, node);
			return;
		}
		node = node->next;
	}

	printf("released something that wasn't retained!\n");
}