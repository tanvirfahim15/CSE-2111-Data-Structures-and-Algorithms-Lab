#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int c(int n,int r)
{
    if(r==1)
        return n;
    if(n==r)
        return 1;
    return c(n-1,r)+c(n-1,r-1);

}
main()
{

    int n,r;
    scanf("%d %d",&n,&r);
    printf("%d",c(n,r));

}
