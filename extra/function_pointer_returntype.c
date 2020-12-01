#include<stdio.h>
typedef int (*FPTR)(int,int);
int sum(int a, int b)
{
    return a+b;
}
FPTR return_pointer()
{
    return sum;
}
int main()
{
    FPTR p;
    p=return_pointer();
    printf("sum=%d\n",p(10,10));
}