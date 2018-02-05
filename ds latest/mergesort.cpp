#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int h);
void mergesort(int a[],int l,int h)
{
    if(l==h)
        return;
    else
    {
        int m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}
void merge(int a[],int l,int m,int h)
{
    int b[100];
    int i=0;
    int l1=l,l2=m+1;
    int h1=m,h2=h;
    while(l1<=h1&&l2<=h2)
    {
        if(a[l1]<a[l2])
        {
            b[i++]=a[l1++];

        }
        else
        {
            b[i++]=a[l2++];
        }
    }
    while(l1<=h1){
            b[i++]=a[l1++];

    }
    while(l2<=h2){
               b[i++]=a[l2++];

    }
    for(i=l;i<=h;i++){
        a[i]=b[i-l];
    }
}
main()
{
    srand(time(NULL));

    int a[100];
    int i=0,j;
    int x=10;
    while(x--)
    {
        a[i]=rand()%100;
        i++;
    }

    int cnt=i;
    for(i=0; i<cnt; i++)
        printf("%d ",a[i]);
    puts("");
    puts("");



    mergesort(a,0,cnt-1);



    for(i=0; i<cnt; i++)
        printf("%d ",a[i]);

}
