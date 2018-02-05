#include <bits/stdc++.h>
using namespace std;
struct cll
{
    struct node
    {
        int val;
        node* next;
        node* prev;
    };
    node* head=NULL;
    node* tail=NULL;
    int cnt=0;
    void insertlast(int x)
    {
        cnt++;
        node* temp=new node();
        temp->val=x;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
        {
            temp->next=temp;
            temp->prev=temp;
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=tail->next;
            tail->next=head;
            head->prev=tail;
        }

    }
    void insertfirst(int x)
    {
        cnt++;
        node* temp=new node();
        temp->val=x;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
        {
            temp->next=temp;
            temp->prev=temp;
            head=temp;
            tail=temp;
        }
        else
        {
            head->prev=temp;
            temp->next=head;
            head=head->prev;
            head->prev=tail;
            tail->next=head;
        }
    }
    int deletelast()
    {
        if(tail)
        {
            cnt--;
            int x=tail->val;
            if(head==tail)
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
            return x;
        }
        return -1;
    }
    int deletefirst()
    {
        if(head)
        {
            cnt--;
            int x=head->val;
            if(head->next!=head)
            {
                head=head->next;
                head->prev=tail;
                tail->next=head;
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
            if(temp==head)
                break;
        }
        puts("");
    }
    void deleteme(node* p)
    {
        if(!p)return;
        if(head==p)
            deletefirst();
        else if(tail==p)
            deletelast();
        else
        {
            node* f=p->prev;
            node* l=p->next;
            f->next=l;
            l->prev=f;
            cnt--;
        }
    }
    int josephus(int n,int k){
        int i;
        for(i=1;i<=n;i++)
            insertlast(i);
        i=1;
        node* tmp=head;
        while(cnt>1){
            tmp=tmp->next;
            i++;
            if(i%k==0){
                tmp=tmp->prev;
                deleteme(tmp->next);
            }
        }
        return deletefirst();
    }

};
main()
{
    freopen("input.txt","r",stdin);
    printf("1.Insert last(x)\n2.print\n3.Insert first(x)\n4.delete first\n5.delete last\n6.joshephus(n,k)\n");
    int cmd;
    cll a;
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
            int n;
            int k;
            scanf("%d %d ",&n,&k);
            printf("%d\n",a.josephus(n,k));
        }

        else
            break;
    }
}
