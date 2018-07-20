#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
    int *ptr = NULL;
    int *pt = NULL;

    ptr = malloc (sizeof (int) * 5);
    pt = malloc (10);

    printf ("%d\n", *(ptr - 1));

    *ptr = 20;
    free (ptr);
    //free (ptr);
//    printf ("%d\n", *ptr);
   // ptr = pt;

    *pt = 10;

 //   printf ("%d\n", *ptr);
  //  printf ("%d\n", sizeof (malloc (15)));

    return 0;
}
