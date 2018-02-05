#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void bswap(int a[],int start,int stop)
{
    if(start==stop)
        return;
    if(a[start]>a[start+1])
    {
        int x=a[start];
        a[start]=a[start+1];
        a[start+1]=x;
    }
    bswap(a,start+1,stop);
}

void bsort(int a[],int n)
{

    if(n==0)
        return;
    bswap(a,0,n-1);
    bsort(a,n-1);

}




main()
{

    int a[2000]= {1,2,3,4,2,3,4,5};
    int i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    bsort(a,n);

    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
