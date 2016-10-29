main: main.c
	gcc -Werror -Wall -pthread main.c -o main
.PHONY: run
run: main
	./main
