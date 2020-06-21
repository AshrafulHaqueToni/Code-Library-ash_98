#include<bits/stdc++.h>
using namespace std;
 
#define mx 2500005
#define ll long long
const int N=50005;
 
char ch[N][55];
int Trie[mx][5],cnt[mx];
int n,m,k,ii,st,re;
 
void Insert(int idx)
{
    int len=strlen(ch[idx]);
    int cur=1;
    for(int i=0;i<len;i++)
    {
        char tem=ch[idx][i];
        int val;
        if(tem=='A')val=1;
        if(tem=='G')val=2;
        if(tem=='C')val=3;
        if(tem=='T')val=4;
        if(Trie[cur][val]==0)Trie[cur][val]=++st;
        cur=Trie[cur][val];
        cnt[cur]++;
    }
}
 
void dfs(int node,int dis)
{
    for(int i=1;i<=4;i++)
    {
        if(Trie[node][i])dfs(Trie[node][i],dis+1);
    }
    re=max(re,cnt[node]*dis);
}
 
void solve()
{
   scanf("%d",&n);
   st=1;
   re=0;
   memset(Trie,0,sizeof(Trie));
   memset(cnt,0,sizeof(cnt));
   for(int i= 1;i<=n ;i++)
   {
     scanf("%s",ch[i]);
     Insert(i);
   }
   dfs(1,0);
   printf("Case %d: %d\n",++ii,re);
}
 
int main()
{
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
