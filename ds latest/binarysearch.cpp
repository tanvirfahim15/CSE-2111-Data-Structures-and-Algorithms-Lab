#include <bits/stdc++.h>
using namespace std;
int bnsearch(int a[],int l,int h,int x){
    int m=(l+h)/2;
    if(a[m]==x)return 1;
    if(l==h) return 0;
    if(a[m]<x)
        bnsearch(a,m+1,h,x);
    else
        bnsearch(a,l,m-1,x);
}
main()
{
    int a[10]={1,2,3,4,5,6,7};
    printf("%d",bnsearch(a,0,6,3));
}
