// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

vector<int>pf;
int n,m,ii,k;

ll val,limit;

void func(int i,int cnt,ll lcm)
{
	if(lcm>limit)return;

	if(i==m)
	{
		if(cnt==0)return;
		if(cnt&1)val+=limit/lcm;
		else val-=limit/lcm;
		return;
	}
	func(i+1,cnt+1,(lcm*pf[i])/__gcd(lcm,(ll)pf[i]));
	func(i+1,cnt,lcm);
}

void solve()
{
	scanf("%d",&n);
	ll l,r;
	scanf("%lld%lld",&l,&r);
	pf.clear();
	if(n%2==0)pf.push_back(2);
	while(n%2==0)
	{
		n/=2;
	}
	for(ll i=3;i*i<=n;i+=2)
	{
		if(n%i==0)
		{
			pf.push_back(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)pf.push_back(n);
	val=0;
	m=pf.size();
	limit=r;
	func(0,0,1);  /// # of value [1,r] and n has gcd>1
    ll re=r-val;
    val=0;
    limit=l-1;
    func(0,0,1);
    re-=(l-1-val); /// # of value [1,l-1] and n has gcd>1

    printf("%lld\n",re ); /// total # of value [l,r] and n has gcd=1 that means co-prime


}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
