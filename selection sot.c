#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

main()
{
    int a[100]={9,8,7,6,5,4,3,2,1,9,8,76,6,5,4,3,2,1};
    int i,j,m,n;
    n=20;

    for(i=0;i<n;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
        {
            if(a[m]>a[j])
            {
                int x=a[m];
                a[m]=a[j];
                a[j]=x;
            }
        }
    }

    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
