output_dir := Build
output := PolyCompiler.exe

MCS=dmcs
MCS_FLAGS=-r:$(output_dir)/Poly.Internals.dll -sdk:4.5

cs := $(wildcard *.cs)

all: $(output_dir)/$(output)

.PHONY: all clean

Poly.Internals:
	$(MAKE) -C ../Poly.Internals

$(output_dir)/Poly.Internals.dll: Poly.Internals
	cp ../Poly.Internals/Build/Poly.Internals.dll $@

clean:
	rm -rf $(output_dir)

rebuild: clean all

$(output_dir):
	mkdir -p $@

$(output_dir)/$(output): $(cs) | $(output_dir) $(output_dir)/Poly.Internals.dll
	$(MCS) $(MCS_FLAGS) $(cs) -out:$@

