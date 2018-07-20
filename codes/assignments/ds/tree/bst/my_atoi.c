/**
 * @brief Converting integer string to integer
 * **/
//Function to convert integer string to integer
int my_atoi(char *str)
{
    int temp = 0;
    int value;
    while((*str != '\0') && (*str != '\n'))
    {
        value= *str - 48;
        temp = (temp * 10) + value;
        str++;
    }
    return temp;
}
