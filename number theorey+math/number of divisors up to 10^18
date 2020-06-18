#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<int>prime;
bool is_composite[1000005];

void sieve(int n)
{
    for(int i=2; i*i<n; i++)
    {
        if(is_composite[i]==false)
        {
            for(int j=i*i; j<n; j+=i)
            {
                is_composite[j]=true;
            }
        }
    }

    prime.push_back(2);

    for(int i=3; i<n; i+=2)
    {
        if(is_composite[i]==false)
            prime.push_back(i);
    }
}

ll big_Multiply(ll a,ll b,ll n)
{
    if(b==0)
        return 0;

    if(b%2==0)
    {
        ll s=big_Multiply(a,b/2,n);
        return (2*s)%n;
    }
    else
        return (a+big_Multiply(a,b-1,n))%n;
}

ll bin_Exp(ll b,ll e,ll m)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll x=bin_Exp(b,e/2,m);
        return big_Multiply(x,x,m);
    }
    else
        return (big_Multiply(b,bin_Exp(b,e-1,m),m));
}


bool is_compair(ll a,ll s, ll d,ll n)
{
    ll x=bin_Exp(a,d,n);

    if(x==1 || x== n-1)
        return false;

    for(int i=1; i<s; i++)
    {
        x=big_Multiply(x,x,n);
        if(x==n-1)
            return false;

    }

    return true;
}

bool Miller(ll n,int iter)
{
    if(n<=3)
    {
        return n==2 || n==3;
    }

    if(n%2==0)
        return 0;

    ll s=0,d=n-1;

    while(d%2==0)
    {
        s++,d/=2;
    }

    for(int i=1; i<=iter; i++)
    {
        ll a=2+rand()%(n-3);

        if(is_compair(a,s,d,n))
            //continue;

            return false;
    }
    return true;
}

int main()
{
    sieve(1000005);

    ll num;
    scanf("%lld",&num);
    ll ans=1;

    for(auto it:prime)
    {
        if(1LL*it*it*it>num)
            break;
        int cnt=1;

        if(num%it==0)
        {
            while(num%it==0)
            {
                num/=it;
                cnt++;
            }
        }
        ans*=cnt;
    }

    ll val=sqrt(num);

    if(Miller(num,25))
    {
        ans*=2;
    }
    else if(val*val==num && val>1)
    {
        ans*=3;
    }
    else if(num!=1)
    {
        ans*=4;
    }

    printf("%lld\n",ans);
}
