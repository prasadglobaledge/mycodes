# 1 "1st.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "1st.c"
int main()

 int a,i;

 printf("enter any integer\n");
 scanf("%d",&a);

 for(i=31;i>=0;i--)

  a=a&(1<<i);
  printf("%d",a);
