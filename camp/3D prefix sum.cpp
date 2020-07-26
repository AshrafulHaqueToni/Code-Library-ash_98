#include<bits/stdc++.h>
using namespace std;
#define mx 105
#define ll long long
ll ar[mx][mx][mx];
ll prefix[mx][mx][mx];
int n,m,l;

void solve()
{
    scanf("%d%d%d",&n,&m,&l);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            for(int k=1; k<=l; k++)
                scanf("%lld",&ar[i][j][k]);


    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            for(int k=1; k<=l; k++)
                prefix[i][j][k]=prefix[i-1][j][k]+prefix[i][j-1][k]+prefix[i][j][k-1]
                                -prefix[i-1][j-1][k]-prefix[i-1][j][k-1]-prefix[i][j-1][k-1]
                                +prefix[i-1][j-1][k-1]+ar[i][j][k];


    ll ans=-1e18;

    /// (x1,y1,z1) theke (x2,y2,z2) distance

    for(int x1=1; x1<=n; x1++)
    {
        for(int x2=x1; x2<=n; x2++)
        {
            for(int y1=1; y1<=m; y1++)
            {
                for(int y2=y1; y2<=m; y2++)
                {
                    for(int z1=1; z1<=l; z1++)
                    {
                        for(int z2=z1; z2<=l; z2++)
                        {
                            ll re=prefix[x2][y2][z2]-prefix[x1-1][y2][z2]-prefix[x2][y1-1][z2]-prefix[x2][y2][z1-1]
                                  +prefix[x1-1][y1-1][z2]+prefix[x1-1][y2][z1-1]+prefix[x2][y1-1][z1-1]
                                  -prefix[x1-1][y1-1][z1-1];
                            ans=max(re,ans);
                        }
                    }
                }
            }
        }
    }


    printf("%lld\n",ans);
    for(int i=0;i<=n+5;i++)
        for(int j=0;j<=m+5;j++)
            for(int k=0;k<=l+5;k++)prefix[i][j][k]=0;

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
        if(t)printf("\n");
    }
    return 0;
}
