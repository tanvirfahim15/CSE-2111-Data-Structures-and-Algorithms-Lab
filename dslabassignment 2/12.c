#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);

}
main()
{

    int n;
    scanf("%d",&n);
    printf("%d",fact(n));

}
