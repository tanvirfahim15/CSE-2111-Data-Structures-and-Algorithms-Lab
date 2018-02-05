#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int a[50][50],b[50][50],c[50][50];

loop1(int i,int n1,int m1,int m2)
{
    if(i==n1)
        return;
    loop2(i,0,n1,m1,m2);
    loop1(i+1,n1,m1,m2);
}

loop2(int i,int j,int n1,int m1,int m2)
{
    if(j==m2)
        return;
    else
    {
        c[i][j]=loop3(0,m1,i,j);
        return loop2(i,j+1,n1,m1,m2);
    }
}

int loop3(int k,int m1,int i,int j)
{
    if(k==m1)
        return 0;
    return a[i][k]*b[k][j]+loop3(k+1,m1,i,j);
}
main()
{
    int i,j,k,n1,m1,n2,m2;
    scanf("%d %d",&n1,&m1);
    for(i=0; i<n1; i++)
    {
        for(j=0; j<m1; j++)
            scanf("%d",&a[i][j]);
    }
    scanf("%d %d",&n2,&m2);
    for(i=0; i<n2; i++)
    {
        for(j=0; j<m2; j++)
            scanf("%d",&b[i][j]);
    }
    /*
    for(i=0; i<n1; i++)
    {
        for(j=0; j<m2; j++)
        {
            int s=0;
            for(k=0; k<m1; k++)
                s+=a[i][k]*b[k][j];
            c[i][j]=s;
        }
    }*/
    loop1(0,n1,m1,m2);
    for(i=0; i<n1; i++)
    {
        for(j=0; j<m2; j++)
        {
            printf("%d ",c[i][j]);
        }
        puts("");
    }

}
