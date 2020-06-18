#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 100005

int a[mx+10];
char ch[mx+10];
int n;
ll dp[mx];

ll func(int n)
{
    if(n<2)return n==0;

    ll &val=dp[n];

    if(val!=-1)return val;

    val=1LL*(n-1)*func(n-2)+1LL*(n-1)*func(n-1);

    return val;
}


void solve(int ii)
{
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);

    printf("%lld\n",func(n));

   return;
}

int main()
{
    int t=1;

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}

