#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ll
{
    struct node
    {
        int val;
        node * prev;
        node * next;
    };
    node *head=NULL;
    node *tail=NULL;
    void insertl(int v)
    {
        node* a;
        a= (node *)malloc(sizeof(node));
        a->val=v;
        a->next=NULL;
        a->prev=NULL;
        if(head==NULL)
        {
            head=a;
            tail=a;
            a->next=a;
            a->prev=a;
        }
        else
        {
            a->prev=tail;
            tail->next=a;
            tail=tail->next;
            tail->next=head;
            head->prev=tail;
        }

    }
    int deletef()
    {
        int x;
        if(head==NULL)
            x=-1;
        else
        {
            x=head->val;
            if(head->next==head)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {

                head=head->next;
                head->prev=tail;
                tail->next=head;
            }
        }
        return x;
    }


    void pr()
    {
        node *p;
        p=head;
        if(p==NULL)
            printf("empty");
        else
        {
            while(1)
            {
                printf("%d ",p->val);
                if(p!=tail)
                    p=p->next;
                else
                    break;
            }
        }
        printf("\n");
    }
    int isempty()
    {
        if(head==NULL)
            return 1;
        return 0;
    }


};

struct que
{
    ll a;
    void enq(int v)
    {
        a.insertl(v);
    }
    int deq()
    {
        a.deletef();
    }
    int isempty()
    {
        return a.isempty();
    }
    int top()
    {
        if(!a.isempty())
            return a.head->val;
        else
            return -1;
    }
    void pr()
    {
        a.pr();
    }
};

int main()
{
    printf("1:enqueue\n2:dequeue\n3:print\n4:top\n5:is empty?\n");
    que a;
    int c;
    while(1)
    {
        scanf("%d",&c);
        if(c==1)
        {
            int v;
            scanf("%d",&v);
            a.enq(v);
        }
        else if(c==2)
        {

            printf("%d\n",a.deq());
        }
        else if(c==3)
            a.pr();
        else if(c==4)
            printf("%d\n",a.top());
        else if(c==5)
            printf("%d\n",a.isempty());
        else
            break;
    }
}
