#include<stdio.h>
//#pragma pack(2)
struct tag{
//    char a:7
char :0;
      char :1;
int :1;
  //  int f:15;
  // char d:4;
//    char :1;    
};

int main()
{
    printf("%d\n",sizeof(struct tag));
    return 0;
}
