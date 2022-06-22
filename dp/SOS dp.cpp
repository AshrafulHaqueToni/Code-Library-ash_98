// Created by ash_98
///https://codeforces.com/contest/165/problem/E

#include<bits/stdc++.h>
using namespace std;

#define mx 4500005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,ii,k;
int Ace[(1<<22)+10];
int dp[mx];
///int id= __builtin_ctz(mask); its give the position of the first one from the left
/// int tot= __builtin_popcount(mask); number of one bit .
int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}

bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

/*
iterate all the submask of a mask

for(int mask=1;mask<(1<<sz);mask++)
    {
        int tmask=mask&(mask-1);
        
        while(tmask)
        {
            cout<<tmask<<endl;
           // dp[mask]=min(dp[mask],dp[tmask]+dp[mask^tmask]);
            tmask=(tmask-1)&mask;
        }
        

    }
*/

void solve()
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
		dp[ar[i]]=ar[i];
	}

	for(int i=0;i<22;i++)
	{
		for(int mask=0;mask<(1<<22);mask++)
		{
			if(chk(mask,i))dp[mask]=max(dp[mask],dp[mask^(1<<i)]);
		}
	}

	int boro=(1<<22)-1;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dp[boro^ar[i]]);
	}

}

int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}
