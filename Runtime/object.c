#include "object.h"
#include "stack.h"
#include <stdio.h>

/* System__Object_m___ctor */
void *m2B0D04DDC4F15CBA53A6777CEE421CC56D11EE16(/**/) {
	pop_pointer();
	return 0;
}

void *System__Console_m_WriteLine() {
	int32_t value = pop_value32();
	printf("%i\n", value);
}