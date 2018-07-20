VPATH = dir:dir1
GCC = gcc
FLAGS = -o

CC = $(GCC) $(FLAGS)
objects = main.o add.o sub.o mul.o div.o

prasad : $(objects)
	$(CC) $@ $(objects)

main.o : main.c
	gcc -c $<

add.o : add.c
	gcc -c $<

sub.o : sub.c
	gcc -c $<

mul.o : mul.c
	gcc -c $<

div.o : div.c
	gcc -c $<
