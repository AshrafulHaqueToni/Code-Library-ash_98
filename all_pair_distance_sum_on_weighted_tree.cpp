#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 10005

struct me
{
    int v;
    int w;
    me() {}
    me(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};
vector<me>g[mx];

ll subsize[mx];
int n;
ll re;

void dfs(int u,int cost,int parent)
{
    subsize[u]=1;
    for(auto it:g[u])
    {
        int next=it.v;
        int c=it.w;
        if(next!=parent)
        {
            dfs(next,c,u);
            subsize[u]+=subsize[next];
        }
    }
    re+=(n-subsize[u])*subsize[u]*cost;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(me(v,w));
        g[v].push_back(me(u,w));
    }
    dfs(1,0,-1);

    printf("%lld\n",re);
    return 0;
}

