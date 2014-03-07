#include "object.h"
#include "stack.h"
#include <stdio.h>

int object_is_type_or_subtype(struct SYSTEM__OBJECT_proto *object, const char* type) {
	//printf("object_is_type_or_subtype '%s' == '%s'\n", object->__CILtype, type);
	if (strcmp(type, (char*)object->__CILtype) == 0)
		return 1;
	for (int i = 0; i < *(object->__CILbaseclasses_length); i++) {
		if (strcmp(type, ((char**)object->__CILbaseclasses)[i]) == 0)
			return 1;
	}
	return 0;
}

/* System__Object_m___ctor */
/*void *m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16() {
	pop_pointer();
	return 0;
}*/

/*
void *System__Console_m_WriteLine() {
	int32_t value = pop_value32();
	printf("%i\n", value);
}*/