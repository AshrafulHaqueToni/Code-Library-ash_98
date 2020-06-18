#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll unsigned long long int

ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}

ll sumXOR(ll arr[], int n)
{
    ll sum = 0;

    for (int i = 0; i <64; i++)
    {
         ll zc = 0, oc = 0;

        ll idsum = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] % 2 == 0)
                zc++;
            else
                oc++;
            arr[j] /= 2;
        }


        idsum =(((oc*zc)%mod)*bigmod(2,i))%mod;
        sum = (sum+idsum+mod)%mod;
    }
    return sum;
}

int main()
{
    ll sum = 0;

    int n;
    cin>>n;

    ll arr[n+2];

    for(int i=0;i<n;i++)cin>>arr[i];

    sum = sumXOR(arr,n);

    cout << sum<<endl;

    return 0;
}
