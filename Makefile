all:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c ./test/test.c ./builtin/*.c ./redirect/*.c ./cmd/*.c -lreadline  -fsanitize=address -g
run: all
	./a.out
debug:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c ./test/test.c ./builtin/*.c ./redirect/*.c ./cmd/*.c -lreadline -ggdb
