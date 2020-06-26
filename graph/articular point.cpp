#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];
vector<int>g[mx];
int articular_point[mx];
int n,m,k,ii;
int st[mx],low[mx];
int Time=1;

int dfs(int u,int p)
{
    st[u]=low[u]=Time++;
    int child=0;
    for(auto it:g[u])
    {
        if(it==p)continue;
        if(st[it]==0)
        {
            child++;
            dfs(it,u);
            if(st[u]<=low[it])articular_point[u]=1;
            low[u]=min(low[u],low[it]);
        }
        else low[u]=min(low[u],st[it]);

    }
    return child;
}

void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
   {
       int x,y;
       scanf("%d%d",&x,&y);
       g[x].push_back(y);
       g[y].push_back(x);
   }
   for(int i=1;i<=n;i++)
   {
       if(st[i])continue;
       articular_point[i]=(dfs(i,-1)>1);
   }
   cout<<"articular points are: \n";
   for(int i=1;i<=n;i++)
   {
       if(articular_point[i])cout<<i<<endl;
   }
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
  // scanf("%d",&t);
   while(t--)solve();
   return 0;
}
