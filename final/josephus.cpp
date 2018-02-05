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
            a->next=a;
            a->prev=a;
        }
        else
        {
            head->prev=a;
            a->next=head;
            head=head->prev;
            head->prev=tail;
            tail->next=head;
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


    int deletel()
    {
        int x;
        if(tail==NULL)
            x=-1;
        else
        {
            x=tail->val;
            if(tail->prev==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
                tail=tail->prev;
                tail->next=head;
                head->prev=tail;
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
    int srchh(int v)
    {
        node *p=head;
        int i=1;
        while(1)
        {
            if(p->val==v)
                break;
            if(p->next==head)
            {
                i=-1;
                break;
            }
            i++;
            p=p->next;
        }
        return i;
    }
    int srcht(int v)
    {
        node *p=tail;
        int i=1;
        while(1)
        {
            if(p->val==v)
                break;
            if(p->next==tail)
            {
                i=-1;
                break;
            }
            i++;
            p=p->next;
        }
        return i;
    }
    void j(int n,int k)
    {
        node *p;
        p=head;
        while(1)
        {
            int y=k-1;
            while(y)
            {
                p=p->next;
                if(p->val)
                    y--;
            }
            p->val=0;
            n--;
            while(!p->val)
                p=p->next;
            if(n==1)
            {
                printf("%d",p->val);
                break;
            }
        }
    }


};

int main()
{
    ll a;
    int c;
    int n,k;
    scanf("%d %d",&n,&k);
    for(c=1; c<=n; c++)
        a.insertl(c);
    a.j(n,k);

}
