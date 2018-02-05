#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
struct bnst
{
    struct node
    {

        int val;
        node* left;
        node * right;
        node* parent;

    };
    node *root=NULL;
    void insert(int x)
    {
        node* a=(node*)malloc(sizeof(node));
        a->val=x;
        a->left=NULL;
        a->right=NULL;
        a->parent=NULL;
        if(root==NULL)
        {
            root=a;
        }
        else
        {
            node* temp=root;
            while(1)
            {
                if(temp->val>x&&temp->left==NULL)
                {
                    a->parent=temp;
                    temp->left=a;
                    break;
                }
                if(temp->val<x&&temp->right==NULL)
                {
                    a->parent=temp;
                    temp->right=a;
                    break;
                }

                if(temp->val>x)
                {

                    temp=temp->left;

                }
                else if(temp->val<x)
                {
                    temp=temp->right;
                }

            }
        }
    }
    void trvrs(node* a)
    {
        if(a==NULL)
            return;
        trvrs(a->left);


        printf("%d ",a->val);

        trvrs(a->right);
    }
    node* min(node* a)
    {
        if(a->left==NULL)
            return a;
        return min(a->left);
    }
    void deleteme(node* a)
    {
        if(a==NULL)
            return;
        if(a->left==NULL&&a->right==NULL)
        {
            if(a==root)
                root=NULL;
            else if(a->parent->left==a)
            {
                a->parent->left=NULL;
            }
            else if(a->parent->right==a)
            {
                a->parent->right=NULL;
            }
        }
        else if(a->left==NULL)
        {
            if(a->parent->left==a)
            {
                a->parent->left=a->right;
                a->right->parent=a->parent;
            }
            else if(a->parent->right==a)
            {
                a->parent->right=a->right;
                a->right->parent=a->parent;
            }
        }
        else if(a->right==NULL)
        {
            if(a->parent->left==a)
            {
                a->parent->left=a->left;

                a->left->parent=a->parent;
            }
            else if(a->parent->right==a)
            {
                a->parent->right=a->left;

                a->left->parent=a->parent;
            }
        }
        else
        {
            node* x= min(a->right);
            swap(x->val,a->val);
            deleteme(x);
        }
    }
    node* search(node* a,int x)
    {
        if(a==NULL)
            return NULL;
        if(a->val==x)
            return a;
        else if(a->val>x)
            return search(a->left,x);
        else
            return search(a->right,x);

    }

    int ssearch(node* a,int x)
    {
        if(a==NULL)
            return 0;
        if(a->val==x)
            return 1;
        else if(a->val>x)
            return ssearch(a->left,x);
        else
            return ssearch(a->right,x);

    }

};
main()
{
    bnst b;
    b.insert(5);
    b.insert(3);
    b.insert(6);
    b.insert(36);
    b.insert(44);
    b.deleteme(b.search(b.root,36));
    b.deleteme(b.search(b.root,44));
    printf("%d   ",b.ssearch(b.root,44));
    b.trvrs(b.root);
}
