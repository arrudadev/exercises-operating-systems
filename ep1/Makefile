.PHONY: run clean

run: main
	./main

main: main.c malloc.c malloc.h
	gcc -W -Wall -pedantic -std=c11 main.c malloc.c malloc.h -o main

clean:
	rm -rf main