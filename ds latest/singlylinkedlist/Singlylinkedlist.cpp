#include <bits/stdc++.h>
using namespace std;
struct ll
{
    struct node
    {
        int val;
        node* next;
    };
    node* head=NULL;
    node* tail=NULL;
    void insert(int x)
    {
        node* temp=new node();
        temp->val=x;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    int search(int x)
    {

        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->val==x)
                return 1;
            temp=temp->next;
        }
        return 0;
    }
    void insertbefore(int x,int y)
    {
        node* temp=ssearch(x);
        insertafter(x,y);
        swap(temp->val,temp->next->val);
    }
    void insertafter(int x,int y)
    {
        node* temp=ssearch(x);
        node*a=new node();
        a->val=y;
        a->next=temp->next;
        temp->next=a;
    }
    node *ssearch(int x)
    {

        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->val==x)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    void ddelete(int x)
    {
        if(ssearch(x))
        {
            if(ssearch(x)==head)
                head=head->next;
            else
            {

                node* temp=head;
                while(temp)
                {
                    if(temp->next==ssearch(x))
                    {
                        temp->next=temp->next->next;
                        break;
                    }
                    temp=temp->next;
                }
            }
        }
    }
    void print()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val );
            temp=temp->next;
        }
        puts("");
    }
    void printreverse(node *p)
    {
        if(!p)return;
        printreverse(p->next);
        printf("%d ",p->val);

    }
    int isempty()
    {
        return head==NULL;
    }

};

main()
{
    freopen("input.txt","r",stdin);
    printf("1.Insert(x)\n2.print\n3.search(x)\n4.delete(x)\n5.insert y after x(x,y)\n6.insert y before x(x,y)\n7.print reverse\n\n");
    int cmd;
    ll a;
    while(1)
    {
        scanf("%d",&cmd);
        if(cmd==1)
        {
            int x;
            scanf("%d",&x);
            a.insert(x);
        }
        else if(cmd==2)
        {
            a.print();
        }
        else if(cmd==3)
        {
            int x;
            scanf("%d",&x);
            if(a.search(x)==1)
                printf("found(%d)\n",x);
            else
                printf("not found(%d)\n",x);
        }
        else if(cmd==4)
        {
            int x;
            scanf("%d",&x);
            a.ddelete(x);
        }
        else if(cmd==5)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            a.insertafter(x,y);
        }
        else if(cmd==6)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            a.insertbefore(x,y);
        }
        else if(cmd==7)
        {
            a.printreverse(a.head);
            puts("");
        }

        else
            break;
    }
}
