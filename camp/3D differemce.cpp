#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

ll ar[mx][mx][mx],Diff[mx][mx][mx];

int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)scanf("%lld",&ar[i][j][k]);

    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)Diff[i][j][k]=ar[i][j][k]-ar[i][j][k-1]
                        -ar[i][j-1][k]-ar[i-1][j][k]+ar[i-1][j-1][k]
                        +ar[i-1][j][k-1]+ar[i][j-1][k-1]-ar[i-1][j-1][k-1];

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x1,y1,z1,x2,y2,z2,val;
        scanf("%d%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2,&val);
        Diff[x1][y1][z1]+=val;
        Diff[x2+1][y1][z1]-=val;
        Diff[x1][y2+1][z1]-=val;
        Diff[x1][y1][z2+1]-=val;
        Diff[x2+1][y2+1][z1]+=val;
        Diff[x2+1][y1][z2+1]+=val;
        Diff[x1][y2+1][z2+1]+=val;
        Diff[x2+1][y2+1][z2+1]-=val;
    }
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)printf("%lld%c",Diff[i][j],(j==n)?'\n':' ');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)ar[i][j][k]=Diff[i][j][k]+ar[i][j][k-1]
                        +ar[i][j-1][k]+ar[i-1][j][k]-ar[i-1][j-1][k]
                        -ar[i-1][j][k-1]-ar[i][j-1][k-1]+ar[i-1][j-1][k-1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)printf("%lld%c",ar[i][j][k],(k==n)?'\n':' ');


    return 0;
}
