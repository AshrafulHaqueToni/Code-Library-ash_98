// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int n,m,ii,k,LOG;
int depth[mx];
int par[mx][25];

namespace MO
{
    const int N=100005;
    const int Q=100005;

    int ar[N],br[N],BlockId[N],ans[Q];
    bool vis[N];

    struct node
    {
    	int l,r,id,lca;
    	node(){}
    	node(int l,int r,int lca,int id)
    	{
    		this->l=l;
    		this->r=r;
    		this->lca=lca;
    		this->id=id;
    	}
        bool operator < (const node& u)
        {
        	int a=BlockId[l],b=BlockId[u.l];
        	return (a==b)?(r<u.r):a<b;
        }
    }query[Q];

    int re=0,sz;
    int cnt[100005];  


    void check(int pos)
    {
    	if(vis[pos])
    	{
    		if(cnt[ar[pos]]==1)re--;
    		cnt[ar[pos]]--;
    	}
    	else
    	{
    		if(cnt[ar[pos]]==0)re++;
    		cnt[ar[pos]]++;

    	}
    	vis[pos]^=1;
    }
	
	
    vector<int> g[N];
    int Euler[2*N],st[N],en[N],Time;

    void dfs(int u,int p,int lvl)
    {
       st[u]=++Time;
       Euler[Time]=u;
       par[u][0]=p;
       depth[u]=lvl;
       for(int v:g[u])
       {
       	 if(v==p)continue;
       	 dfs(v,u,lvl+1);
       }
       en[u]=++Time;
       Euler[Time]=u;
    }

}

using namespace MO;

void init(int root)
{
    dfs(root,-1,1);

    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
            }
            else par[i][j]=-1;
        }
    }
}

 int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    int log=1;
    while(1)
    {
        int next=log+1;
        if(depth[u]<(1<<next))break;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(depth[u]-(1<<i)>=depth[v])
        {
            u=par[u][i];
        }
    }
    if(u==v)return u;

    for(int i=log;i>=0;i--)
    {
        if(par[u][i]!=-1 && par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[v][0];
}

void solve()
{
	int q;
	scanf("%d%d",&n,&q);
	LOG=log2(n)+1;
	Time=0;
	re=0;
	sz=sqrt(n);

	for(int i=1;i<=n;i++)
		scanf("%d",&ar[i]),br[i]=ar[i],BlockId[i]=i/sz,vis[i]=false,cnt[i]=0;

	// Compressing Coordinates . its a alternative of map
	sort(br+1,br+n+1);
	k = unique(br+1,br+n+1)-br-1;
	for(int i=1;i<=n;i++) ar[i]=lower_bound(br+1,br+k+1,ar[i])-br;

	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	init(1);

	for(int i=1;i<=q;i++)
	{
       int x,y;
       scanf("%d%d",&x,&y);
       if(st[x]>st[y])swap(x,y);
       int p=lca(x,y);
       if(x==p)query[i]=node(st[x],st[y],-1,i);
       else query[i]=node(en[x],st[y],p,i);
	}

	sort(query+1,query+1+q);
    
    int left=query[1].l;
	int right=left-1;

	for(int i=1;i<=q;i++)
	{
		node Now=query[i];
		while(left<Now.l)check(Euler[left++]);
		while(left>Now.l)check(Euler[--left]);
		while(right<Now.r)check(Euler[++right]);
		while(right>Now.r)check(Euler[right--]);
        if(Now.lca!=-1)check(Now.lca); 
        ans[Now.id]=re;
        if(Now.lca!=-1)check(Now.lca);
	}

	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    for(int i=1;i<=n;i++)g[i].clear();

}

int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}
