all: treap.o
	gcc main.c treap.o -lm -o main

treap.o: treap.c treap.h
	gcc -c treap.c

run: 
	./main