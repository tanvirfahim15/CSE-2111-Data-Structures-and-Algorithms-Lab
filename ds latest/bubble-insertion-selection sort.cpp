#include <bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int cnt)
{
    int i,j;
    for(i=0; i<cnt; i++)
    {
        for(j=0; j<cnt-i-1; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}
void selectionsort(int a[],int cnt)
{
    int i,j;
    for(i=0; i<cnt-1; i++)
    {
        int m=i;
        for(j=i+1; j<cnt; j++)
        {
            if(a[j]<a[m])m=j;
        }
        swap(a[m],a[i]);
    }
}

void insertionsort(int a[],int cnt){
    int i,j;
    for(i=1;i<cnt;i++){
        j=i;
        while(j>0&&a[j]<a[j-1]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
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



    insertionsort(a,cnt);



    for(i=0; i<cnt; i++)
        printf("%d ",a[i]);

}
