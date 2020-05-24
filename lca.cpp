#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define LOG 22

int par[mx][LOG];
int depth[mx];
vector<int>g[mx];
int n;

void dfs(int u,int p,int lvl)
{
    par[u][0]=p;
    depth[u]=lvl;

    for(auto v:g[u])
    {
        if(v==p)continue;
        dfs(v,u,lvl+1);
    }
}

void init(int root)
{
    dfs(root,-1,1);

    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
            }
            else par[i][j]=-1;
        }
    }
}

 int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    int log=1;
    while(1)
    {
        int next=log+1;
        if(depth[u]<(1<<next))break;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(depth[u]-(1<<i)>=depth[v])
        {
            u=par[u][i];
        }
    }
    if(u==v)return u;

    for(int i=log;i>=0;i--)
    {
        if(par[u][i]!=-1 && par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[v][0];
}


int dist(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

int kth_parent(int u,int k)
{
    for(int i=LOG-1;i>=0;i--)
    {
        if(k>=(1<<i))
        {
            k-=(1<<i);
            u=par[u][i];
        }
        if(u==-1)return u;
    }
    return u;
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    init(1);
    cout<<dist(6,8)<<endl;
    cout<<kth_parent(8,1)<<endl;

    return 0;
}
