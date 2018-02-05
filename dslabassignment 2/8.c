#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int indexmaxvalue(int a[],int n)
{
    if(n==1)
        return 0;
    int tmp=indexmaxvalue(a,n-1);
    if(a[n-1]>a[tmp])
    return n-1;
    return tmp;

}
main()
{
    int a[100];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",indexmaxvalue(a,n));

}
