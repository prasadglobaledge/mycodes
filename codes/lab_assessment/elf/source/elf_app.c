/**@brief Application program for Readelf imlementation */


///main function
int main (int argc, char *argv[])
{
    ///structure instance
    Elf32_Ehdr *my_elf = NULL;

    my_elf = (Elf32_Ehdr *) malloc (SIZE_ELF * sizeof(char));
    assert(my_elf);

    ///File pointer
    FILE *fp = NULL;

    /*
    char *str = "\177ELF";
    char *str1 = NULL; //to validate the format of the file

    str1 = (char *)malloc(SIZE_MAGIC * sizeof(char));
    assert(str1);*/

    fp = fopen(argv[1], "r");//opening a ELF format file
    assert(fp); //validating the file pointer
    fread(my_elf, SIZE_BYTE, SIZE_ELF, fp);//reading the first 52 bytes of ELF
    
    print_elf(my_elf);//printing the Elf header
    rewind(fp);
    print_section(my_elf,fp);//printing the section header

    return 0;

}
