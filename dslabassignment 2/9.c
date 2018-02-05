#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int sum(int a[],int n)
{
    if(n==1)
        return a[0];
    return a[n-1]+sum(a,n-1);

}
main()
{
    int a[100];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",sum(a,n));

}
