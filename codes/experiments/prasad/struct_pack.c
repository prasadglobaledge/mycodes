#include <stdio.h>

struct tag{
    int __attribute__((packed, aligned ())) a;
//    int b;
  //  double d;
    //int c;
};

int main (void) 
{
    printf ("%d\n", sizeof (struct tag));

    return 0;
}
