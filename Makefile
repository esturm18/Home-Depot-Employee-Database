#Makefile for employee database

main: main.o list.o
	gcc -g -o main main.o list.o
main.o: main.c struct.h
	gcc -g -c main.c
list.o: list.c
	gcc -g -c list.c
clean:
	rm main main.o list.o
