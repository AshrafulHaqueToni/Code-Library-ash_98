int n,m,ii,k;
vector<int>g[mx];
int par[mx],sub_sz[mx];
int Head[mx],st[mx],sesh[mx];
int Rin[mx];  /// Segment Tree er init ye Tree[bode]=ar[Rin[be]] likte hobe
int T;

using namespace Segment_Tree;

void sz_dfs(int u,int p)
{
	sub_sz[u]=1;
	par[u]=p;
	for(int &v: g[u])
	{
		if(v==p)continue;
		sz_dfs(v,u);
		sub_sz[u]+=sub_sz[v];
		if(sub_sz[v]>sub_sz[g[u][0]])swap(v,g[u][0]);
	}
}
void hld_dfs(int u,int p)
{
     st[u]=++T;
     Rin[st[u]]=u;
     for(int v:g[u])
     {
     	if(v==p)continue;
     	Head[v]= (v==g[u][0] ? Head[u]:v);
     	hld_dfs(v,u); 
     }
     sesh[u]=T;
}

void hld_build(int root)
{
	T=0;
	Head[root]=root;
	sz_dfs(root,root);
	hld_dfs(root,root);
}

bool Is_it_parent(int p,int u)
{
	return st[p]<=st[u] && sesh[u]<=sesh[p];
}

int path_query(int u,int v)
{
	int re=-inf;
	while(1)
	{
		if(Is_it_parent(Head[u],v))break;
		re=max(re,query(1,1,n,st[Head[u]],st[u]));  /// for sum we  will do just add all query sum
		u=par[Head[u]]; 
	}
	swap(u,v);
	while(1)
	{
		if(Is_it_parent(Head[u],v))break;
		re=max(re,query(1,1,n,st[Head[u]],st[u]));  /// for sum we  will do just add all query sum
		u=par[Head[u]]; 
	}
	if(st[u]>st[v])swap(u,v);
	re=max(re,query(1,1,n,st[u],st[v]));

	return re;
}

void path_update(int u,int v,int val)
{
	while(1)
	{
		if(Is_it_parent(Head[u],v))break;
		Rupdate(1,1,n,st[Head[u]],st[u],val);  
		u=par[Head[u]]; 
	}
	swap(u,v);
	while(1)
	{
		if(Is_it_parent(Head[u],v))break;
		Rupdate(1,1,n,st[Head[u]],st[u],val);  
		u=par[Head[u]];
	}
	if(st[u]>st[v])swap(u,v);
	Rupdate(1,1,n,st[u],st[v],val);
}

void update_subtree(int u,int val)
{
	Rupdate(1,1,n,st[u],sesh[u],val);
}
