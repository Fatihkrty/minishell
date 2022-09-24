all:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c ./test/test.c ./builtin_funcs/*.c ./redirect_funcs/*.c ./cmd/*.c -lreadline
run: all
	./a.out
debug:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c ./test/test.c ./builtin_funcs/*.c ./redirect_funcs/*.c ./cmd/*.c -lreadline -ggdb
