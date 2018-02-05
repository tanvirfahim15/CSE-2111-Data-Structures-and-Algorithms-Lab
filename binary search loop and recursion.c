#include<stdio.h>
#include<string.h>
int a[20000],b[200000];
int bn(int low,int high,int x)
{
    int mid=(low+high)/2;
    if(low>high)
        return -1;
    if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
    return bn(low,mid-1,x);
    else if(a[mid]<x)
    return bn(mid+1,high,x);
}
main()
{
    int i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    scanf("%d",&x);
    int low=0,high=n-1,mid;
    while(1)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
         break;
        else if(low>high)
        {
            mid=-1;
            break;
        }
        else if(a[mid]>x)
         high=mid-1;
        else if(a[mid]<x)
         low=mid+1;
    }
    // mid=bn(low,high,x);
    if(mid>=0)
    {
        printf("%d",mid);
    }
    else
     printf("not found");

}
