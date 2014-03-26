.PHONY: all clean polyc

all: polyc

clean:
	rm -rf polyc

rebuild: clean all

polyc: polyc.prefix
	cp $< $@
	sed -i'' 's/$$PREFIX/$(subst /,\/,$(PREFIX))/g' $@
	sed -i'' 's/$$CFLAGS/$(subst /,\/,$(CFLAGS))/g' $@
	sed -i'' 's/$$POLYFLAGS/$(subst /,\/,$(POLYFLAGS))/g' $@
	chmod a+x $@
