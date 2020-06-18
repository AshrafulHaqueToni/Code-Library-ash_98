#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[15][2][400][2];
const ll mpos=11;
char ch[40];
ll digitval;

void convert(ll n)
{
    for(ll i=0; i<mpos; i++)
    {
        ch[i]=(n%10)+'0';
        n/=10;
    }

    reverse(ch,ch+mpos);
    ch[mpos]=0;
}

ll func(ll pos,ll smallornot,ll digitvalcnt,ll startornot)
{
    if(pos==mpos)
        return digitvalcnt;

    if(dp[pos][smallornot][digitvalcnt][startornot]!=-1)
        return dp[pos][smallornot][digitvalcnt][startornot];

    ll be=0;
    ll en=9;

    if(!smallornot)
        en=ch[pos]-'0';

    ll re=0;

    for(ll i=be; i<=en; i++)
    {
        ll ismallornot= smallornot | (i<en);
        ll idigitvalcnt=digitvalcnt+ i;
        ll istartornot= startornot | (i!=0);

        re+=func(pos+1,ismallornot,idigitvalcnt,istartornot);
    }

    return dp[pos][smallornot][digitvalcnt][startornot]=re;
}



int main()
{

    ll n,m,sum=0;
    scanf("%lld%lld",&m,&n);

   // for(digitval=1; digitval<=9; digitval++)
   // {

        memset(dp,-1,sizeof dp);

        convert(n);

        ll re1=func(0,0,0,0);

        ll re2=0;

        if(m>0)
        {
            convert(m-1);
            memset(dp,-1,sizeof dp);
            re2=func(0,0,0,0);
        }

        //cout<<re1<<" "<<re2<<endl;

        sum+=(re1-re2);
   // }


    printf("%lld\n",sum);
    return 0;
}

