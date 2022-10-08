all:
	gcc main.c \
	./utils/*.c \
	./lexer/*.c \
	./tokenize/*.c \
	./test/test.c \
	./builtin/*.c \
	./redirect/*.c \
	./cmd/*.c \
	./free/*.c \
	./error/*.c \
	-lreadline # -fsanitize=address -g
run: all
	clear
	./a.out

