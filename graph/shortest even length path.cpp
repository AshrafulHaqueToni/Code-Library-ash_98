#include<bits/stdc++.h>
using namespace std;
/// uva-10356 Rough Roads

#define mx 5005
#define ll long long 
#define inf 1e9

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}



vector<pair<int,int>>g[mx];
int dis[mx][2];
int m,n,k,ii,re;



void solve()
{
   for(int i=1;i<=m;i++)
   {
       int x,y,z;
       scanf("%d%d%d",&x,&y,&z);
       x++,y++;
       g[x].push_back({y,z});
       g[y].push_back({x,z});
   }
   for(int i=1;i<=n;i++)dis[i][0]=dis[i][1]=inf;
   priority_queue<pair<int,pair<int,bool>>>q;
   q.push({0,{1,false}});
   dis[1][0]=0;
   while(!q.empty())
   {
      int u=q.top().second.first;
      int val=q.top().first;
      val*=-1;
      bool f=q.top().second.second;
      q.pop();
      if(dis[u][f]<val)continue;
      for(auto it:g[u])
      {
          int v=it.first;
          int val1=val+it.second;
         // cout<<u<<" "<<v<<" "<<val1<<endl;
          if(dis[v][f^1]>val1)
          {
            dis[v][f^1]=val1;
            q.push({-val1,{v,f^1}});
          }
      }
   }
  // for(int i=1;i<=n;i++)printf("%d %d\n",dis[i][0],dis[i][1] );
   printf("Set #%d\n",++ii);
   if(dis[n][0]==inf)printf("?\n");
   else printf("%d\n",dis[n][0] );
 
   for(int i=1;i<=n;i++)g[i].clear();

}

int main()
{
  IO();
  int t=1;
 // scanf("%d",&t);
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    solve();
  }
  return 0;
}
