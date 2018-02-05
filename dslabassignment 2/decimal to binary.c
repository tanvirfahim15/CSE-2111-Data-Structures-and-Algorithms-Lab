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
decimaltobinary(int n)
{
    if(n==0)
        return;
    decimaltobinary(n/2);
    printf("%d",n%2);
}
main()
{
    decimaltobinary(2);
}
