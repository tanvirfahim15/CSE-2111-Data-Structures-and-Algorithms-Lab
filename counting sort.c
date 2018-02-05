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
int b[10000];
int c[10000];
main()
{
    int a[100]={53,3,6,23,16,32,67,34,78,44,99};
    int i,j;
    for(i=1;i<11;i++)
        c[a[i]]++;
    for(i=1;i<10000;i++)
        c[i]+=c[i-1];
    for(i=10;i>=1;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }
    for(i=1;i<11;i++)
        printf("%d ",b[i]);
}
