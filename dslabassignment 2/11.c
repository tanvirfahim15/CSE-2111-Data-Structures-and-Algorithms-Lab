#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int bn(int a[],int n,int x)
{
    int m=n/2;
    if(n<0)
        return -1;
    if(a[m]==x)
        return m;
    if(a[m]>x)
        return bn(a,m-1,x);
    if(a[m]<x)
    {
        int tmp=bn(a+m+1,n-m,x);
        if(tmp==-1)
            return tmp;
        return m+1+tmp;
    }


}
main()
{

    int a[2000];
    int i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    printf("%d",bn(a,n-1,x));

}
