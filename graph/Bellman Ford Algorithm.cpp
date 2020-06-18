#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Edge
{
    int u,v,w;
    Edge(){};
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

vector<Edge>E;
ll dist[100];
int n,m;

bool bellman_ford()
{
    /// here i can start from 1 .if given that stating node i can set dist[src]=0

    for(int i=1;i<=n;i++)dist[i]=10000000;

    dist[1]=0;

    for(int i=1;i<n;i++)
        for(Edge it: E)
            if(dist[it.v]>dist[it.u]+it.w)
                dist[it.v]=dist[it.u]+it.w;


    for(Edge it:E)
        if(dist[it.v]>dist[it.u]+it.w)return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        E.push_back(Edge(x,y,z));
    }

    bool f=bellman_ford();///negative_cycle_check;

    if(f)
    {
        cout<<"Negative cycle\n";
    }
    else
    {
        int sum=0;
        for(int i=1;i<=n;i++)sum+=dist[i],cout<<i<<" "<<dist[i]<<endl;///distance from 1 node;
        cout<<"total cost "<<sum<<endl;
    }
    return 0;
}
