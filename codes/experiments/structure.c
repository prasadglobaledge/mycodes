#include<stdio.h>
struct st
{
    double a;
    int b;
    float c;
    char d;
}v2={.a=2.45,.b=4,.c=5.2,.d='b'};

int main()
{
    struct st1
    {
        int a;
        int b;
        char c;
    };
   // struct st1 v1={.a=1,.b=2,.c='a'};

  //  printf("%d %d %c\n",v1.a,v1.b,v1.c);
 
    printf("%d\n",sizeof(struct st1));
//    printf("%lf %d %f %c\n",v2.a,v2.b,v2.c,v2.d);

}
