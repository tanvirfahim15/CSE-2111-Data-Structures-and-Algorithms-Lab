#include<stdio.h>
#include<stdlib.h>
#include<string.h>




struct dll
{
    struct node
    {
        node* prev;
        node* next;
        int val;
    };
    node* head=NULL;
    node* tail=NULL;
    void insert_first(int x)
    {
        node* a=(node*)malloc(sizeof(node));
        a->prev=NULL;
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
            head->prev=a;
            head=head->prev;
        }
    }

    void insert_last(int x)
    {
        node* a=(node*)malloc(sizeof(node));
        a->prev=NULL;
        a->next=NULL;
        a->val=x;
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




    void insert_after(node* p,int x)
    {
        if(p==tail)
            insert_last(x);
        else
        {
            node* a=(node*)malloc(sizeof(node));
            a->prev=p;
            a->next=p->next;
            a->val=x;
            p->next=a;
            a->next->prev=a;
        }

    }


    void insert_before(node* p,int x)
    {
        if(p==head)
            insert_first(x);
        else
        {
            node* a=(node*)malloc(sizeof(node));
            a->prev=p->prev;
            a->next=p;
            a->val=x;
            p->prev=a;
            a->prev->next=a;
        }

    }

    int delete_first()
    {
        if(head==NULL)
            return -1;
        else if(head->next==NULL)
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
            head->prev=NULL;
            return x;
        }
    }

    int delete_last()
    {
        if(head==NULL)
            return -1;
        else if(head->next==NULL)
        {
            int x=head->val;
            head=NULL;
            tail=NULL;
            return x;
        }
        else
        {
            int x=tail->val;
            tail=tail->prev;
            tail->next=NULL;
            return x;
        }
    }

    int delete_me(node *p)
    {
        if(p==head)
            return delete_first();
        else if(p==tail)
            return delete_last();
        else
        {
            int x=p->val;
            p=p->prev;
            p->next=p->next->next;
            p=p->next;
            p->prev=p->prev->prev;
            return x;
        }
    }

    void print()
    {
        node* p=head;
        while(p)
        {
            printf("%d ",p->val);
            p=p->next;
        }
    }


    void printd()
    {
        node* p=tail;
        while(p)
        {
            printf("%d ",p->val);
            p=p->prev;
        }
    }



    void srt()
    {
        node*p=head;
        int i,j,n=0;
        while(p)
        {
            n++;
            p=p->next;
        }
        for(i=0; i<n-1; i++)
        {
            p=head;
            for(j=0; j<n-1-i; j++)
            {
                if(p->val>p->next->val)
                {
                    int x=p->val;
                    p->val=p->next->val;
                    p->next->val=x;
                }
                p=p->next;
            }
        }
    }








};






















main()
{
    dll a;

    a.insert_last(1);
    a.insert_last(2);
    a.insert_last(3);
    a.insert_last(4);
    a.insert_last(5);
    a.delete_me(a.head->next);
    a.insert_before(a.head->next,99);
    a.print();
    printf("\n");
    a.srt();
    a.printd();


}
