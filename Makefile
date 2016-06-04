all: brainfuck.c tokenizer.c parser.c executor.c
	gcc -o brainfuck brainfuck.c tokenizer.c parser.c executor.c

clean:
	rm -f *.o brainfuck

test:
	make -o $(PART)_test $(PART).c $(PART)_test.c
