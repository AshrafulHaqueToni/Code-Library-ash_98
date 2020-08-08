#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long 

int ar[mx];
vector<int>g[mx];
int Diff[mx];
int par[mx];
int m,n,k,ii,dek;

void get_dif(int u,int p)
{
	par[u]=p;
	int sum=0;
	for(int v:g[u])
	{
		if(v==p)continue;
		get_dif(v,u);
		sum+=ar[v];
	}
	Diff[u]=ar[u]-sum;
}

void get_array(int u,int p)
{
	int sum=0;
	for(int v:g[u])
	{
		if(v==p)continue;
		get_array(v,u);
        sum+=ar[v];
	}
	ar[u]=Diff[u]+sum;
	
}

void solve()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);

	}
	for(int i=1;i<=n;i++)scanf("%d",&ar[i]);

	get_dif(1,0);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int u,v,val;
		scanf("%d%d%d",&u,&v,&val); /// Here u is parent and v is ancestor
		Diff[v]+=val;
		Diff[par[u]]-=val;
	}
	get_array(1,0);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ar[i] );
	}
	printf("\n");
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=1;
	//scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}