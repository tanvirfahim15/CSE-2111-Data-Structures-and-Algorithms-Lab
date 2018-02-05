#include <bits/stdc++.h>
using namespace std;
struct vertex
{
    int c=0;
    int d=-1;
    int p=-1;
    int dc=0;
    int dp=-1;
    int start=-1;
    int stop=-1;
    vector<int> adjacent;
};

struct graph
{
    vertex v[100];
    vector<int> vset;
    stack<int> topsort;
    int adj[100][100];
    int tadj[100][100];
    int t2adj[100][100];
    int time=0;
    int hascycle=0;
    int compdir=0;
    int edgecnt=0;
    int vcnt=0;
    matrixmult()
    {
        int i,j,k;
        for(i=0; i<100; i++)
        {
            for(j=0; j<100; j++)
            {
                int sum=0;
                for(k=0; k<100; k++)
                {
                    int x=adj[i][k]*tadj[k][j];
                    sum+=x;
                }
                t2adj[i][j]=sum;
            }
        }
        for(i=0; i<100; i++)
        {
            for(j=0; j<100; j++)
            {
                tadj[i][j]=t2adj[i][j];
            }

        }
    }
    void matcopy()
    {
        int i,j;
        for(i=0; i<100; i++)
        {
            for(j=0; j<100; j++)
            {
                tadj[i][j]=adj[i][j];
            }

        }
    }
    int cntpath(int x,int y,int k)
    {
        matcopy();
        int i;
        for(i=0; i<k; i++)
        {
            matrixmult();
        }
        return tadj[x][y];
    }
    int totpath(int x,int y)
    {
        int i,ans=0;
        matcopy();
        for(i=1; i<100; i++)
        {
            matrixmult();
            ans+=tadj[x][y];
        }

        return ans;

    }
    graph()
    {
        int i,j;
        for(i=0; i<100; i++)
            for(j=0; j<100; j++)
                adj[i][j]=0;
    }
    compdfs()
    {
        compdir=0;
        time=0;
        hascycle=0;
        int i;
        for(i=0; i<100; i++)
        {
            v[i].dc=0;
            v[i].start=-1;
            v[i].stop=-1;
        }
        while(!topsort.empty())
        {
            int x=topsort.top();
            topsort.pop();
            if(v[x].dc==0)
            {
                dfsvisit(x);
                compdir++;
            }
        }
    }
    int getcompdir()
    {
        dfs();
        compdfs();
        return compdir;
    }
    int istree()
    {
        int x=vcnt-1;
        if(edgecnt==x)
        {
            if(getcompdir()==1&&hascycle==0);
            return 1;
        }
        return 0;
    }
    dfs()
    {
        time=0;
        hascycle=0;
        int i;
        for(i=0; i<100; i++)
        {
            v[i].dc=0;
            v[i].dp=-1;
            v[i].start=-1;
            v[i].stop=-1;
        }
        while(!topsort.empty())
            topsort.pop();
        for(vector<int>::iterator it=vset.begin(); it!=vset.end(); ++it)
            if(v[*it].dc==0)
                dfsvisit(*it);
    }
    cycledfs()
    {
        time=0;
        hascycle=0;
        int i;
        for(i=0; i<100; i++)
        {
            v[i].dc=0;
            v[i].start=-1;
            v[i].stop=-1;
        }
        while(!topsort.empty())
            topsort.pop();
        for(vector<int>::iterator it=vset.begin(); it!=vset.end(); ++it)
            if(v[*it].dc==0)
                cycledfsvisit(*it);

    }
    printtopsort()
    {
        dfs();
        if(!hascycle)
            while(!topsort.empty())
            {
                printf("%d ",topsort.top());
                topsort.pop();
            }
    }
    cycledfsvisit(int x)
    {
        time++;
        v[x].start=time;
        v[x].dc=1;
        for(vector<int>::iterator it=v[x].adjacent.begin(); it!=v[x].adjacent.end(); ++it)
        {
            if(v[*it].dc==0)
                cycledfsvisit(*it);
            else if(v[*it].dc==1)
            {
                hascycle=1;
                dobfs(*it);
                printpath(*it,x);
                puts("");
            }
        }
        time++;
        v[x].stop=time;
        v[x].dc=2;
        topsort.push(x);
    }
    dfsvisit(int x)
    {
        time++;
        v[x].start=time;
        v[x].dc=1;
        for(vector<int>::iterator it=v[x].adjacent.begin(); it!=v[x].adjacent.end(); ++it)
        {
            if(v[*it].dc==0)
            {
                dfsvisit(*it);
                v[*it].dp=x;
            }
            else if(v[*it].dc==1)
                hascycle=1;
        }
        time++;
        v[x].stop=time;
        v[x].dc=2;
        topsort.push(x);
    }
    int isbipartite()
    {
        int i;
        for(i=0; i<100; i++)
        {
            v[i].c=0;
            v[i].p=-1;
            v[i].d=-1;
        }
        int x=1;
        for(i=0; i<100; i++)
        {

            if(v[i].c==0)
                x*=checkbipartite(i);
        }
        return x;
    }
    int checkbipartite(int source)
    {
        v[source].c=1;
        queue<int> bfs;
        bfs.push(source);
        while(!bfs.empty())
        {
            int cur=bfs.front();
            bfs.pop();
            for(vector<int>::iterator it=v[cur].adjacent.begin(); it!=v[cur].adjacent.end(); ++it)
            {
                if(v[*it].c==0)
                {
                    v[*it].c=3-v[cur].c;
                    bfs.push(*it);
                }
                else if(v[*it].c==v[cur].c)
                    return 0;
            }
        }
        return 1;
    }
    void dobfs(int source)
    {
        int i;
        for(i=0; i<100; i++)
        {
            v[i].c=0;
            v[i].p=-1;
            v[i].d=-1;
        }
        v[source].c=1;
        v[source].d=0;
        queue<int> bfs;
        bfs.push(source);
        while(!bfs.empty())
        {
            int cur=bfs.front();
            bfs.pop();
            for(vector<int>::iterator it=v[cur].adjacent.begin(); it!=v[cur].adjacent.end(); ++it)
            {
                if(v[*it].c==0)
                {
                    v[*it].c=1;
                    v[*it].d=v[cur].d+1;
                    v[*it].p=cur;
                    bfs.push(*it);
                }
            }
            v[cur].c=2;
        }
    }
    void printpath(int x,int y)
    {
        if(x==y)
            printf("%d ",x);
        else
        {
            printpath(x,v[y].p);
            printf("%d ",y);
        }
    }
    addedge(int x,int y)
    {
        v[x].adjacent.push_back(y);
        adj[x][y]=1;
        edgecnt++;
        addtovset(x);
        addtovset(y);
    }
    int findinvset(int x)
    {

        for(vector<int>::iterator it=vset.begin(); it!=vset.end(); ++it)
            if(*it==x)
                return 1;
        return 0;
    }
    addtovset(int x)
    {
        if(!findinvset(x))
        {

            vset.push_back(x);
            vcnt++;
        }
    }
    addbiedge(int x,int y)
    {
        v[x].adjacent.push_back(y);
        adj[x][y]=1;
        v[y].adjacent.push_back(x);
        adj[y][x]=1;
        addtovset(x);
        addtovset(y);
        edgecnt+=2;
    }

};
main()
{
    freopen("input.txt","r",stdin);
    graph g;
    int cmd;
    printf("1.insert edge(x->y)\n");
    printf("2.insert edge(x<->y)\n");
    printf("3.Has edge?(x->y)\n");
    printf("4.Has path form x to y?\n");
    printf("5.shortest distance form x to y\n");
    printf("6.Print shortest path form x to y?\n");
    printf("7.is Bipartite?\n");
    printf("8.print topsort\n");
    printf("9.hascycle?\n");
    printf("10.print cycles\n");
    printf("11. get components\n");
    printf("12. is tree?\n");
    printf("13.Number of path of length k from x to y(x,y,k)\n");
    printf("14.Number of path of  any length from x to y(x,y) \n");

    printf("\n\n");
    while(true)
    {
        scanf("%d",&cmd);
        if(cmd==1)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            g.addedge(x,y);
        }
        else if(cmd==2)
        {

            int x,y;
            scanf("%d %d",&x,&y);
            g.addbiedge(x,y);
        }
        else if(cmd==3)
        {

            int x,y;
            scanf("%d %d",&x,&y);
            if(g.adj[x][y])
                printf("edge from %d to %d\n",x,y);
            else
                printf("No edge from %d to %d\n",x,y);
        }
        else if(cmd==4)
        {

            int x,y;
            scanf("%d %d",&x,&y);
            g.dobfs(x);
            if(g.v[y].d!=-1)
                printf("path exists from %d to %d\n",x,y);
            else
                printf("No path from %d to %d\n",x,y);
        }
        else if(cmd==5)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            g.dobfs(x);
            printf("%d\n",g.v[y].d);
        }
        else if(cmd==6)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            g.dobfs(x);
            if(g.v[y].d!=-1)
            {

                g.printpath(x,y);
                puts("");
            }
            else
                printf("No path from %d to %d\n",x,y);
        }
        else if(cmd==7)
        {
            if(g.isbipartite())
                printf("bipartite\n");
            else
                printf("Not bipartite\n");

        }
        else if(cmd==8)
        {
            g.printtopsort();
            printf("\n");
        }
        else if(cmd==9)
        {
            g.dfs();
            if(g.hascycle)
            {
                printf("cycle exists\n");
            }
            else
                printf("No cycles\n");
        }
        else if(cmd==10)
        {
            printf("cycles:\n");
            g.cycledfs();
        }
        else if(cmd==11)
        {
            printf("%d\n",g.getcompdir());
        }
        else if(cmd==12)
        {
            if(g.istree())
                printf("Tree\n");
            else
                printf("Not tree\n");
        }
        else if(cmd==13)
        {

            int x,y,k;
            scanf("%d %d %d",&x,&y,&k);
            printf("%d\n",g.cntpath(x,y,k-1));
        }
        else if(cmd==14)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",g.totpath(x,y));
        }
        else
            break;
    }
}
