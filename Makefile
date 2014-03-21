DIRS = Poly.Internals PolyCompiler Runtime BCL Testing

.PHONY: force

all: $(DIRS)

clean_DIRS=$(addprefix clean_, $(DIRS))
clean: $(clean_DIRS)

$(clean_DIRS): force
	make -C $(patsubst clean_%, %, $@) clean

$(DIRS): force
	$(MAKE) -C $@

