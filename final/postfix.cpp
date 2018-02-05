#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct stk
{
    int tp=-1;
    int a[100];
    int emp()
    {
        if(tp==-1)
            return 1;
        return 0;
    }
    int top()
    {
        if(emp())
            return -1;
        else
            return a[tp];
    }
    void push(int v)
    {
        if(tp==99)
            printf("FULL\n");
        else
        {
            tp++;
            a[tp]=v;
        }
    }
    int pop()
    {
        if(tp==-1)
            return -1;
        else
        {
            int x=a[tp];
            tp--;
            return x;
        }
    }
    void pr()
    {
        int i;
        for(i=0; i<=tp; i++)
            printf("%d ",a[i]);
    }

};

main()
{
    char q[1000],an[200];
    scanf("%s",&q);
    int i,f=0;
    stk a;
    for(i=0; i<strlen(q); i++)
    {
        if(q[i]!='+'&&q[i]!='-'&&q[i]!='/'&&q[i]!='*'&&q[i]!='('&&q[i]!=')')
        {
            an[f]=q[i];
            f++;
        }
        else if(q[i]=='(')
                    a.push(q[i]);
        else if(q[i]==')')
        {
            while(a.top()!='(')
            {
                an[f]=a.top();
                f++;
                a.pop();
            }
            a.pop();
        }
        else if(q[i]=='+'||q[i]=='-')
        {
            while(!a.emp()&&a.top()!='(')
            {
                an[f]=a.top();
                f++;
                a.pop();
            }
            a.push(q[i]);
        }
        else if(q[i]=='*'||q[i]=='/')
        {
            while(!a.emp()&&a.top()!='('&&a.top()!='-'&&a.top()!='+')
            {
                an[f]=a.top();
                f++;
                a.pop();
            }
            a.push(q[i]);
        }


    }
    while(!a.emp())
    {
        an[f]=a.top();
        f++;
        a.pop();
    }
    an[f]=0;
    puts(an);





}




