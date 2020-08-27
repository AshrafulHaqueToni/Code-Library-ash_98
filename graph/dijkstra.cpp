#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 
#define inf 1e18

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}


int par[mx];
vector<pair<int,int>>g[mx];
ll dis[mx];
int m,n,k,ii;


void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++)
   {
      int x,y,w;
      scanf("%d%d%d",&x,&y,&w);
      g[x].push_back({y,w});
      g[y].push_back({x,w});
   }
   for(int i=1;i<=n;i++)dis[i]=inf;
   priority_queue<pair<ll,int>>q;   /// graph dense hole set use korbo
   dis[1]=0;
   par[1]=-1;
   q.push({0,1});
   while(!q.empty())
   {
       int u=q.top().second;
       ll val=q.top().first;
       val*=-1;
       q.pop();
       if(dis[u]<val)continue;
       for(auto it:g[u])
       {
          ll val1=val+it.second;
          int v=it.first;
          if(val1<dis[v])
          {
            dis[v]=val1;
            q.push({-val1,v});
            par[v]=u;
          }
       }
   }
   if(dis[n]==inf)printf("-1\n");
   else 
    {
      //printf("%lld\n",dis[n] );  shortest distance
      vector<int>path;
      while(n!=-1)
      {
        path.push_back(n);
        n=par[n];
      }
      reverse(path.begin(),path.end());
      for(int it:path)printf("%d ",it );
    }

}

int main()
{
  IO();
  int t=1;
  
  while(t--)
  {
    solve();
  }
  return 0;
}
