DIRS = Poly.Internals PolyCompiler Runtime BCL Testing mono-compat

export PREFIX = /usr/local

CC=gcc
CFLAGS=
AR=ar
POLYFLAGS=

ifndef ARCH
export ARCH = $(shell uname -m)
endif

ifeq ($(ARCH), x86_64)
	CFLAGS += -m64
	POLYFLAGS += --arch=X64
else
	CFLAGS += -m32
	POLYFLAGS += --arch=X86
endif

export CFLAGS
export POLYFLAGS

.PHONY: force clean install libs

all: $(DIRS)

clean_DIRS=$(addprefix clean_, $(DIRS))
clean: $(clean_DIRS)

$(clean_DIRS): force
	make -C $(patsubst clean_%, %, $@) clean

$(DIRS): force
	$(MAKE) -C $@

libs: all
	mkdir -p libs
	mono PolyCompiler/Build/PolyCompiler.exe $(POLYFLAGS) BCL/mscorlib/Build/__mscorlib.dll --out=libs
	mono PolyCompiler/Build/PolyCompiler.exe $(POLYFLAGS) Poly.Internals/Build/Poly.Internals.dll --out=libs
	$(CC) -IRuntime libs/mscorlib.c -c -o libs/mscorlib.obj $(CFLAGS)
	$(CC) -IRuntime libs/Poly.Internals.c -c -o libs/Poly.Internals.obj $(CFLAGS)

install: all libs
	mkdir -p $(PREFIX)/lib/poly
	mkdir -p $(PREFIX)/lib/poly/bin
	mkdir -p $(PREFIX)/lib/poly/lib
	mkdir -p $(PREFIX)/lib/poly/include
	cp Runtime/*.h $(PREFIX)/lib/poly/include
	cp libs/*.h $(PREFIX)/lib/poly/include
	cp PolyCompiler/Build/PolyCompiler.exe $(PREFIX)/lib/poly/bin
	cp Poly.Internals/Build/Poly.Internals.dll $(PREFIX)/lib/poly/bin
	cp Poly.Internals/Build/Poly.Internals.dll $(PREFIX)/lib/poly/lib
	cp libs/Poly.Internals.obj $(PREFIX)/lib/poly/lib
	cp BCL/mscorlib/Build/__mscorlib.dll $(PREFIX)/lib/poly/lib
	cp libs/mscorlib.obj $(PREFIX)/lib/poly/lib
	cp Runtime/runtime.a $(PREFIX)/lib/poly/lib
	cp mono-compat/polyc $(PREFIX)/lib/poly/bin
	cp mono-compat/polyc $(PREFIX)/bin

uninstall:
	rm -rf $(PREFIX)/poly
	rm -rf $(PREFIX)/bin/polyc
