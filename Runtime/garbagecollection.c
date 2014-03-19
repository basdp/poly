#include "garbagecollection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG_GARBAGE_COLLECTION 0

struct LinkedList _gc_all_objects;
struct LinkedList _gc_all_arrays;
struct LinkedList _gc_all_valuearrays;
struct LinkedList _gc_root_scope;

void gc_init() {
	_gc_all_objects = linkedlist_new();
	_gc_root_scope = linkedlist_new();

	_gc_all_arrays = linkedlist_new();
	_gc_all_valuearrays = linkedlist_new();

	srand((unsigned int)time(NULL));
#if DEBUG_GARBAGE_COLLECTION == 1
	printf("Initialize Garbage Collection\n");
#endif
}

uintptr_t gc_alloc(size_t size) {
	uintptr_t p = (uintptr_t)calloc(1, size);
	//printf("alloc %p (%i bytes)\n", p, size);
	return p;
}

void gc_new(uintptr_t o) {
	struct SYSTEM__OBJECT_proto* obj = (struct SYSTEM__OBJECT_proto*)o;
#if DEBUG_GARBAGE_COLLECTION==1
	printf("new %s (%p)\n", obj->__CILtype, obj);
#endif
	linkedlist_append(&_gc_all_objects, (uintptr_t)obj);
}

void gc_new_arr(uintptr_t o) {
#if DEBUG_GARBAGE_COLLECTION==1
	printf("new array %p\n", o);
#endif
	linkedlist_append(&_gc_all_arrays, o);
}

void gc_new_valuearray(uintptr_t arr) {
#if DEBUG_GARBAGE_COLLECTION==1
	printf("new value array %p\n", o);
#endif
	linkedlist_append(&_gc_all_valuearrays, arr);
}

void gc_retain(uintptr_t s, uintptr_t ref) {
	if (ref == 0) return;

	struct SYSTEM__OBJECT_proto* self = (struct SYSTEM__OBJECT_proto*)s;
	struct LinkedList *list;
	if (self == 0) {
#if DEBUG_GARBAGE_COLLECTION == 1
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("root scope retains ");
		printf("%p\n", reference);
#endif
		list = &_gc_root_scope;
	}
	else {
#if DEBUG_GARBAGE_COLLECTION == 1
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("%p retains %p\n", self, ref);
#endif
		list = &self->__CILreferences;
	}


	linkedlist_append(list, ref);
}

void gc_release(uintptr_t s, uintptr_t ref) {
	if (ref == 0) return;

	struct SYSTEM__OBJECT_proto* self = (struct SYSTEM__OBJECT_proto*)s;

	struct LinkedList *list;
	if (self == 0) {
#if DEBUG_GARBAGE_COLLECTION == 1
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("root scope releases %p\n", ref);
#endif
		list = &_gc_root_scope;
	}
	else {
#if DEBUG_GARBAGE_COLLECTION == 1
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ref;
		printf("%p releases %p\n", self, ref);
#endif
		list = &self->__CILreferences;
	}	

	struct Node *node = list->first;
	while (node != 0) {
		if (node->ptr == ref) {
			linkedlist_remove(list, node);

			//if (rand() % 5 == 0) {
				gc_cycle();
			//}

			return;
		}
		node = node->next;
	}

	printf("released something that wasn't retained!\n");
}

extern void* mDA7BB6FE2475319A165CB49FA632EE1D1F8A71BA();
extern char* mDA7BB6FE2475319A165CB49FA632EE1D1F8A71BA_sig;

