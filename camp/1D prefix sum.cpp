#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
int prefix[mx];

char ch[mx];

int n,m,k,ii;

void solve()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
     for(int i=1;i<=n;i++)
     {
         prefix[i]=prefix[i-1]+ar[i];
     }

     while(m--)
     {
         int l,r;
         scanf("%d%d",&l,&r);
         int sum=prefix[r]-prefix[l-1];
         printf("%d\n",sum);
     }

}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   //scanf("%d",&t);
   while(t--)solve();
   return 0;
}
