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
int palcheck(char c[],int l,int h)
{
    if(l>h)
        return 1;
    if(c[l]!=c[h])
        return -1;
    return palcheck(c,l+1,h-1);
}
main()
{
    char c[50]="trtrtrt";
    printf("%d",palcheck(c,0,6));
}
