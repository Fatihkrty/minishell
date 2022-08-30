

all:
	gcc main.c ./utils/*.c -lreadline

run: all
	./a.out
debug:
	gcc main.c ./utils/*.c -lreadline -ggdb