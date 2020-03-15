#include<bits/stdc++.h>
using namespace std;

#define mx 10005

vector<int>g[mx],g_rev[mx],order,component;
vector<bool>visit;
int node,edge;

void dfs1(int u)
{
    visit[u]=true;
    for(auto it:g[u])
    {
        if(visit[it])continue;
        dfs1(it);
    }
    order.push_back(u);
}

void dfs2(int u)
{
    visit[u]=true;
    component.push_back(u);
    for(auto it:g_rev[u])
    {
        if(visit[it])continue;
        dfs2(it);
    }
}

int main()
{
    scanf("%d%d",&node,&edge);
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);///directed graph
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }
    visit.assign(node+1,false);
    for(int i=1;i<=node;i++)
    {
        if(visit[i]==true)continue;
        dfs1(i);
    }
    visit.assign(node+1,false);
    for(int i=1;i<=node;i++)
    {
        int v=order[node-i];
        if(visit[v]==true)continue;
        dfs2(v);
        for(auto it:component)cout<<it<<" ";
        cout<<endl;
        component.clear();
    }

    return 0;
}

