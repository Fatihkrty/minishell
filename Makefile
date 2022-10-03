all:
	gcc main.c \
	./utils/*.c \
	./lexer/*.c \
	./tokenize/*.c \
	./test/test.c \
	./builtin/*.c \
	./redirect/*.c \
	./cmd/*.c \
	./pipes/*.c \
	./free/*.c \
	-lreadline # -fsanitize=address -g
run: all
	clear
	./a.out
debug:
	gcc main.c ./utils/*.c ./lexer/*.c ./tokenize/*.c ./test/test.c ./builtin/*.c ./redirect/*.c ./cmd/*.c -lreadline -ggdb
