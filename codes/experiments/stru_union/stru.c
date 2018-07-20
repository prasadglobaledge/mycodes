#include<stdio.h>
struct tag{
    int a;
    char b;
    float c;
    struct tag1{
        int a;
        char b;
        float c;
    }var1;
 //   struct tag *ptr;
}var,*ptr = NULL;

int main()
{
  //  int *pt = NULL;
    struct tag var = {.a = 10,.b = 'a', .c = 2.5};
    struct tag1 var1= {.a = 20, .b = 'b', .c =3.5};
    ptr = &var;
    printf("%d\n%c\n%lf\n",ptr -> a, ptr -> b, ptr -> c);
    struct tag1 *ptr1 = NULL;
    printf("sizeof(tag) = %d\n", sizeof(struct tag));
    ptr1 = &var1;
    printf("%d\n%c\n%lf\n",ptr1 -> a, ptr1 -> b, ptr1 -> c);
    return 0;
}
