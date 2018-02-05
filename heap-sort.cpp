#include <iostream>
#include<stdio.h>
using namespace std;


struct heap
{

    int x[100000];
    int xc = 0;

    int count()
    {
        return xc;
    }

    int getleftchild(int n)
    {
        return x[2 * n];
    }

    int getrightchild(int n)
    {
        return x[2 * n + 1];
    }

    int getmaxchild(int n)
    {
        if (getleftchild(n) > getrightchild(n))
        {
            return 2 * n;
        }
        return 2 * n + 1;
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
        if(x[in]<x[n]&&in!=0)
        {
            int temp=x[in];
            x[in]=x[n];
            x[n]=temp;
            shiftup(in);

        }

    }
    void insert(int q)
    {
        xc++;
        x[xc]=q;
        shiftup(xc);
    }
    void print()
    {
        int i;
        for (i = 1; i <= xc; i++)
        {
            printf("%d ",x[i]);
        }
        puts("");
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

                if (x[n]< x[2 * n] && x[n] < x[2 * n + 1])
                {
                    int in = getmaxchild(n);

                    int temp=x[in];
                    x[in]=x[n];
                    x[n]=temp;
                    shiftdown(in);
                }
                else if (x[n]< x[2 * n])
                {

                    int in = 2*n;
                    int temp=x[in];
                    x[in]=x[n];
                    x[n]=temp;
                    shiftdown(in);
                }
                else if (x[n] < x[2 * n+1])
                {
                    int in = 2*n+1;
                    int temp=x[in];
                    x[in]=x[n];
                    x[n]=temp;
                    shiftdown(in);
                }
            }
            else if (x[n]< x[2 * n])
            {
                int in = 2*n;
                int temp=x[in];
                x[in]=x[n];
                x[n]=temp;
                shiftdown(in);
            }
        }

    }

    int deletemax()
    {
        int temp=x[1];
        x[1]=x[xc];
        x[xc]=temp;
        xc--;
        shiftdown(1);
        return temp;
    }
    void constructheap(int n)
    {
        int i;
        for (i = n / 2; i >= 1; i--)
        {
            shiftdown(i);
        }

    }
    void heapsort()
    {
        int i;
        int n=xc;
        for(i=1; i<=n; i++)
        {
            deletemax();
        }
        for(i=1; i<=n; i++)
        {
            printf("%d ",x[i]);
        }
        puts("");
    }
};






int main()
{
    heap a;
    printf("1.insert 2.print 3.deletemax 4.heapsort\n");
    int x;
    while(1)
    {
        scanf("%d",&x);
        if(x==1)
        {
            int y;
            scanf("%d",&y);
            a.insert(y);
        }
        else if(x==2)
        {
            a.print();
        }

        else if(x==3)
        {
            a.deletemax();
        }
        else if(x==4)
        {
            a.heapsort();
        }

    }

}
