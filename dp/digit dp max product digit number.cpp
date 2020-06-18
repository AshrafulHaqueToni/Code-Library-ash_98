#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll product(ll n)
{
    ll val=1;

    while(n)
    {
        val*=(n%10);
        n/=10;
    }

    return val;
}

ll func(ll l,ll r)
{
    string s=to_string(l);
    string t=to_string(r);

    ll ans=r;

    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='0')continue;

        string cur=t;

        cur[i]=((cur[i]-'0')-1)+'0';

        for(int j=i+1;j<cur.size();j++)
            cur[j]='9';

        ll re=0;

        for(auto ch: cur)
            re=re*10+(ch-'0');

        if(re>=l && product(ans)<product(re))
            ans=re;
    }

    return ans;
}


int main()
{
    ll l,r;

    scanf("%lld %lld",&l,&r);

    printf("%lld\n",func(l,r));

    return 0;
}
