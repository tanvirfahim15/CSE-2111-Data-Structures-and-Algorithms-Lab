#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int fib(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fib(n-1)+fib(n-2);

}
main()
{

    int n;
    scanf("%d",&n);
    printf("%d",fib(n));

}
