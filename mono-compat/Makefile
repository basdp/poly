UNAME_S := $(shell uname -s)
SED_I = sed -i''
ifeq ($(UNAME_S),Darwin)
SED_I = sed -i ''
endif


.PHONY: all clean polyc

all: polyc

clean:
	rm -rf polyc

rebuild: clean all

polyc: polyc.prefix
	cp $< $@
	$(SED_I) 's/$$PREFIX/$(subst /,\/,$(PREFIX))/g' $@
	$(SED_I) 's/$$CFLAGS/$(subst /,\/,$(CFLAGS))/g' $@
	$(SED_I) 's/$$POLYFLAGS/$(subst /,\/,$(POLYFLAGS))/g' $@
	chmod a+x $@
