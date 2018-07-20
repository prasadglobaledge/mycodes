#include<stdio.h>
#include<unistd.h>
int main()
{
    unsigned int n;
    read(0,&n,sizeof(int));
    printf("%d\n",n);
    n=n+1;
    write(1,&n,sizeof(int));
    return 0;
}
