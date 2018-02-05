#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=NULL;
    node *tail=NULL;
    void insert_first(int x)
    {
        //insert x at first
        node *a = (node*)malloc(sizeof(node));
        a->next=NULL;
        a->val=x;
        if(head==NULL)
        {
            head=a;
            tail=a;
        }
        else
        {
            a->next=head;
            head=a;

        }

    }
    void insert_last(int x)
    {
        //insert x at last
        node*a=(node*)malloc(sizeof(node));
        a->next=NULL;
        a->val=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }
    void insert_after(node* p,int x)
    {
        if(p==tail)
            insert_last(x);
        else
        {
            node*a=(node*)malloc(sizeof(node));
            a->val=x;
            a->next=p->next;
            p->next=a;
        }
    }
    void insert_x_after_y(int x,int y)
    {
        node* p=head;
        while(p)
        {
            if(p->val==y)
                insert_after(p,x);
            p=p->next;
        }
    }
    void insert_x_before_y(int x,int y)
    {
        node* p=head;
        while(p)
        {
            if(p->val==y)
                insert_before(p,x);
            p=p->next;
        }
    }
    void insert_before(node *p,int x)
    {
        if(p==head)
            insert_first(x);
        else
        {
            node* t=head;
            while(t->next!=p)
                t=t->next;
            insert_after(t,x);
        }
    }
    int delete_f()
    {
        //delete first element
        /*if(head==NULL)
            return -1;
        if(head==tail)
        {
            int x=head->val;
            head=NULL;
            tail=NULL;
            return x;
        }
        else
        {
            int x=head->val;
            head=head->next;
            return x;
        }*/
        delete_me(head);
    }
    int delete_l()
    {
        //delete last element
        /*if(head==NULL)
            return -1;
        if(head==tail)
        {
            int x=head->val;
            head=NULL;
            tail=NULL;
            return x;
        }
        else
        {
            node *p=head;
            while(p->next!=tail)
                p=p->next;
            int x=tail->val;
            p->next=NULL;
            tail=p;
            return x;
        }*/
        return delete_me(tail);
    }

    int delete_me(node *a)
    {
        //delete any node a
        node* p=head;
        if(head==a)
        {
            if(head==NULL)
                return -1;
            if(head==tail)
            {
                int x=head->val;
                head=NULL;
                tail=NULL;
                return x;
            }
            else
            {
                int x=head->val;
                head=head->next;
                return x;
            }
        }
        else if(tail==a)
        {
            if(head==NULL)
                return -1;
            if(head==tail)
            {
                int x=head->val;
                head=NULL;
                tail=NULL;
                return x;
            }
            else
            {
                node *p=head;
                while(p->next!=tail)
                    p=p->next;
                int x=tail->val;
                p->next=NULL;
                tail=p;
                return x;
            }
        }
        else
        {
            if(head==NULL)
                return -1;
            if(head==tail)
            {
                return -1;
            }
            else
            {
                node *p=head;
                while(p->next!=a)
                    p=p->next;
                int x=a->val;
                p->next=p->next->next;
                return x;
            }
        }
    }
    int srch(int x)
    {
        //not found->return 0||else return index starting from 1,2,...
        node *p=head;
        if(head==NULL)
            return 0;
        int f=0,c=1;
        while(p)
        {
            if(p->val==x)
            {
                f++;
                break;
            }
            c++;
            p=p->next;
        }
        return f*c;
    }


    void delfh(int x)
    {
        //delete the first x
        node *p=head;
        node *tmp;
        if(head==NULL)
            return;
        int f=0;
        while(p)
        {
            if(p->val==x)
            {
                f++;
                tmp=p;
                break;
            }
            p=p->next;
        }
        if(f)
            delete_me(tmp);
    }


    void delft(int x)
    {
        //delete the last x
        node *p=head;
        node *tmp;
        if(head==NULL)
            return;
        int f=0;
        while(p)
        {
            if(p->val==x)
            {
                f++;
                tmp=p;
            }
            p=p->next;
        }
        if(f)
            delete_me(tmp);
    }



    void print()
    {
        node *p=head;
        while(p)
        {
            printf("%d ",p->val);
            p=p->next;
        }
    }
    void printft()
    {

        prd(head);
    }
    void prd(node* p)
    {
        if(p==NULL)
            return;
        prd(p->next);
        printf("%d ",p->val);
    }



};
main()
{
    ll a;
    int i;
    for(i=0; i<5; i++)
        a.insert_last(i);
    a.print();



}
