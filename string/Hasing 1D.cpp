#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];
int n,m,k,ii;

ll base[]= {307,367};
ll mod[]= {1040160883,1066517951};
///backup prime,1e9+7,1e9+9,1072857881
ll powbase[3][mx];
ll Hash[3][mx];

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
            Hash[j][i]=(Hash[j][i+1]*base[j]+(ch[i]-'0'))%mod[j]; ///alphabet hole ch[i]-'a'+1
            Hash[j][i]=(Hash[j][i]+mod[j])%mod[j];
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

void solve()
{
     scanf("%s",ch);
     build();
     int q;
     scanf("%d",&q);
     while(q--)
     {
         int x,y,x1,y1;///0 base index
         scanf("%d%d%d%d",&x,&y,&x1,&y1);
         pair<int,int>p,p1;
         p=HashVal(x,y);
                  p1=HashVal(x1,y1);
         cout<<p.first<<" "<<p.second<<" "<<p1.first<<" "<<p1.second<<endl;
         if(p==p1)
         {
             printf("They are equal subarray\n");
         }
         else printf("They are not equal subarray\n");

     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t=1;
    //scanf("%d",&t);
    pre();
    while(t--)solve();
    return 0;
}
