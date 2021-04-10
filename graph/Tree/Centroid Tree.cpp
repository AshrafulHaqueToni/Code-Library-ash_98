// Tested by CF 766E (https://codeforces.com/contest/766/problem/E)
#define mx 200005
int dis[18][mx],re[mx],vis[mx];
int p[mx],sub[mx],lvl[mx];
vector<int>g[mx],ng[mx];
/* p[u] = parent of u in centroid tree
dis[x][u] = distance from u to a parent of u at level x of centroid tree
if u is in subtree of centroid c, then dis[lvl[c]][u] = dist(c, l)
If (x, y) edge exist, then x must be in g[y] and y must be in g[x]*/
/* we can do more pre work in dfs function*/
void dfs(int l,int u,int par)
{
	if(par!=-1)dis[l][u]=dis[l][par]+1;
	for(int v:g[u])
		if(v!=par && !vis[v])dfs(l,v,u);
}
int centroid(int u,int par,int r)
{
	for(int v:g[u])
		if(v!=par && !vis[v] && sub[v]>r)return centroid(v,u,r);
	return u;
}
void pre_cal(int u,int par)
{
	sub[u]=1;
	for(int v:g[u])
		if(v!=par && !vis[v])pre_cal(v,u),sub[u]+=sub[v];
}
void decompose(int u,int par)
{
	pre_cal(u,-1);
	int tem=centroid(u,-1,sub[u]>>1);
	vis[tem]=1,p[tem]=par,lvl[tem]=0;
	if(par!=-1)lvl[tem]=lvl[par]+1,ng[par].push_back(tem);
	dfs(lvl[tem],tem,-1);
	for(int v:g[tem])
		if(v!=par && !vis[v])decompose(v,tem);
}
void update(int u)
{
	for(int v=u;v!=-1;v=p[v])
		re[v]=min(re[v],dis[lvl[v]][u]);
}
int query(int u)
{
	int ans=1e9;
	for(int v=u;v!=-1;v=p[v])
		ans=min(ans,re[v]+dis[lvl[v]][u]);
	return ans;
}
int lca(int u,int v)
{
	if(lvl[u]<lvl[v])swap(u,v);
	while(lvl[u]>lvl[u])u=p[u];
	while(u!=v)u=[u],v=p[v];
	return u;
}
int dist(int u,int v)
{
	int lc=lca(u,v);
	return dis[lvl[lc]][u]+dis[lvl[lc]][v];
}
int GetRoot(int u)
{
	while(p[u]!=-1)u=p[u];
	return u;
}
// at first call decompose(1,-1)
