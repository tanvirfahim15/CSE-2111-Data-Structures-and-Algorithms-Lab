#include <bits/stdc++.h>
using namespace std;
struct bnst
{
    struct node
    {
        int val;
        node* left;
        node* right;
        node* parent;
    };
    node*root=NULL;
    void insert(int x)
    {
        node*in=new node();
        in->val=x;
        in->left=NULL;
        in->right=NULL;
        in->parent=NULL;
        if(root)
            ins(root,in);
        else
            root=in;

    }
    void ins(node*p,node*in)
    {
        if(p->val>=in->val&&p->left==NULL)
        {

            p->left=in;
            in->parent=p;
        }
        else if(p->val<in->val&&p->right==NULL)
        {

            p->right=in;
            in->parent=p;
        }
        else if(p->val>=in->val)
            ins(p->left,in);
        else
            ins(p->right,in);

    }
    void inorder()
    {
        inor(root);
    }
    void inor(node*p)
    {
        if(!p)return;
        inor(p->left);
        printf("%d ",p->val);
        inor(p->right);
    }
    int search(int x)
    {
        node*temp=root;
        while(temp)
        {
            if(temp->val==x)
                return 1;
            else if(temp->val>x)
                temp=temp->left;
            else
                temp=temp->right;
        }
        return 0;
    }
    node* ssearch(int x)
    {

        node*temp=root;
        while(temp)
        {
            if(temp->val==x)
                return temp;
            else if(temp->val>x)
                temp=temp->left;
            else
                temp=temp->right;
        }
        return NULL;
    }
    void deleteme(node* p)
    {
        if(!p)return;
        if(p->left==NULL&&p->right==NULL)
        {
            if(p->parent->left==p)
                p->parent->left=NULL;
            else
                p->parent->right=NULL;
        }
        else if(p->left==NULL)
        {
            if(p->parent->left==p)
                p->parent->left=p->right;
            else
                p->parent->right=p->right;
        }
        else if(p->right==NULL)
        {
            if(p->parent->left==p)
                p->parent->left=p->left;
            else
                p->parent->right=p->left;
        }
        else
        {

            node*t=min(p->right);
            swap(t->val,p->val);
            deleteme(t);
        }


    }
    node*min(node*p)
    {
        if(!p->left)
            return p;
        min(p->left);
    }


};
main()
{
    freopen("input.txt","r",stdin);
    int cmd;
    bnst a;
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
            a.inorder();
            puts("");

        }
        else if(cmd==3)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",a.search(x));
        }
        else if(cmd==4)
        {
            int x;
            scanf("%d",&x);
            a.deleteme(a.ssearch(x));
        }
        else
            break;
    }
}
