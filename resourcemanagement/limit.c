#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int main()
{
    struct rlimit v;
    getrlimit(RLIMIT_STACK,&v);
    printf("soft limit=%lu    hard limit=%lu\n",v.rlim_cur,v.rlim_max);
    v.rlim_max=0;
    setrlimit(RLIMIT_STACK,&v);
    getrlimit(RLIMIT_STACK,&v);
    printf("soft limit=%lu    hard limit=%lu\n",v.rlim_cur,v.rlim_max);
}
