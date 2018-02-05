#include <bits/stdc++.h>
using namespace std;

int part(int arr[],int  low,int  high);
void qsort(int a[],int l,int h)
{
    if(l>=h)return;
    int p=part(a,l,h);
    qsort(a,l,p-1);
    qsort(a,p+1,h);
}
int part(int arr[],int  low,int  high)
{
    int pivot;
    pivot = arr[high];
    int i,j;
    i = (low - 1)  ;

    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap (arr[i],arr[j]);
        }
    }
    swap (arr[i + 1], arr[high]);
    return (i + 1);
}
main()
{
    srand(time(NULL));

    int a[100];
    int i=0,j;
    int x=10;
    while(x--)
    {
        a[i]=rand()%100;
        i++;
    }

    int cnt=i;
    for(i=0; i<cnt; i++)
        printf("%d ",a[i]);
    puts("");
    puts("");



    qsort(a,0,cnt-1);



    for(i=0; i<cnt; i++)
        printf("%d ",a[i]);

}
