#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx],enpoint[mx],cnt[mx];
char ch[mx][10];
int Trie[mx][10];
int n,m,k,ii,st;
bool f;

void Insert(int idx)
{
    int len=strlen(ch[idx]);
    int cur=1;
    for(int i=0;i<len;i++)
    {
        int val=ch[idx][i]-'0';
        if(Trie[cur][val]==0)Trie[cur][val]=++st;
        cur=Trie[cur][val];
        cnt[cur]++;
        if(enpoint[cur])f=true;
    }
    if(cnt[cur]>1)f=true;
    enpoint[cur]=1;
}

void solve()
{
   st=1;
   f=false;
   scanf("%d",&n);
   memset(enpoint,0,sizeof(enpoint));
   memset(Trie,0,sizeof(Trie));
   memset(cnt,0,sizeof(cnt));
   for(int i=0;i<n;i++)
   {
      scanf("%s",&ch[i]);
      Insert(i);
   }
   if(f)
   {
      printf("Case %d: NO\n",++ii);
   }
   else
   {
       printf("Case %d: YES\n",++ii);
   }
}

int main()
{
  // freopen("in.txt","r",stdin);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
