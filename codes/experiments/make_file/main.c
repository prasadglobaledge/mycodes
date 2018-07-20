#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int main()
{
    int a = 10;
    int b = 2;
    int res;

    res = add(a,b);
    printf("%d\n",res);
    res = sub(a,b);
    printf("%d\n",res);
    res = mul(a,b);
    printf("%d\n",res);
    res = div(a,b);
    printf("%d\n",res);
    return 0;
}
