/**@brief Readelf implementation to get ELF header format and Section headers*/

///hedader guards
#ifndef ELF_HEADER_H 
#define ELF_HEADER_H

///headers files
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <elf.h> ///@brief required to get the ELF structures

///Macros definition
#define SIZE_ELF 52
#define SIZE_BYTE 1
#define SIZE_MAGIC 7

///function declarations
void print_elf(Elf32_Ehdr *my_elf);
void print_section(Elf32_Ehdr *my_elf, FILE *fp);
int get_offset(Elf32_Shdr *my_sec, Elf32_Ehdr *my_elf );
void print_flags(unsigned int flag);
///end of header guards
#endif
