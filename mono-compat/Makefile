.PHONY: all clean

all: polyc

clean:
	rm -rf polyc

rebuild: clean all

polyc: polyc.prefix
	sed 's/$$PREFIX/$(subst /,\/,$(PREFIX))/g' $< > $@
	chmod a+x $@
