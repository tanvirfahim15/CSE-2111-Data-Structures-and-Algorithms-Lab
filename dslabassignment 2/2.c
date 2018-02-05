#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void print(int n)
{
    if(n==0)
        return;

    printf("%d ",n);
    print(n-1);
}
main()
{
    int n;
    scanf("%d",&n);
    print(n);

}
