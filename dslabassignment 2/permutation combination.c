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


per(int a[],int l,int h)
{
    int i=0;
    if(l==h)
    {
        for(i=1;i<=h;i++)
            printf("%d ",a[i]);
        puts("");
    }
    for(i=l;i<=h;i++)
    {
        swap(a+l,a+i);
        per(a,l+1,h);
        swap(a+l,a+i);
    }
}
comb(int a[],int n,int r,int s)
{
    int i;
    for(i=n;i>=r;i--)
    {
        a[r-1]=i;
        if(r>1)
        {
            comb(a,i-1,r-1,s);
        }
        else
        {
            int j;
            for(j=0;j<s;j++)
                printf("%d ",a[j] );
            puts("");
        }
    }
}
main()
{
    int a[10]={1,2,3,4,5,6,7,8,9};
    comb(a,4,2,2);
    int b[10]={0,1,2,3,4,5,6,7,8,9};
    per(b,1,3);
}
