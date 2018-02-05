#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int oddcnt(int a[],int n)
{
    if(n==0)
        return 0;
    if(a[n-1]%2==1)
        return 1+oddcnt(a,n-1);
    else return oddcnt(a,n-1);
}
main()
{
    int a[100];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",oddcnt(a,n));

}
