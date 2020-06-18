#include<bits/stdc++.h>
using namespace std;

#define mx 10005

vector<int>g[mx];
int visit[mx];
bool f;

void dfs(int u)
{
    visit[u]=1;
    for(auto it:g[u])
    {
        if(visit[it]==1)
        {
            f=true;
            return;
        }
        if(visit[it]==0)
        {
            dfs(it);
        }
    }
    visit[u]=2;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            dfs(i);
            if(f)break;
        }
    }
    if(f)cout<<"Here is cycle\n";
    else cout<<"It's a DAG\n";
}
