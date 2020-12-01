#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 100000005


int phi[mx];

void eulor_totient(int n)
{
    for(int i=2; i<=n; i++) phi[i]=i;
    for(int i=2;i<=n;i+=2)
    {
        phi[i]>>=1;
    }
    for(int i=3; i<=n; i+=2) {
        if(phi[i]==i) {
            phi[i]--;
            for(int j=2*i; j<=n; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
}
