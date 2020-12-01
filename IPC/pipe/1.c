#include<unistd.h>
#include<stdio.h>
int main()
{
int pipefd[2];
if(fork())
{
printf("parent-->pid=%d   ppid=%d\n",getpid(),getppid());
}
else
{

printf("child-->pid=%d   ppid=%d\n",getpid(),getppid());
}

}
