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
main()
{
    freopen("input.txt","r",stdin);
    printf("1.Insert last(x)\n2.print\n3.Insert first(x)\n4.delete first\n5.delete last\n6.search(x)\n7.delete(x)\n");
    int cmd;
    dll a;
    while(1)
    {
        scanf("%d",&cmd);
        if(cmd==1)
        {
            int x;
            scanf("%d",&x);
            a.insertlast(x);

        }
        else if(cmd==2)
        {
            a.print();

        }
        else if(cmd==3)
        {
            int x;
            scanf("%d",&x);
            a.insertfirst(x);
        }
        else if(cmd==4)
        {
            printf("%d\n",a.deletefirst());

        }
        else if(cmd==5)
        {
            printf("%d\n",a.deletelast());
        }
        else if(cmd==6){
            int x;
            scanf("%d",&x);
            if(a.search(x)){
                printf("found(%d)\n",x);
            }
            else
                printf("not found(%d)\n",x);
        }
        else if(cmd==7){
            int x;
            scanf("%d",&x);
            a.deleteme(a.ssearch(x));
        }

        else
            break;
    }
}
