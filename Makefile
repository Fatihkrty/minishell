all:
	gcc main.c \
	./utils/*.c \
	./lexer/*.c \
	./tokenize/*.c \
	./builtin/*.c \
	./redirect/*.c \
	./cmd/*.c \
	./free/*.c \
	./error/*.c \
	-lreadline -g  -ggdb # -fsanitize=address 
run: all
	clear
	./a.out

valgrind: all
	clear
	valgrind --leak-check=full  ./a.out

