#include<stdio.h>
typedef int (*FPTR)(int,int);
int sum(int a, int b)
{
    return a+b;
}
int pointer_arg(FPTR p,int a,int b)
{
    return p(a,b);
}
int main()
{
    printf("sum=%d\n",pointer_arg(sum,20,20));
}