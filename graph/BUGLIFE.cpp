#include<bits/stdc++.h>
using namespace std;

/// odd length er cycle thakley bipartite hobe nah
/// https://www.spoj.com/problems/BUGLIFE/en/
#define mx 2005
#define ll long longz


int n,m,k,ii;
int visit[mx],color[mx];
vector<int>g[mx];
bool f;

void dfs(int u,int col)
{
    visit[u]=1;
    color[u]=col;
    for(auto it:g[u])
    {
        if(visit[it])
        {
            if(color[it]==color[u])
            {
                f=true;
                return;
            }
        }
        else
        {
            dfs(it,col^1);
        }
    }

}
void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++)
   {
       int x,y;
       scanf("%d%d",&x,&y);
       g[x].push_back(y);
       g[y].push_back(x);
   }
   for(int i=1;i<=n;i++)
    if(!visit[i])
     dfs(1,1);
   printf("Scenario #%d:\n",++ii);
   if(f)
   {
       printf("Suspicious bugs found!\n");   ///Not bipartite
   }
   else printf("No suspicious bugs found!\n");  /// bipartite

   for(int i=1;i<=n;i++)
   {
       g[i].clear();
       visit[i]=false;
   }
   f=false;
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
