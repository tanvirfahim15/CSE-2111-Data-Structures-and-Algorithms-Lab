#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void print(int a[],int n)
{
    if(n==0)
        return;
    print(a,n-1);
    if(a[n-1]%3==0)
    printf("%d ",a[n-1]);
}
main()
{
    int a[100];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    print(a,n);

}
