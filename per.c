#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int a[50];

void print(int l,int r)
{
    if(l==r)
    {
        int i;
        for(i=1; i<=r; i++)
            print("%d ",a[i]);
        puts("");
        return;
    }
    int i;
    for(i=l;i<=r;i++)
    {

    }



}
main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        a[i]=i;
    print(0,n);

}
