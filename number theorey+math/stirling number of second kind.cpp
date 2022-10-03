
/// # of ways put n items in k not empty similar boxes

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 1005

int a[mx+10];
char ch[mx+10];
int n,k;

ll dp[mx][mx];

ll func(int nn,int kk)
{
    if(kk==1)return 1;

    if(nn==kk)return 1;
    if(kk==0)return 0;


    ll &val=dp[nn][kk];

    if(val!=-1)return val;

    val=func(nn-1,kk-1)+1LL*kk*func(nn-1,kk);

    return val;
}

void solve(int ii)
{
    scanf("%d%d",&n,&k);
    memset(dp,-1,sizeof dp);
    printf("%lld\n",func(n,k));

   return;
}

int main()
{
    int t=1;

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
