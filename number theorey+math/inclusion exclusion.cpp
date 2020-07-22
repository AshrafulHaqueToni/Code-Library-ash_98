#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[20];

int m,k,ii;
/// koto gulo number ace[1,n] jara a1 or a2 or a3...,am dara divide
/// if m=3 and 3 values are a1,a2,a3 then
/// |a1 U a2 U a3|=|a1|+|a2|+|a3|-|a1 union a2|-|a2 union a3|-|a1 union a3|+|a1 union a2 union a3|
/// if number of cadidate is odd do add or do substract
/// time complexity 2^m.

ll re1,n;

void func(int idx,int cnt,ll lcm)
{
    if(lcm>n)break;
    if(idx==m)
    {
        if(cnt==0)return;

        if(cnt & 1)re1+=n/lcm;
        else re1-=n/lcm;
        return;
    }
    func(idx+1,cnt+1,(lcm*ar[idx])/__gcd(lcm,(ll)ar[idx]));
    func(idx+1,cnt,lcm);
}

void solve()
{

    scanf("%lld%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",&ar[i]);
    ///using bitmask
    ll re=0;
    for(int i=1; i<(1<<m);i++)
    {
        ll lcm=1;
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(i & (1<<j))
            {
                cnt++;
                lcm=(lcm*ar[j])/__gcd(lcm,(ll)ar[j]);
                if(lcm>n)break;
            }
        }
        if(cnt&1)re+=n/lcm;
        else re-=n/lcm;
    }
    printf("%lld\n",re);

    /// using recursive

     func(0,0,1);
    printf("%lld\n",re1);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
  // scanf("%d",&t);
   while(t--)solve();
   return 0;
}
