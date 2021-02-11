#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

#define N 2100000

bool Mark[N+5];

vector<ll>v;


bool seive()
{
    for(int i=3; i*i<N; i+=2)
    {
        if(!Mark[i])
        {
            for(int j=i*i; j<N; j+=i*2)
                Mark[j]=1;
        }
    }
    v.push_back(2);

    for(int i=3; i<N; i+=2)
        if(!Mark[i])
            v.push_back(i);
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

ll pollard_rho(ll n)
{
    if(n==1)
        return 1;

    if(n%2==0)
        return 2;

    srand(time(NULL));

    ll x=2+rand()%(n-2);

    ll y=x;

    ll c=1+rand()%(n-1);

    ll d=1;

    while(d==1)
    {
        x=(big_Multiply(x,x,n)+c+n)%n;

        y=(big_Multiply(y,y,n)+c+n)%n;

        y=(big_Multiply(y,y,n)+c+n)%n;

        d=__gcd((x>=y? x-y:y-x),n);

        if(d==n)
            return pollard_rho(n);
    }

    return d;

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
    ll n;
    scanf("%llu",&n);

    seive();

    map<ll,int>m;

    printf("%llu= ",n);

    for(int i=0; i<v.size() && v[i]*v[i]<=n; i++)
    {
        if(n%v[i]==0)
        {
            while(n%v[i]==0)
            {
                m[v[i]]++;
                n/=v[i];
            }
        }
    }

    if(n>1)
    {
        if(Miller(n,5))
            m[n]++;
        else
        {
            ll x=pollard_rho(n);
            m[x]++;
            m[n/x]++;
        }
    }

    for(auto it=m.begin(); it!=m.end(); it++)
    {
        if(it!=m.begin())
        {
            printf("*%llu",it->first);
        }
        else
            printf("%llu",it->first);
        if(it->second>1)
        {
            printf("^%d",it->second);
        }
    }
    printf("\n");


    return 0;

}
