#include<bits/stdc++.h>
using namespace std;
///https://www.spoj.com/problems/TRYCOMP/
#define mx 5000005
#define ll long long

int best[mx];
string ch,re[mx];
int Trie[mx][26];
map<string,int>mp;
int n,m,k,ii,st=1,cnt;

void Insert(string s)
{
    int len=s.size();
    int cur=1;
    for(int i=0;i<len;i++)
    {
        int val=s[i]-'a';
        if(Trie[cur][val]==0)Trie[cur][val]=++st;
        cur=Trie[cur][val];
        if(best[cur]<mp[s])
        {
            best[cur]=mp[s];
            re[cur]=s;
        }
    }
}

int query()
{
    int len=ch.size();
    int cur=1;
    for(int i=0;i<len;i++)
    {
        int val=ch[i]-'a';
        if(Trie[cur][val]==0)return -1;
        cur=Trie[cur][val];
    }
    return cur;
}



void solve()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
         cin>>ch;
         mp[ch]++;
     }

     for(auto it:mp)Insert(it.first);

     scanf("%d",&m);
     while(m--)
     {
         cin>>ch;
         cnt=0;
         int cur=query();
         if(cur==-1)printf("-1\n");
         else
         {
         cout<<re[cur]<<" "<<mp[re[cur]]<<"\n";
         }
     }


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
