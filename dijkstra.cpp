#include<bits/stdc++.h>
using namespace std;

struct Node   /// dijkstra O(mlogn)
{
    int now,cost;
    Node(){};
    Node(int now,int cost)
    {
        this->now=now;
        this->cost=cost;
    }
};
bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}
struct Edge{
  int v,w;
  Edge(){};
  Edge(int v,int w){this->v=v,this->w=w;}
};

vector<Edge>adj[100];
priority_queue<Node>PQ;
int dist[100];
int n,m;

void dijkstra(int src)
{
    for(int i=1;i<=n;i++)dist[i]=1000000000;

    dist[src]=0;
    PQ.push(Node(src,0));

    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();
        if(u.cost!=dist[u.now])
        {
            continue;
        }

        for(Edge it: adj[u.now])
        {
            if(dist[it.v]>u.cost+it.w)
            {
                dist[it.v]=u.cost+it.w;
                PQ.push(Node(it.v,dist[it.v]));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        adj[x].push_back(Edge(y,w));
        adj[y].push_back(Edge(x,w));
    }

    int start;
    scanf("%d",&start);

    dijkstra(start);

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }

    return 0;
}
