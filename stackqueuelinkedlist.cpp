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
    node *head = NULL;
    node *tail=NULL;
    void insert_last(int v)
    {
        node *a = (node *) malloc(sizeof(node));
        a->val = v;
        a->next = NULL;
        a->prev=NULL;
        if(head==NULL)
        {
            head=a;
            tail=a;
        }
        else
        {
            tail->next=a;
            a->prev=tail;
            tail=tail->next;
        }
    }
    int del_first()
    {
        if(head==NULL)
        {
            printf("empty\n");
            return -1;
        }
        else if(head->next==NULL)
        {
            int x= head->val;
            head=NULL;
            tail=NULL;
            return x;
        }
        else
        {
            int x;
            x=head->val;
            head=head->next;
            head->prev=NULL;
            return x;
        }
    }
    int del_last()
    {
        if(head==NULL)
        {
            printf("empty\n");
            return -1;
        }
        else if(head->next==NULL)
        {
            int x= head->val;
            head=NULL;
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
    void printlla()
    {
        node *p;
        p=head;
        if(p==NULL)
            printf("empty\n");
        else
        {
            while(1)
        {
            printf("%d ",p->val);
            if(p->next==NULL)
                break;
            else
                p=p->next;
        }
        }
    }

    void printlld()
    {
        node *p;
        p=tail;
        while(1)
        {
            printf("%d ",p->val);
            if(p->prev==NULL)
                break;
            else
                p=p->prev;
        }
    }



};
struct stkq
{

    ll a;

    void push(int v)
    {
        a.insert_last(v);

    }
    void enq(int v)
    {
        a.insert_last(v);

    }
    int deq()
    {
        return a.del_first();
    }
    int pop()
    {
        return a.del_last();
    }
    void displaystack()
    {
        a.printlld();
    }
    void displayq()
    {
        a.printlla();
    }
    int top()
    {
        return a.tail->val;
    }
    int isempty()
    {
        if (a.head==NULL)
            return 1;
        return 0;
    }



};


int main()
{

    stkq a;
    int i;
    for(i=0; i<5; i++)
        a.push(i);
    a.displayq();

       printf("%d ",a.isempty());



}
