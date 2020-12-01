#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int main()
{
    struct rlimit v;
    getrlimit(RLIMIT_CPU,&v);
    printf("soft limit=%lu    hardlimit=%lu \n",v.rlim_cur,v.rlim_max);
    //1//v.rlim_cur=0;
    //2//v.rlim_cur=5; //after 5 sec cpu limit will exceeded
    v.rlim_cur=5;
    v.rlim_max=5;   //after reaching hardlimit it is not show cpu time exceed it will show killed
    setrlimit(RLIMIT_CPU,&v);
    getrlimit(RLIMIT_CPU,&v);
     printf("soft limit=%lu    hardlimit=%lu \n",v.rlim_cur,v.rlim_max);
     while(1);

}
/*output:-
soft limit=18446744073709551615    hardlimit=18446744073709551615 
soft limit=0    hardlimit=18446744073709551615 
CPU time limit exceeded (core dumped)
*/