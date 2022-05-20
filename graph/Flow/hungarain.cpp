
#define INF 1e18
pair<ll,vector<int>> hungarain(vector<vector<ll>>mat,int f,int sz)
{
    vector<int>par(sz+1,0),way(sz+1,0),match(sz+1,0);
    vector<bool>vis(sz+1,0);
    vector<ll>U(sz+1,0),V(sz+1,0),MinV(sz+1,0);
    for(int i=1;i<=sz;i++)
    {
        for(int j=1;j<=sz;j++)
        {
            mat[i][j]*=f;
        }
    }
    int a,b,d;
    ll r,w;
    for(int i=1;i<=sz;i++)
    {
        par[0]=i;
        b=0;
        for(int j=1;j<=sz;j++)MinV[j]=INF,vis[j]=0;
        do{
            vis[b]=1;
            a=par[b],d=0,w=INF;
            for(int j=1;j<=sz;j++)
            {
                if(!vis[j])
                {
                    r=mat[a][j]-U[a]-V[j];
                    if(r<MinV[j])MinV[j]=r,way[j]=b;
                    if(MinV[j]<w)w=MinV[j],d=j;
                }
            }
            for(int j=0;j<=sz;j++)
            {
                if(vis[j])U[par[j]]+=w,V[j]-=w;
                else MinV[j]-=w;
            }
            b=d;
        }
        while(par[b]!=0);
        do{
            d=way[b];
            par[b]=par[d],b=d;
        }
        while(b!=0);
    }
    for(int j=1;j<=sz;j++)match[par[j]]=j;
    return {-f*V[0],match};
}
// called hungarain(mat,1,n)
