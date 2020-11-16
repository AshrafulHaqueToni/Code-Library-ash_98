// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007
#define block 555 ///block=sqrt(mx)+5
ll ar[mx];
char ch[mx];
int n,m,ii,k;
ll block_sum[block];
ll add_later[block];


void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&ar[i]),block_sum[i/block]+=ar[i];
	while(m--)
	{
		int ti;
		scanf("%d",&ti);
		if(ti==1)  /// range updated by O(sqrt(n))
		{
           int x,y,val;
           scanf("%d%d%d",&x,&y,&val);
           x--,y--;  /// O base index
           int Left_Block=x/block;
           int Right_Block=y/block;
           if(Left_Block==Right_Block)
           {
           	  for(int i=x;i<=y;i++)block_sum[i/block]+=val,ar[i]+=val;
           	  continue;
           }
           for(int i=Left_Block+1;i<Right_Block;i++)add_later[i]+=val;
           for(int i=x;i<(Left_Block+1)*block;i++)block_sum[i/block]+=val,ar[i]+=val;
           for(int i=Right_Block*block;i<=y;i++)block_sum[i/block]+=val,ar[i]+=val;

		}
	    else  /// range query O(sqrt(n))
	    {
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            int Left_Block=x/block;
            int Right_Block=y/block;
            ll re=0;
            if(Left_Block==Right_Block)
            {

           	  for(int i=x;i<=y;i++)re+=ar[i]+add_later[i/block];
           	  printf("%lld\n",re);
           	  continue;
            }
            for(int i=Left_Block+1;i<Right_Block;i++)re+=add_later[i]*block+block_sum[i];
            for(int i=x;i<(Left_Block+1)*block;i++)re+=add_later[i/block]+ar[i];
            for(int i=Right_Block*block;i<=y;i++)re+=add_later[i/block]+ar[i];
            printf("%lld\n",re );

	    }
	}

}

int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}