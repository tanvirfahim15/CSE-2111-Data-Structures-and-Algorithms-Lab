#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
swap(int *x,int *y)
{
    int z=*x;
    *x=*y;
    *y=z;
}
pr(int n)
{
    if(n==0)
        return;
    printf("%d",n%10);
    return pr(n/10);
}
main()
{
    pr(65443);
}
