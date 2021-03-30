int par[mx][20];
ll ans[mx][20];
int depth[mx],LOG;
vector<pair<int,ll>>g[mx];
void dfs(int u,int p,int lvl)
{
    par[u][0]=p;
    depth[u]=lvl;
    for(auto it:g[u])
    {
        int v=it.first;
        ll w=it.second;
        if(v==p)continue;
        ans[v][0]=w;
        dfs(v,u,lvl+1);
    }
}

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
                ans[i][j]=max(ans[i][j-1],ans[par[i][j-1]][j-1]);
            }
            else par[i][j]=-1;

        }
    }
}

ll query(int u,int v)
{
	if(u==v)return 0;
    if(depth[u]<depth[v])swap(u,v);
    int diff=depth[u]-depth[v];
    ll re=0;
    for(int i=LOG-1;i>=0;i--)
    {
        if(diff>=(1<<i))
        {
            diff-=(1<<i);
            re=max(re,ans[u][i]);
            u=par[u][i];
        }
    }
    if(u==v)return re;

    for(int i=LOG-1;i>=0;i--)
    {
        if( par[u][i]!=par[v][i])
        {
            re=max({re,ans[u][i],ans[v][i]});
            u=par[u][i];
            v=par[v][i];
        }
    }
    re=max({re,ans[u][0],ans[v][0]});
    return re;
}
solve()
{
  scanf("%d%d",&n,&m); 
  for(int i=1;i<=n;i++)
	{
		g[i].clear();
		for(int j=0;j<LOG;j++)ans[i][j]=0,par[i][j]=-1;
	}
  LOG=log2(n)+1;
}
