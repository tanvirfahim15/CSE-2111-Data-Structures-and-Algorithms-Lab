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


};

int main()
{
    printf("1:insert first\n2:insert last\n3:print\n4:delete first\n5:delete last\n6:is empty?\n7:search from head\n8:search from tail\n");
    ll a;
    int c;
    int n,k;
    scanf("%d %d",&n,&k);
    for(c=1;c<=n;c++)
        a.insertl(c);

    while(1)
    {
        scanf("%d",&c);
        if(c==1)
        {
            int v;
            scanf("%d",&v);
            a.insertf(v);
        }
        else if(c==2)
        {
            int v;
            scanf("%d",&v);
            a.insertl(v);
        }
        else if(c==3)
            a.pr();
        else if(c==4)
            printf("%d\n",a.deletef());
        else if(c==5)
            printf("%d\n",a.deletel());
        else if(c==6)
            printf("%d\n",a.isempty());
        else if(c==7)
        {
            int i;
            scanf("%d",&i);
            printf("%d\n",a.srchh(i));
        }
        else if(c==8)
        {
            int i;
            scanf("%d",&i);
            printf("%d\n",a.srcht(i));
        }
        else
            break;
    }
}
