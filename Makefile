

all:
	gcc main.c ./utils/*.c ./tokenize/*.c -lreadline

run: all
	./a.out
debug:
	gcc main.c lexical_analysis.c commander.c ./utils/*.c ./tokenize/*.c -lreadline -ggdb