static int gc_cycle_in_progress = 0;
void gc_cycle() {
	if (gc_cycle_in_progress) return;
	gc_cycle_in_progress = 1;
#if DEBUG_GARBAGE_COLLECTION == 1
	printf("Performing a Garbage Collection Cycle\n");
	//print_callstack();
	//print_stack();
#endif

	struct LinkedList white = linkedlist_new();
	struct LinkedList grey = linkedlist_new();
	struct LinkedList black = linkedlist_new();

	struct Node *node = _gc_all_objects.first;
	while (node != 0) {
		if (linkedlist_contains(&_gc_root_scope, node->ptr)) {
			linkedlist_append(&grey, node->ptr);
		}
		else {
			linkedlist_append(&white, node->ptr);
		}
		node = node->next;
	}
	node = _gc_all_arrays.first;
	while (node != 0) {
		if (linkedlist_contains(&_gc_root_scope, node->ptr)) {
			linkedlist_append(&grey, node->ptr);
		}
		else {
			linkedlist_append(&white, node->ptr);
		}
		node = node->next;
	}
	node = _gc_all_valuearrays.first;
	while (node != 0) {
		if (linkedlist_contains(&_gc_root_scope, node->ptr)) {
			linkedlist_append(&grey, node->ptr);
		}
		else {
			linkedlist_append(&white, node->ptr);
		}
		node = node->next;
	}

	int i = 0;
	for (i = 0; i < stack_size(); i++) {
		if (stack_offset_type(i) == CIL_pointer || stack_offset_type(i) == CIL_array) {
			uintptr_t ptr = peek_pointer(i);
			if (ptr == 0) continue;
			if (!linkedlist_contains(&grey, ptr)) {
				if (linkedlist_contains(&white, ptr)) {
					// remove it from the white list, because the stack is global scope
					linkedlist_tryRemoveValue(&white, ptr);
				}
				linkedlist_append(&grey, ptr);
#if DEBUG_GARBAGE_COLLECTION == 1
				struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)ptr;
				printf("Added %p to the grey list, because it is on the stack\n", ptr);
#endif
			}
		}
	}
		
	node = grey.first;
	while (node != 0) {
		// remove this node from the grey set and blacken it (add to the black set)
		linkedlist_append(&black, node->ptr);
		if (linkedlist_contains(&_gc_all_arrays, node->ptr)) {
			#if DEBUG_GARBAGE_COLLECTION == 1
				printf("Blackening array %p\n", node->ptr);
				printf("    %p contains references to:\n", node->ptr);
			#endif
			int len = ((int32_t*)node->ptr)[0];
			uintptr_t* array = (uintptr_t*)node->ptr;
			for (int i = 0; i < len; i++) {
				uintptr_t r = (uintptr_t)array[i + 2];
				#if DEBUG_GARBAGE_COLLECTION == 1
					printf("        %p\n", r);
				#endif
				linkedlist_tryRemoveValue(&white, r);
				linkedlist_append(&grey, r);
			}
		} else if (linkedlist_contains(&_gc_all_objects, node->ptr)) {
			struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)node->ptr;
			#if DEBUG_GARBAGE_COLLECTION == 1
				printf("Blackening %p\n", reference);
				printf("    %p references:\n", reference);
			#endif
			struct Node *subNode = reference->__CILreferences.first;
			while (subNode != 0) {
				struct SYSTEM__OBJECT_proto* r = (struct SYSTEM__OBJECT_proto*)subNode->ptr;
				#if DEBUG_GARBAGE_COLLECTION == 1
					printf("        %p\n", r);
				#endif
				linkedlist_tryRemoveValue(&white, subNode->ptr);
				linkedlist_append(&grey, subNode->ptr);
				subNode = subNode->next;
			}
		} else if (linkedlist_contains(&_gc_all_valuearrays, node->ptr)) {
			// do nothing with it's contents
		}
		else {
			// happens when the object is still in the constructor phase
			//linkedlist_tryRemoveValue(&white, node->ptr);
			//linkedlist_tryRemoveValue(&grey, node->ptr);
			//linkedlist_tryRemoveValue(&black, node->ptr);
			//linkedlist_append(&black, node->ptr);
		}

		struct Node* oldNode = node;
		node = node->next;
		linkedlist_remove(&grey, oldNode);
	}
	// Grey set is now empty, meaning that objects in the black set are still referenced, and objects in the white set are free

	node = white.first;
	while (node != 0) {
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)node->ptr;
#if DEBUG_GARBAGE_COLLECTION == 1
		printf("    freeing %p\n", reference);
#endif
		if (!linkedlist_tryRemoveValue(&_gc_all_objects, node->ptr)) {
			if (!linkedlist_tryRemoveValue(&_gc_all_arrays, node->ptr)) {
				if (!linkedlist_tryRemoveValue(&_gc_all_valuearrays, node->ptr)) {
					node = node->next;
					continue;
				}
				else {
					// this is an value array
				}
			}
			else {
				// this is an array
			}
		}
		else {
			// this is an object
			// finalize the object
			int stackSize = stack_size();
			push_pointer(node->ptr);
			callstack_push("Finalize", "", 0);
			CIL_callvirt_dispatch("mF826D67105FC9EE6FA183DB08AB63B7C77D9484D", 0, &mDA7BB6FE2475319A165CB49FA632EE1D1F8A71BA, 1);
			if (stack_size() > stackSize) stack_shrink(stackSize);
		}
		
		free((void*)node->ptr);
		node = node->next;
	}

#if DEBUG_GARBAGE_COLLECTION == 1
	printf("End of Garbage Collection Cycle\n");
#endif

	linkedlist_free(&white);
	linkedlist_free(&grey);
	linkedlist_free(&black);

	gc_cycle_in_progress = 0;
}

void print_heap() {
	printf("Heap: (size: %d objects, %d arrays)\n", _gc_all_objects.length, _gc_all_arrays.length);
	printf("Objects:\n");
	struct Node* node = _gc_all_objects.first;
	while (node != 0) {
		struct SYSTEM__OBJECT_proto* reference = (struct SYSTEM__OBJECT_proto*)node->ptr;
		printf("    %p\t%s\n", node->ptr, reference->__CILtype);
		node = node->next;
	}
	printf("Arrays:\n");
	node = _gc_all_arrays.first;
	while (node != 0) {
		int32_t len = ((int32_t*)node->ptr)[0];
		printf("    %p\tlength: %d\n", node->ptr, len);
		node = node->next;
	}
}

int heap_size() {
	return _gc_all_objects.length + _gc_all_arrays.length;
}