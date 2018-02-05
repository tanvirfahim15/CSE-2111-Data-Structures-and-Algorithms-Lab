#include<stdio.h>
struct stk{
    int a[1000];
    int tp=-1;
    void push(int x){
        if(tp+1==1000)
            printf("Stack if full");
        else{

        tp++;
        a[tp]=x;
        }
    }
    int pop()
    {
        if(tp==-1)
            printf("Stack empty");
        else
        {
            tp--;
            return a[tp+1];
        }
        return -1;

    }

    void printstack()
    {
        int i;
        for(i=tp;i>=0;i--)
            printf("%d ",a[i]);
        printf("\n");
    }

};
main(){
    stk a;
    int i;
    for(i=0;i<5;i++)
    a.push(i);

    for(i=0;i<=5;i++)
    {
        printf("%d ",a.pop());
    }

}
