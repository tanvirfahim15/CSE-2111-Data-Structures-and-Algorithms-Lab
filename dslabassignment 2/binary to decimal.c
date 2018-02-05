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
int binarytodecimal(int b,int c)
{
    if(b==0)
        return 0;
    return c*b%10+binarytodecimal(b/10,c*2);
}
main()
{
    printf("%d",binarytodecimal(11,1));
}
