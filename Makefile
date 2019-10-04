.PHONY: all

#global const's
GCC=gcc -ansi
#procedures
all: test.zip
	unzip -l $<

#main
gen-output: gen-output.c
	$(GCC) -o $@ $<

gen-random-input: gen-random-input.c
	$(GCC) -o $@ $<
in%.txt: gen-random-input
	./$< > $@
out%.txt: in%.txt gen-output
	cat $< | ./gen-output > $@
test.zip: $(addsuffix .txt, $(addprefix in, 1 2 3 4 5) $(addprefix out, 1 2 3 4 5))
	rm -rf $@
	zip $(basename $@) $^
