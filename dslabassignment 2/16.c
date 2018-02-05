#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int b[2000];

void merge(int a[],int l,int m,int h)
{
    int l1=l;
    int l2=m+1;
    int i=0;
    while(l1<=m&&l2<=h)
    {
        if(a[l1]<=a[l2])
            b[i++]=a[l1++];
        else
            b[i++]=a[l2++];
    }
    while(l1<=m)
        b[i++]=a[l1++];
    while(l2<=h)
        b[i++]=a[l2++];
    for(i=l;i<=h;i++)
        a[i]=b[i-l];
}
void mergesort(int a[],int l,int h)
{
    int m=(l+h)/2;
    if(l==h)
        return;
    mergesort(a,l,m);
    mergesort(a,m+1,h);

    merge(a,l,m,h);


}
main()
{

    int a[2000];
    int i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
