#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int main()
{
    struct rlimit v;
    getrlimit(RLIMIT_FSIZE,&v);
    printf("soft limit=%lu    hard limit=%lu\n",v.rlim_cur,v.rlim_max);
    v.rlim_cur=0;
    setrlimit(RLIMIT_FSIZE,&v);
    getrlimit(RLIMIT_FSIZE,&v);
    printf("soft limit=%lu    hard limit=%lu\n",v.rlim_cur,v.rlim_max);
}