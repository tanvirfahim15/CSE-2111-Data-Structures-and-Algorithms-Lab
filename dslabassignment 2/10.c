#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int linearsrch(int a[],int n,int x)
{
    if(n==0)
        return -1;
    if(a[n-1]==x)
        return n-1;
    return linearsrch(a,n-1,x);

}
main()
{
    int a[100];
    int i,n,x;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    printf("%d",linearsrch(a,n,x));

}
