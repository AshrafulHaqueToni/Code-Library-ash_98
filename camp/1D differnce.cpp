#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

ll ar[mx],Diff[mx];

int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&ar[i]);
    for(int i=1;i<=n;i++)Diff[i]=ar[i]-ar[i-1];

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        Diff[x]+=val;
        Diff[y+1]-=val;
    }
    for(int i=1;i<=n;i++)ar[i]=Diff[i]+ar[i-1];
    for(int i=1;i<=n;i++)printf("%lld%c",ar[i],(i==n)?'\n':' ');

    return 0;
}

