#include <iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int value;
    int priority;
};

struct pq
{

    node x[100000];
    int xc = 0;

    int getleftchild(int n)
    {
        return x[2 * n].priority;
    }

    int getrightchild(int n)
    {
        return x[2 * n + 1].priority;
    }

    int getmaxchild(int n)
    {
        if (getleftchild(n) < getrightchild(n))
        {
            return 2 * n +1;
        }
        return 2 * n;
    }

    int getparent(int n)
    {
        if(n==1)
            return 0;
        return n/2;
    }
    void shiftup(int n)
    {
        int in=getparent(n);
        if(x[in].priority<x[n].priority&&in!=0)
        {
            node temp=x[in];
            x[in]=x[n];
            x[n]=temp;
            shiftup(in);

        }

    }
    void push(int x,int y)
    {
        node q;
        q.value=x;
        q.priority=y;
        insert(q);
    }
    void insert(node q)
    {
        xc++;
        x[xc]=q;
        shiftup(xc);
    }


    void shiftdown(int n)
    {
        if (n * 2 > xc)
        {
            return;
        }
        else
        {
            if (2 * n + 1 <= xc)
            {

                if (x[n].priority<x[2 * n].priority && x[n].priority < x[2 * n + 1].priority)
                {
                    int in = getmaxchild(n);

                    node temp=x[in];
                    x[in]=x[n];
                    x[n]=temp;
                    shiftdown(in);
                }
                else if (x[n].priority< x[2 * n].priority)
                {

                    int in = 2*n;
                    node temp=x[in];
                    x[in]=x[n];
                    x[n]=temp;
                    shiftdown(in);
                }
                else if (x[n] .priority< x[2 * n+1].priority)
                {
                    int in = 2*n+1;
                    node temp=x[in];
                    x[in]=x[n];
                    x[n]=temp;
                    shiftdown(in);
                }
            }
            else if (x[n].priority< x[2 * n].priority)
            {
                int in = 2*n;
                node temp=x[in];
                x[in]=x[n];
                x[n]=temp;
                shiftdown(in);
            }
        }

    }

    node deletemax()
    {
        node temp=x[1];
        x[1]=x[xc];
        x[xc]=temp;
        xc--;
        shiftdown(1);
        return temp;
    }
    int pop()
    {
        node temp=x[1];
        x[1]=x[xc];
        x[xc]=temp;
        xc--;
        shiftdown(1);
        return temp.value;
    }
    void constructheap(int n)
    {
        int i;
        for (i = n / 2; i >= 1; i--)
        {
            shiftdown(i);
        }

    }
    void print()
    {

        int i;
        for(i=1; i<=xc; i++)
            printf("%d ",x[i].value);
        puts("");
    }

};






int main()
{
    pq a;
    printf("1.insert(value,priority) 2.print 3.pop\n");
    int x;
    while(1)
    {

        scanf("%d",&x);
        if(x==1)
        {
            int y,z;
            scanf("%d %d",&y,&z);
            a.push(y,z);
        }
        else if(x==2)
        {
            a.print();
        }
        else if(x==3)
        {
            printf("%d\n",a.pop());
        }
        else
            break;

    }
}
