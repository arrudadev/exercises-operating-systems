.PHONY: run clean

run: main
	./main

main: main.c info.c info.h
	gcc -W -Wall -pedantic -std=c11 main.c info.c -o main

clean:
	rm -rf main