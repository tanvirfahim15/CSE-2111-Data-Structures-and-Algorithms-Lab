#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int b[100000];
mrg(int a[],int l,int m,int h)
{
    int i=0;
    int ll=l;
    int l1=m+1;
    while(l<=m&&l1<=h)
    {
        if(a[l]>=a[l1])
            b[i++]=a[l1++];
        else
            b[i++]=a[l++];
    }
    while(l<=m)
    {
        b[i++]=a[l++];
    }
    while(l1<=h)
    {
        b[i++]=a[l1++];
    }
    for(i=ll; i<=h; i++)
    {
        a[i]=b[i-ll];
    }


}
void mm(int a[],int l,int m,int h)
{
    int i=0;
    int ll=l;
    int l1=m+1;
    while(l<=m&&l1<=h)
    {
        if(a[l]<=a[l1])
            b[i++]=a[l++];
        else
            b[i++]=a[l1++];
    }

    while(l<=m)
        b[i++]=a[l++];
    while(l1<=h)
        b[i++]=a[l1++];
    for(i=ll; i<=h; i++)
        a[i]=b[i-ll];

}
void srt(int a[],int l,int h)
{
    int m=(l+h)/2;
    if(l==h)
        return;
    srt(a,0,m);
    srt(a,m+1,h);
    mm(a,0,m,h);
}
main()
{
    int a[100000];
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    srt(a,0,n-1);

    printf("[%d",a[0]);
    for(i=1; i<n; i++)
        printf(",%d",a[i]);
    printf("]");
}
