#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    int b;
    int c = 0;
    char *str = NULL;
    char *ap = NULL;
    char *bp = NULL;
    char *cp = NULL;
    int index;

    str = (char *)malloc(sizeof(int));
    if(str == NULL)
    {
        printf("MA failed\n");
        exit(1);
    }

    printf("enter the value of a \n");
    fgets(str, sizeof(int), stdin);
    a = atoi(str);
    printf("enter the value of b\n");
    __fpurge(stdin);
    fgets(str, sizeof(int), stdin);
    b = atoi(str);

    ap = (char *)&a;
    bp = (char *)&b;
    cp = (char *)&c;

    for(index = 0;index < 4;index++)
    {
        printf("%d %d %d\n",*ap, *bp, *cp);
        *cp = (*ap + *bp)/2;
        printf("value of c%d=a%d+b%d is : %x\n",index,index,index,*cp);
        ap++;
        bp++;
        cp++;    
    }
    return 0;
}
