#include <bits/stdc++.h>
using namespace std;
struct dll
{
    struct node
    {
        int val;
        node* next;
        node* prev;
    };
    node* head=NULL;
    node* tail=NULL;
    void insertlast(int x)
    {
        node* temp=new node();
        temp->val=x;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=tail->next;
        }

    }
    void insertfirst(int x)
    {
        node* temp=new node();
        temp->val=x;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            head->prev=temp;
            temp->next=head;
            head=head->prev;
        }
    }
    int deletelast()
    {
        if(tail)
        {
            int x=tail->val;
            if(head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
                tail=tail->prev;
                tail->next=NULL;
            }
            return x;
        }
        return -1;
    }
    int deletefirst()
    {
        if(head)
        {
            int x=head->val;
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
            return x;
        }
        return -1;
    }
    void print()
    {
        node* temp=head;
        while(temp)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        puts("");
    }
    int search(int x){
        node* temp=head;
        while(temp){
            if(temp->val==x)
                return 1;
            temp=temp->next;
        }
        return 0;
    }
    node* ssearch(int x){
        node* temp=head;
        while(temp){
            if(temp->val==x)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    void deleteme(node* p){
        if(!p)return;
        if(head==p)
            deletefirst();
        else if(tail==p)
        deletelast();
        else{
            node* f=p->prev;
            node* l=p->next;
            f->next=l;
            l->prev=f;
        }
    }

};
struct deq{
    dll a;
    int isempty(){
        return a.head==NULL;
    }
    void enqf(int x){
        a.insertfirst(x);
    }
    int deqf(){
        return a.deletefirst();
    }
    void enql(int x){
        a.insertlast(x);
    }
    int deql(){
        return a.deletelast();
    }
    void print(){
        a.print();
    }
};
main()
{
    freopen("input.txt","r",stdin);
    printf("1.Insert last(x)\n2.print\n3.Insert first(x)\n4.delete first\n5.delete last\n\n");
    int cmd;
    deq a;
    while(1)
    {
        scanf("%d",&cmd);
        if(cmd==1)
        {
            int x;
            scanf("%d",&x);
            a.enql(x);

        }
        else if(cmd==2)
        {
            a.print();

        }
        else if(cmd==3)
        {
            int x;
            scanf("%d",&x);
            a.enqf(x);
        }
        else if(cmd==4)
        {
            printf("%d\n",a.deqf());

        }
        else if(cmd==5)
        {
            printf("%d\n",a.deql());
        }
        else
            break;
    }
}
