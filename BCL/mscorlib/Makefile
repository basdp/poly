output_dir := Build
output := __mscorlib.dll

MCS=dmcs
MCS_FLAGS=-t:library -r:$(output_dir)/Poly.Internals.dll -sdk:4.5 -nowarn:0436,1685

cs := $(shell find . -type f -name "*.cs")

.PHONY: all clean

all: $(output_dir)/$(output)

clean:
	rm -rf $(output_dir)

rebuild: clean all

$(output_dir):
	mkdir -p $@

$(output_dir)/$(output): $(cs) | $(output_dir) $(output_dir)/Poly.Internals.dll
	$(MCS) $(MCS_FLAGS) $(cs) -out:$@

Poly.Internals:
	make -C ../../Poly.Internals

$(output_dir)/Poly.Internals.dll: Poly.Internals
	cp ../../Poly.Internals/Build/Poly.Internals.dll $@


