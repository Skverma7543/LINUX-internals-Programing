#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<string.h>

int main()
{
    struct rlimit v;
    static char s[10];
    strcpy(s,"abcdefgh");
    
    getrlimit(RLIMIT_DATA,&v);
    printf("soft limit=%lu    hard limit=%lu\n",v.rlim_cur,v.rlim_max);
    v.rlim_cur=0;
    setrlimit(RLIMIT_DATA,&v);
    getrlimit(RLIMIT_DATA,&v);
    printf("soft limit=%lu    hard limit=%lu\n",v.rlim_cur,v.rlim_max);
}