#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int cnt[mx];
ll ans[mx];
int n,m,k,ii;

void solve()
{
    scanf("%d",&n);
    int boro=0;
    ll re=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        boro=max(boro,x);
        cnt[x]++;
    }
    for(int i=boro;i>=1;i--)
    {
        ll tot=0;
        for(int j=i;j<=boro;j+=i)
        {
            tot+=cnt[j];
            ans[i]-=ans[j];
        }
        if(tot<2)            /// if want k length set then use k
        {
            ans[i]=0;
        }
        else
        {
            tot=(tot*(tot-1))/2;  /// if want k length set then  nCk. n=tot;
            ans[i]+=tot;
            re+=ans[i]*i;
        }
    }
    printf("%lld\n",re);
}

/*
5
1 1 1 1 1
*/

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
  // scanf("%d",&t);
   while(t--)solve();
   return 0;
}
