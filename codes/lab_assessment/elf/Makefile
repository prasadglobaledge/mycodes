VPATH = source
objects = elf_app.c elf_lib.c  

out : $(objects)
	gcc -Wall -include "header/elf_header.h" $^ -o $@

.PHONY : clean

clean:
	rm a.out elf_app.o elf_lib.o
