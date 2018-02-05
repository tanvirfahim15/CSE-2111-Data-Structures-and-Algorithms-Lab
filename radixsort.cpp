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
    void insertf(int v)
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
        }
        else
        {
            a->next=head;
            head->prev=a;
            head=head->prev;
        }

    }
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
        }
        else
        {
            a->prev=tail;
            tail->next=a;
            tail=tail->next;
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
            if(head->next)
            {
                head=head->next;
                head->prev=NULL;
            }
            else
            {
                head=NULL;
                tail=NULL;
            }
        }
        return x;
    }
    int deletel()
    {
        int x;
        if(tail==NULL)
            x=-1;
        else
        {
            x=tail->val;
            if(tail->prev)
            {
                tail=tail->prev;
                tail->next=NULL;
            }
            else
            {
                head=NULL;
                tail=NULL;
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
                if(p->next)
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
    int a[1000];
    que q[10];
    int i,j,n,m=10,d=10;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    while(d)
    {
        for(i=0; i<n; i++)
        {
            int x=a[i]%m;
            x/=(m/10);
            q[x].enq(a[i]);

        }
        int x=0;
        for(i=0; i<10; i++)
        {
            while(!q[i].isempty())
            {
                a[x]=q[i].deq();
                x++;
            }
        }
        m*=10;
        d--;
    }
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
}
