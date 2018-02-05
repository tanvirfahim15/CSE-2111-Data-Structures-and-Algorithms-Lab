#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void print(int n)
{
    if(n==0)
        return;
    print(n-1);
    printf("%d ",n);

}
main()
{
    int n;
    scanf("%d",&n);
    print(n);

}
