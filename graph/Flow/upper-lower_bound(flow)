// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 515
#define ll long long
#define INF 1e12
int n,m,ii,k;

const ll eps = 0;

struct edge {
    int a, b;
    ll cap,flow;
    int yo, x, y;
};

struct Dinic {
    int s,t,d[mx], ptr[mx] ;
    //int Id[mx][mx];
    vector<edge>e;
    vector<int>g[mx];
    void init() {
        e.clear();
        memset(d,0,sizeof(d));
        for(int i = 0; i < mx ; i++)g[i].clear();
        // for(int i=0;i<mx;i++)
        // {
        //  for(int j=0;j<mx;j++)
        //  {
        //      Id[i][j]=0;
        //  }
        // }
    }
    void addEdge(int a,int b,ll cap, int x = -1, int y= -1) {
        edge e1 = { a, b, cap, 0, 1, x, y } ;
        edge e2 = { b, a, 0, 0, 0, x, y } ;
      //  Id[a][b]=e.size();
        g[a].push_back((int)e.size());
        e.push_back(e1);
      //  Id[b][a]=e.size();
        g[b].push_back((int)e.size());
        e.push_back(e2);
    }
    bool bfs() {
        queue < int > Q ;
        Q.push(s);
        memset(d,-1,sizeof(d));
        d[s]=0 ;
        while (!Q.empty()) {
            int u=Q.front() ;
            Q.pop() ;
            for(int i=0; i<g[u].size(); i++) {
                int id=g[u][i];
                int v=e[id].b;
              //  printf("%d %d %0.3lf %0.3lf\n",u,v,e[id].cap,e[id].flow);
                if(d[v]==-1&&e[id].flow<e[id].cap) {
                    Q.push(v) ;
                    d[v]=d[u]+1 ;
                }
            }
        }
        return d[t]!=-1 ;
    }
    ll dfs(int u,ll flow) {
        if (flow<=eps)  return 0 ;
        if ( u==t )  return flow ;
        for(int& i = ptr[u] ; i<g[u].size(); i++) {
            int id = g[u][i];
            int v =  e[id].b ;
            if ( d[v] != d[u]+1 )  continue ;
            ll pushed = dfs (v,min (flow,e[id].cap-e[id].flow)) ;
            //cout << "pushed " << pushed << endl;
            if (pushed>eps) {
                e [id].flow+=pushed ;
                e [id^1].flow-=pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }
    ll dinic() {
        ll flow = 0 ;
        while(true) {
            if(!bfs())  break ;
            memset(ptr, 0, sizeof(ptr)) ;
            while (true){
                ll pushed = dfs(s,INF );
                if(pushed<=eps)break;
                flow += pushed ;
            }
        }
        return flow ;
    }
};

Dinic dc;
int x,y;

struct tem
{
    int u,v,a,b;
};

vector<tem>ed;

ll func(ll val)
{
    dc.init();
    dc.s=n+1;
    dc.t=n+2;
    
    /// for upperbound(0,val)
    // dc.addEdge(y,n+3,val); /// sink to super super source
    // dc.addEdge(n+1,x,0); /// sink to source
    // dc.addEdge(n+3,n+2,0); /// super super source to super sink
    // dc.addEdge(n+3,x,val);  /// super super source to source 

    /// for lowerbound(val,inf)
    dc.addEdge(y,n+3,INF); /// sink to super super source
    dc.addEdge(n+1,x,val); /// sink to source
    dc.addEdge(n+3,n+2,val); /// super super source to super sink
    dc.addEdge(n+3,x,INF);  /// super super source to source 
    
    for(auto it:ed)
    {
        dc.addEdge(n+1,it.v,it.a);
        dc.addEdge(it.u,n+2,it.a);
        dc.addEdge(it.u,it.v,it.b-it.a);
    }
    return dc.dinic();
}

void solve()
{
    scanf("%d%d",&n,&m);
    
    scanf("%d%d",&x,&y);
    dc.addEdge(y,x,INF);
    dc.s=n+1;
    dc.t=n+2;
    ll val=0;
    ll en=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,a,b;
        scanf("%d%d%d%d",&u,&v,&a,&b);
        ed.push_back({u,v,a,b});
        val+=a;
        en+=b;
        dc.addEdge(n+1,v,a);
        dc.addEdge(u,n+2,a);
        dc.addEdge(u,v,b-a);
    }
    if(dc.dinic()<val)
    {
        printf("0\n");
        return;
    }
    ll be=val;
    ll re=be;
    while(be<=en)
    {
        ll mid=(be+en)/2;
        ll have=func(mid);
       // cout<<have<<" "<<mid<<endl;
        if(have>=mid+val)
        {
            re=mid;
            be=mid+1;
        }
        else en=mid-1;
    }
    printf("%lld\n",re);
}
 
int main()
{
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
    return 0;
}
