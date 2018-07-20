#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int main()
{
    int a[SIZE] = {0, 2, 3, 5, 9};
    int s[SIZE] = {3, 3, 2, 5, 3};
    int TAT = 0;
    int sum = 0;
    int i;

    printf("---------------------------------------------------------\n");
    printf("process |\tP1\tP2\tP3\tP4\tP5\n");
    printf("Arrival |\t%d\t%d\t%d\t%d\t%d\n", a[0], a[1], a[2], a[3], a[4]);
    printf("service |\t%d\t%d\t%d\t%d\t%d\n", s[0], s[1], s[2], s[3], s[4]);
    printf("---------------------------------------------------------\n");
    printf("TAT     |\t");
    for(i = 0;i < 5;i++)
    {
        if(i == 0)
        {
            TAT = TAT + (s[i] - a[i]);
            printf("%d\t", TAT);
            sum = TAT;
        }
        else
        {
            sum = sum + s[i];
            TAT = sum - a[i];
            printf("%d\t", TAT);
        }
    }
    printf("\n");
    return 0;
}
