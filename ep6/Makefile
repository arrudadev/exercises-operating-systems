
all: reverse.so

reverse.so: reverse.o
	gcc -shared reverse.o -o reverse.so

reverse.o:
	gcc -c reverse.c

clean:
	rm *.o *.so


