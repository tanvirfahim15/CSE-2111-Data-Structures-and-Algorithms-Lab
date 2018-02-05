#include<stdio.h>
#include<stdlib.h>
struct ll
{
    struct node
    {
        int val;
        node *next;
        node *prev;
    };
    node *head=NULL;
    node *tail=NULL;
    node *p=NULL ;
    int cnt=0;
    void push(int v)
    {
        cnt++;
        node *a = (node *) malloc(sizeof(node));
        a->val = v;
        a->next = NULL;
        a->prev = NULL;
        if(head==NULL)
        {
            head=a;
            tail=a;
            head->next=tail;
            tail->prev=head;
            head->prev=tail;
            tail->next=head;
            p=head;
        }
        else
        {
            tail->next = a;
            a->prev=tail;
            tail=a;
            tail->next=head;
        }
    }



    void joshp(int k)
    {
        while(k)
        {
            if(p->val)k--;
            if(k==0)
            {
                p->val=0;
                break;
            }
            p=p->next;
        }
        while(!p->val)
        {
            p=p->next;
        }
    }
    int ans()
    {
        return p->val;
    }
    int isempty()
    {
        if(cnt==0)return 1;
        return 0;
    }
};

    int main()
    {
        ll a;
        int i,n,k;
        scanf("%d %d",&n,&k);
        for(i=1; i<=n; i++)
            a.push(i);
        for(i=1; i<=n-1; i++)
            a.joshp(k);
        printf("%d",a.ans());
        return 0;

    }
