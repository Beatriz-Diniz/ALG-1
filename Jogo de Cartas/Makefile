all: pilha.o
	gcc main.c pilha.o -lm -o main

pilha.o: pilha.c pilha.h
	gcc -c pilha.c

run: 
	./main