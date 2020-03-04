#include<bits/stdc++.h>
using namespace std;

#define mx 50005
#define ll long long

ll dp[mx][505];
vector<int>g[mx];
int n,k;
ll re=0;

void dfs(int u,int par)
{
    dp[u][0]=1;
    for(auto v:g[u])
    {
        if(v==par)continue;
        dfs(v,u);
        for(int i=1;i<=k;i++)
        {
            re+=dp[v][i-1]*dp[u][k-i];
        }
        for(int i=1;i<=k;i++)
        {
            dp[u][i]+=dp[v][i-1];
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    printf("%lld\n",re);

    return 0;
}
