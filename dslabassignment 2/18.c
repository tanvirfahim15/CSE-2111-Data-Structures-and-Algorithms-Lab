#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void sswap(int a[],int j,int i)
{
    if(j<0)
        return;
    if(a[i]<a[j])
    {
        int y=a[j];
        a[j]=a[i];
        a[i]=y;
    }
    sswap(a,j-1,i);

}

void ssort(int a[],int i)
{

    if(i<0)
        return;
    sswap(a,i-1,i);
    ssort(a,i-1);

}

main()
{

    int a[2000];
    int i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);


    ssort(a,n-1);
    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
