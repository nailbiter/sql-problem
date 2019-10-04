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
in%.uncut.txt: gen-random-input
	./$< > $@
out%.txt: in%.uncut.txt gen-output
	cat $< | ./gen-output > $@
in%.txt: in%.uncut.txt
	cat $<|tail -n +2 > $@
test.zip: $(addsuffix .txt, $(addprefix in, 1 2 3 4 5) $(addprefix out, 1 2 3 4 5))
	rm -rf $@
	zip $(basename $@) $^
