CC=gcc
CFLAGS=
AR=ar

ifeq ($(ARCH), x86_64)
	CFLAGS += -m64
else
	CFLAGS += -m32
endif

output := runtime.a

objects := $(patsubst %.c, %.o, $(wildcard *.c))
depends := $(objects:.o=.d)

all: $(output)

clean:
	$(RM) $(objects) $(depends) $(output)

rebuild:
	clean all

%.o: %.c
	$(CC) -c -MMD -MP $< -o $@ $(CFLAGS)

$(output): $(objects)
	$(AR) rcs $@ $(objects)

-include $(depends)
