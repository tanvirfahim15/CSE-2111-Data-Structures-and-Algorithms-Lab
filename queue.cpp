#include<stdio.h>
struct q{
    int a[1000];
    int tp=-1;
    void enq(int x){
        if(tp+1==100)
            printf("queue if full");
        else{

        tp++;
        a[tp]=x;
        }
    }
    int deq()
    {
        if(tp==-1)
            printf("queue empty");
        else
        {
            int x=a[0];
            int i;
            for(i=0;i<tp;i++)
                a[i]=a[i+1];
            tp--;
            return x;
        }
        return -1;

    }


    void printq()
    {
        int i;
        for(i=0;i<=tp;i++)
            printf("%d ",a[i]);
        printf("\n");
    }


};
main(){
    q a;
    int i;
    for(i=0;i<5;i++)
    a.enq(i);

    for(i=0;i<=5;i++)
    {
        printf("%d ",a.deq());
    }
}
