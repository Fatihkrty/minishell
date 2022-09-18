all:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c test.c
run: all
	./a.out
debug:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c test.c -lreadline -ggdb
