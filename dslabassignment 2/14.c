#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int gcd(int a,int b)
{
    if(a%b==0)
    return b;
    return gcd(b,a%b);

}
main()
{

    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));

}
