MCS=dmcs

output_dir := Build
output := RegressionTester.exe

cs := $(wildcard *.cs)

.PHONY: all clean Tests

all: $(output_dir)/$(output) tests

clean:
	rm -rf $(output_dir)

rebuild: clean all

$(output_dir):
	mkdir -p $@

$(output_dir)/$(output): $(cs) | $(output_dir) $(output_dir)/PolyCompiler.exe $(output_dir)/__mscorlib.dll
	$(MCS) $(cs) -out:$@

PolyCompiler:
	$(MAKE) -C ../../PolyCompiler

$(output_dir)/PolyCompiler.exe: $(output_dir)/Poly.Internals.dll
	cp ../../PolyCompiler/Build/PolyCompiler.exe $@

$(output_dir)/Poly.Internals.dll: PolyCompiler
	cp ../../PolyCompiler/Build/Poly.Internals.dll $@

mscorlib:
	$(MAKE) -C ../../BCL/mscorlib

$(output_dir)/__mscorlib.dll: mscorlib
	cp ../../BCL/mscorlib/Build/__mscorlib.dll $@




TESTS := $(wildcard Tests/*)

$(output_dir)/Tests:
	mkdir -p $@

$(output_dir)/Tests/%: Tests/% | $(output_dir)/Tests
	cp $< $(output_dir)/Tests/

tests: $(addprefix $(output_dir)/, $(wildcard Tests/*))
