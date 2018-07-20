#include <stdio.h>

int a = 10;
int c = a;

int main (void) 
{
    int b = 20;
    int d = b;

    printf ("%d\n%d\n", d, c);

    return 0;

}
