#include<stdio.h>
struct cq
{
    int frnt=0,rear=-1,cnt=0,sz=1000;
    int a[1000];
    cq()
    {
        rear+=sz;
    }
    void enq(int x)
    {
        if(cnt==1000)
        {
            printf("Full");
        }
        else
        {
            rear++;
            rear%=sz;
            a[rear]=x;
            cnt++;
        }

    }
    int deq()
    {
        if(cnt==0)
        {
            printf("empty");
            return -1;
        }
        else
        {
            int x=a[frnt];
            frnt++;
            cnt--;
            return x;
        }
    }
    void displayq()
    {
        int i;
        for(i=frnt;i<cnt;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
};

main()
{
    cq a;
    int i;
    for(i=0;i<10;i++)
        a.enq(i);
    a.displayq();
    for(i=0;i<10;i++)
    printf("%d ",a.deq());
    a.deq();
}
