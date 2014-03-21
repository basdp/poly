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

$(output_dir)/$(output): $(cs) | $(output_dir)
	$(MCS) $(cs) -out:$@


TESTS := $(wildcard Tests/*)

$(output_dir)/Tests:
	mkdir -p $@

$(output_dir)/Tests/%: Tests/% | $(output_dir)/Tests
	cp $< $(output_dir)/Tests/

tests: $(addprefix $(output_dir)/, $(wildcard Tests/*))
