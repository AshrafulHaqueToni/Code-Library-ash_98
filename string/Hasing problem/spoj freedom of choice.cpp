#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx],ch1[mx];

int n,m,k,ii;

ll base[]= {307,367};
ll mod[]= {1040160883,1066517951};
///backup prime,1e9+7,1e9+9,1072857881
ll powbase[3][mx];
ll Hash[3][mx],Hash2[3][mx];

void pre()
{
    powbase[0][0]=powbase[1][0]=1;
    for(int j=0; j<2; j++)
    {
        for(int i=1; i<mx-3; i++)
        {
            powbase[j][i]=(powbase[j][i-1]*base[j])%mod[j];
        }
    }
}

void build()
{
    int len=strlen(ch);
    for(int i=len-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
        {
            Hash[j][i]=(Hash[j][i+1]*base[j]+(ch[i]-'A'+1))%mod[j];
            Hash[j][i]=(Hash[j][i]+mod[j])%mod[j];
        }
    }
    len=strlen(ch1);
    for(int i=len-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
        {
            Hash2[j][i]=(Hash2[j][i+1]*base[j]+(ch1[i]-'A'+1))%mod[j];
            Hash2[j][i]=(Hash2[j][i]+mod[j])%mod[j];
        }
    }
}

pair<ll,ll>HashVal(int i,int j)
{
    ll val1=(Hash[0][i]-(Hash[0][j+1]*powbase[0][j-i+1])%mod[0])%mod[0];
    ll val2=(Hash[1][i]-(Hash[1][j+1]*powbase[1][j-i+1])%mod[1])%mod[1];
    if(val1<0)val1+=mod[0];
    if(val2<0)val2+=mod[1];
    return {val1,val2};
}

pair<ll,ll>HashVal2(int i,int j)
{
    ll val1=(Hash2[0][i]-(Hash2[0][j+1]*powbase[0][j-i+1])%mod[0])%mod[0];
    ll val2=(Hash2[1][i]-(Hash2[1][j+1]*powbase[1][j-i+1])%mod[1])%mod[1];
    if(val1<0)val1+=mod[0];
    if(val2<0)val2+=mod[1];
    return {val1,val2};
}

string func(int target)
{
    map<pair<ll,ll>,int>mp;
    for(int i=0;i<=n-target;i++)
    {
        pair<ll,ll>tem=HashVal(i,i+target-1);
        mp[tem]=i;
    }
    int pos=-1;
    for(int i=0;i<=m-target;i++)
    {
        pair<ll,ll>tem=HashVal2(i,i+target-1);
        if(mp.count(tem))
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)return "-1";
    string ret;
    for(int j=pos;j<=pos+target-1;j++)ret+=ch1[j];
    return ret;
}

void solve()
{
    scanf("%d%s%s",&n,ch,ch1);
    m=n;
    build();
    int lo=1,hi=min(n,m);
    string s="";
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        string tem=func(mid);
        if(tem=="-1")
        {
            hi=mid-1;
        }
        else
        {
            s=tem;
            lo=mid+1;
        }
    }
    cout<<s<<endl;
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
  // scanf("%d",&t);
  pre();
   while(t--)solve();
   return 0;
}
