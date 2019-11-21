#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
#define mx 1000009

ll ans[mx];
ll sumsq[mx];
ll sqsum[mx];

vector<int>v[mx];

ll bigmod(ll n,ll p)
{
    if(p==0)
        return 1;
    if(p==1)
        return (n+mod)%mod;
    if(p%2)
        return (bigmod(n,p-1)*n+mod)%mod;
    else
    {
        ll x=bigmod(n,p/2);
        return (x*x+mod)%mod;
    }
}

ll modinverse(ll n)
{
    return bigmod(n,mod-2)%mod;
}

void divisors()
{
    for(int i=1; i<mx; i++)
    {
        for(int j=i; j<mx; j+=i)
            v[j].push_back(i);
    }
}

///(a*b)/x+(b*c)/x+(c*a)/x=  (ab+bc+ca)/x
///(a+b+c)^2=a*a+b*b+c*c+2(ab+bc+ca)
///(ab+bc+ca)=((a+b+c)^2-(aa+bb+cc))/2


int main()
{
    divisors();

    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        int val;

        scanf("%d",&val);

        for(int it:v[val])
        {
            sumsq[it]=((sumsq[it]+val)%mod);
            sqsum[it]=(sqsum[it]+bigmod(val,2))%mod;
        }
    }

    ll re=0;

    for(ll i=mx-1; i>=1; i--)
    {
        ll cur=(bigmod(sumsq[i],2)-sqsum[i]);

        cur=(cur+mod)%mod;

        for(ll j=i+i; j<mx; j+=i)
        {
            cur-=ans[j];
            cur=(cur+mod)%mod;
        }

        ans[i]=cur;

        re=(re+(cur*modinverse(i))%mod)%mod;
    }

    re=(re*modinverse(2))%mod;

    printf("%lld\n",re);




    return 0;
}
