#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long

ll ar[mx][mx],Diff[mx][mx];

int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)scanf("%lld",&ar[i][j]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)Diff[i][j]=ar[i][j]+ar[i-1][j-1]-ar[i-1][j]-ar[j][j-1];

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x1,y1,x2,y2,val;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
        Diff[x1][y1]+=val;
        Diff[x2+1][y2+1]+=val;
        Diff[x1][y2+1]-=val;
        Diff[x2+1][y1]-=val;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)printf("%lld%c",Diff[i][j],(j==n)?'\n':' ');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)ar[i][j]=Diff[i][j]+ar[i-1][j]+ar[i][j-1]-ar[i-1][j-1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)printf("%lld%c",ar[i][j],(j==n)?'\n':' ');


    return 0;
}
