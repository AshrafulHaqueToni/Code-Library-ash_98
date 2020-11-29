#define ll long long
#define mx 1000055
#define mod 1000000007

int lp[mx];
vector<int>prime;
map<int,int>pf[mx];
ll fact[mx],inv[mx];

void sieve()
{
    for(int i=2;i<mx-3;i++)
    {
        if(lp[i]==0)
        {
            prime.push_back(i);
            lp[i]=i;
        }
        for(int j=0;j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<mx-3;j++)
            lp[i*prime[j]]=prime[j];
    }

    for(int i=2;i<mx-3;i++)
    {
        int p=i/lp[i];
        pf[i]=pf[p];
        pf[i][lp[i]]++;
    }
}

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void fact_cal()
{
    fact[0]=1;
    for(int i=1;i<=mx-3;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    inv[mx-3]=bigmod(fact[mx-3],mod-2);
    for(int i=mx-4;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mod;
}
