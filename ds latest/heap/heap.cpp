#include <bits/stdc++.h>
using namespace std;
struct heap{
    int a[1000];
    int in=0;

    void insert(int x){
        in++;
        a[in]=x;
        shiftup(in);
    }
    void shiftup(int n){
            while(n){
                if(a[n/2]<a[n]&&a[n/2])
                    swap(a[n/2],a[n]);
                n/=2;
            }
    }
    void shiftdown(int n){
        if(n*2+1<=in&&a[n]<a[n*2]&&a[n]<a[n*2+1]&&a[n*2+1]>=a[n*2])
        {
            swap(a[n],a[n*2+1]);
            shiftdown(n*2+1);
        }
        else if(n*2<=in){
            swap(a[n],a[n*2]);
        }
    }
    int deletemax(){
        if(in==0)return -1;
        int x=a[1];
        swap(a[1],a[in]);
        in--;
        shiftdown(1);
        return x;
    }
};
main()
{
    freopen("input.txt","r",stdin);
    int cmd;
    heap a;
    while(1)
    {
        scanf("%d",&cmd);
        if(cmd==1)
        {
            int x;
            scanf("%d",&x);
            a.insert(x);

        }
        else if(cmd==2)
        {
            printf("%d\n",a.deletemax());
        }

        else
            break;
    }
}
