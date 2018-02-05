#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
swap(int *x,int *y)
{
    int z=*x;
    *x=*y;
    *y=z;
}
void toh(int s,int m,int d,int n)
{
    if(n==1)
    {
        printf("%d from %d to %d\n",n,s,d);
        return;
    }
    else{
        toh(s,d,m,n-1);
        printf("%d from %d to %d\n",n,s,d);
        toh(m,s,d,n-1);
    }

}
main()
{
    toh(1,2,3,3);
}
