#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

main()
{
    int a[100]={9,8,7,6,5,4,3,2,1,9,8,76,6,5,4,3,2,1};
    int i,j,m,n;
    n=18;

    for(i=1;i<n;i++)
    {
        int j=i;
        while(a[j-1]>a[j]&&j!=0)
        {
            int x=a[j];
            a[j]=a[j-1];
            a[j-1]=x;
            j--;
        }
    }

    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
