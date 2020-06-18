#include<bits/stdc++.h>
using namespace std;
#define mx 505
vector<int>g[mx],visit(mx,0);

int n,edge;

bool dfs(int u,int p)
{
    if(visit[u])return true;
    visit[u]=true;
    //cout<<u<<" "<<p<<endl;
    bool f=false;
    for(auto it:g[u])
    {
        if(it==p)continue;
        cout<<it<<endl;
        f|=dfs(it,u);
    }
    //cout<<u<<" "<<p<<endl;
   return f;
}

int main()
{
    scanf("%d%d",&n,&edge);
    for(int i=1;i<=edge;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);

    }
    bool f=false;

    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            f|=dfs(i,-1);
        }
    }
    cout<<f<<endl;
}
