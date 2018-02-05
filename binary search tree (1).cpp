#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
struct bnst
{
    struct node
    {


        node* left;
        node * right;
        node* parent;

    };
    node *root=NULL;
    void insert(int x)
    {
        node* a=(node*)malloc(sizeof(node));//new node()
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
                if(temp->val>=x&&temp->left==NULL)
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

                if(temp->val>=x)
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
            if(a==root)
                root=root->right;
            else if(a->parent->left==a)
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
            if(a==root)
                root=root->left;
            else if(a->parent->left==a)
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
    printf("1.insert 2.search 3.delete 4. print\n");
    int x;
    while(1)
    {

        scanf("%d",&x);
        if(x==1)
        {
            int y;
            scanf("%d",&y);
            b.insert(y);
        }
        else if(x==2)
        {
            int y;
            scanf("%d",&y);
            if(b.ssearch(b.root,y))
                printf("found\n");
            else
                printf("not found\n");
        }
        else if(x==3)
        {
            int y;
            scanf("%d",&y);
            if(b.ssearch(b.root,y))
            {
                b.deleteme(b.search(b.root,y));
            }
        }
        else if(x==4)
        {
            b.trvrs(b.root);
            printf("\n");
        }
        else
            break;
    }
}
