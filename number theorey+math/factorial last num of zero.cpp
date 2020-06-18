#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;

    ll p=1;

    ll re=0;

    while(1)
    {
        ll val=5;

        for(int i=2;i<=p;i++)val*=5;

        if(n/val==0)break;

        re+=n/val;
        p++;
    }

    printf("%lld\n",re);
}

