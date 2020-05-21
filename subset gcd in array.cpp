/// check from https://www.hackerrank.com/contests/adobe-hackathon/challenges/bokam-and-his-gcd
/// https://toph.co/arena?contest=coding-fever-round-01#!/p/gcd-probability
#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
#define mod 1000000007

ll fact[mx],dp[mx];
int ar[mx],cnt[mx];

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void fact_cal()
{
    fact[0]=1;
    for(int i=1;i<=mx-3;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}
int n,m;

void solve()
{
   scanf("%d",&n);
   int boro=0;
   for(int i=0;i<n;i++)
   {
       scanf("%d",&ar[i]);
       cnt[ar[i]]++;
       boro=max(boro,ar[i]);
   }
   for(int i=boro;i>=1;i--)
   {
       int tot=0;
       for(int j=i;j<=boro;j+=i)
       {
           tot+=cnt[j];
           if(j>i)dp[i]=(dp[i]-dp[j]+mod)%mod;
       }
       /// jodi subset length bole deya thake tobe if(tot>=length) hole (tot)C(length) bave gcd i hobe
       if(tot)
       {
           dp[i]=(dp[i]+bigmod(2,tot)-1)%mod; /// total  ke 2^tot-1 ta subset ye rakle gcd i paoya jabe
       }
   }
   for(int i=0;i<n;i++)
   {
       printf("%d",dp[ar[i]]);
       if(i+1!=n)printf(" ");
       else printf("\n");
   }
}

int main()
{
    int t=1;
    fact_cal();
    while(t--)solve();
    return 0;
}
