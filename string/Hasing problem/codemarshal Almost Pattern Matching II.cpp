#include<bits/stdc++.h>
using namespace std;

///https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/A
#define mx 1200005
#define ll long long

int ar[mx];
char ch[mx],pattern[mx];
int n,m,k,ii;

int base[]= {11};
int mod = 367;

int powbase[mx];
int Hash[mx],HashP[mx];

void pre()
{
    powbase[0]=1;
    for(int i=1; i<mx-4; i++)
    {
        powbase[i]=(powbase[i-1]*base[0]);
        if(powbase[i]>=mod)powbase[i]%=mod;
    }
}

void build()
{
    int len=strlen(ch);
    Hash[len]=0;
    for(int i=len-1; i>=0; i--)
    {
            Hash[i]=(Hash[i+1]*base[0]+(ch[i]-'a'+1));
            if(Hash[i]>=mod)Hash[i]%=mod;
    }
    len=strlen(pattern);
    HashP[len]=0;
    for(int i=len-1; i>=0; i--)
    {
            HashP[i]=(HashP[i+1]*base[0]+(pattern[i]-'a'+1));
            if(HashP[i]>=mod)HashP[i]%=mod;
    }
}
bool HashVal(int i,int j,int bat)
{
    int tem=(Hash[j+1]*powbase[j-i+1]);
    if(tem>=mod)tem%=mod;
    //while(tem>=mod)tem-=mod;
    int val1=(Hash[i]-tem);
    if(val1>=mod)val1-=mod;
    if(val1<0)val1+=mod;


    i-=bat;
    j-=bat;

    tem=(HashP[j+1]*powbase[j-i+1]);
    if(tem>=mod)tem%=mod;
    //while(tem>=mod)tem-=mod;
    int val11=(HashP[i]-tem);
    if(val11>=mod)val11-=mod;
    if(val11<0)val11+=mod;

    if(val11==val1)return true;

    return false;

}

void solve()
{
    scanf("%s%s%d",ch,pattern,&k);
    int re=0;
    n=strlen(ch);
    m=strlen(pattern);
    build();
    for(int i=0; i<=n-m; i++)
    {
        int be=i,en=i+m-1;
        int cnt=0;
        for(int j=0; j<=k; j++)
        {
            int lo=be,hi=en;
            int miss=-1;
            while(lo<=hi)
            {
                int mid=(lo+hi)/2;

                bool p=HashVal(be,mid,i);

                if(p)
                {
                    lo=mid+1;
                }
                else
                {
                    miss=mid;
                    hi=mid-1;
                }
            }

            if(miss==-1)
            {
                re++;
                break;
            }
            else
            {
                be=miss+1;
                cnt++;
            }
            if(be>en)
            {
                if(cnt<=k)re++;
                break;
            }
        }
    }

    printf("Case %d: %d\n",++ii,re);
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t=1;
    pre();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
