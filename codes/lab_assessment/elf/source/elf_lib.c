/**@brief functions to print the ELF header and section header*/


//functions definition to get offset of string table
int get_offset(Elf32_Shdr *my_sec, Elf32_Ehdr *my_elf)
{
    ///@var
    int index;
    int offset = 0;

    for(index = 0; index < my_elf -> e_shnum; index++){
        if(my_sec -> sh_offset == SHT_STRTAB){
            offset = my_sec -> sh_offset;
            return offset;
        }
        my_sec++;
    }
    return 0;
}

//function to print the Elf header
void print_elf(Elf32_Ehdr *my_elf)
{
    ///@var
    int index;

    printf("ELF Header:\n");    
    fprintf(stdout, "Magic:\t");

    for(index = 0; index < EI_NIDENT ;index++){ //to print magic number
        fprintf(stdout, " %x", my_elf -> e_ident[index]);
    }
    printf("\n");
    /* to print the other field of the ELF header */

    printf("Class:\t\t\t\t\tELF32\n");

    printf("Data:\t\t\t\t\t2's complement, little endian\n");

    printf("Version:\t\t\t\t%d(current)\n",EV_CURRENT);//to print the 
                                                            //current version
    printf("OS/ABI:\t\t\t\t\tUNIX - System V\n"); //OS/ABI name
    
    printf("ABI Version:\t\t\t\t0\n");//version of the ABI

    if(my_elf -> e_type == 1){ //type of the file
        printf("Type:\t\t\t\t\tREF (Relocatable file)\n");
    }
    else if(my_elf -> e_type == 2){
        printf("Type:\t\t\t\t\tEXEC (Executable file)\n");
    } 
    else if(my_elf -> e_type == 4){
        printf("Type:\t\t\t\t\tCORE (Core file)\n");
    }

    if(my_elf -> e_machine == 3){//which machine 
        printf("Machine:\t\t\t\tIntel80386\n");
    }

    if(my_elf -> e_version == 1){//object file version
        printf("Version:\t\t\t\t0x%d\n",EV_CURRENT);
    }
    else if(my_elf -> e_version == 0){
        printf("Version:\t\t\t\tInvalid ELF version\n");
    } 
    
    printf("Entry point address:\t\t\t%u\n", my_elf -> e_entry);

    printf("Start of program headers:\t\t%d\n", my_elf -> e_phoff);

    printf("Start of section header:\t\t%d\n", my_elf -> e_shoff);

    printf("Flags:\t\t\t\t\t0x%x\n", my_elf -> e_flags);

    printf("Size of the header:\t\t\t%d\n", my_elf -> e_ehsize);

    printf("Size of the program headers:\t\t%d\n", my_elf -> e_phentsize);

    printf("Number of program headers:\t\t%d\n", my_elf -> e_phnum);

    printf("Size of section header:\t\t\t%d\n",my_elf -> e_shentsize);

    printf("Number of section header:\t\t%d\n", my_elf -> e_shnum);

    printf("Section header string table index:\t%d\n", my_elf -> e_shstrndx);    

}
//function to print the section header table
void print_section(Elf32_Ehdr *my_elf, FILE *fp)
{
    ///structure instance
    Elf32_Shdr *my_sec = NULL;

    ///@var
    char *str = NULL;
    int index;
    //int offset = 0;
    //int previous = 0;

    str = (char *) malloc (sizeof(Elf32_Shdr));
    assert(str);

    printf("[Nr] Name\t\tType\t\tAddr\tOff\tSize\tEs Flg Lk Inf Al\n");
    fseek(fp, my_elf -> e_shoff, SEEK_SET);

    for(index = 0; index < (my_elf -> e_shnum) ; index++){

        my_sec = (Elf32_Shdr*) malloc( sizeof(Elf32_Shdr));
        assert(my_sec); 

        fread(my_sec, sizeof(Elf32_Shdr), 1, fp);

       /* offset = get_offset(my_sec, my_elf);
        printf("%d\n", offset);
        offset = offset + (my_sec -> sh_name);

        previous = ftell(fp);
        fseek(fp, offset, SEEK_CUR);
        fread(str, 20, 1, fp);
        printf("%s\n", str);
        fseek(fp, previous, SEEK_SET);*/
        printf("[%d]\t\t\t", index);

        switch(my_sec -> sh_type){
            case 0: printf("NULL\t\t");
                    break;
            case 1: printf("PROGBITS\t");
                    break;
            case 2: printf("SYMTAB\t\t");
                    break;
            case 3: printf("STRTAB\t\t");
                    break;
            case 4: printf("RELA\t\t");
                    break;
            case 5: printf("HASH\t");
                    break;
            case 6: printf("DYNAMIC\t\t");
                    break;
            case 7: printf("NOTE\t\t");
                    break;
            case 8: printf("BSS\t\t");
                    break;
            case 9: printf("REL\t\t");
                    break;
            case 10: printf("SHLIB\t\t");
                     break;
            case 11: printf("DYNSYM\t\t");
                     break;
            case 14: printf("INIT_ARRAY\t");
                     break;
            case 15: printf("FINI_ARRAY\t");
                     break;
            case  0x6ffffffe: printf("VERNEED\t\t");
                              break;
            case  0x6fffffff : printf("VERSYM\t\t");
                               break;
            case  0x6ffffff6 : printf("GNU_HASH\t");
                               break;
            case 0x6ffffff5 : printf("GNU_ATTRIBUTES\t");
                              break;
        }
        printf("%u\t", my_sec -> sh_addr);
        printf("%u\t", my_sec -> sh_offset);
        printf("%d\t", my_sec -> sh_size);
        printf("%d", my_sec -> sh_entsize);
        print_flags(my_sec -> sh_flags);
        printf(" %d", my_sec -> sh_link);
        printf(" %d", my_sec -> sh_link);
        printf(" %d\n", my_sec -> sh_addralign);

        my_sec++;
    }
    return;
}

//function to get the flags
void print_flags(unsigned int flag)
{
        if((flag) & (1 << 0)){
            printf("W");
        }
        else if((flag) & (1 << 1)){
            printf("A");
        }
        else if((flag) & (1 << 2)){
            printf("X");
        }
        else if((flag) & (1 << 4)){
            printf("M");
        }
        else if((flag) & (1 << 5)){
            printf("S");
        }
        return;
}
