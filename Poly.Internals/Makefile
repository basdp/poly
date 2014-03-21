MCS=dmcs
MCS_FLAGS=-t:library

output_dir := Build
output := Poly.Internals.dll

cs := $(wildcard *.cs)

.PHONY: all clean

all: $(output_dir)/$(output)

clean:
	rm -rf $(output_dir)

rebuild: clean all

$(output_dir):
	mkdir -p $@

$(output_dir)/$(output): $(cs) | $(output_dir)
	$(MCS) $(MCS_FLAGS) $(cs) -out:$@

