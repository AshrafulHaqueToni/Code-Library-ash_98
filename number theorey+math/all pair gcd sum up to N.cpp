#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 4000005

///it works for this condition .for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)sum+=gcd(i,j); thats why phi[1]=0;

int phi[mx];
ll re[mx];

void eulor_totient(int n)
{
    for(int i=2; i<=n; i++) phi[i]=i;
    for(int i=2; i<=n; i+=2)
    {
        phi[i]>>=1;
    }
    for(int i=3; i<=n; i+=2)
    {
        if(phi[i]==i)
        {
            phi[i]--;
            for(int j=2*i; j<=n; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=2;j*i<=n;j++)   /// if want  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sum+=gcd(i,j)
        {                         /// this loop start from 1
            re[i*j]+=i*(ll)phi[j];
        }
    }
    for(int i=1;i<=n;i++)re[i]+=re[i-1];
}


void solve()
{
    while(1)
    {

        int n;
        scanf("%d",&n);
        if(n==0)break;
        printf("%lld\n",re[n]);
    }
}
int main()
{
    int t=1;
    eulor_totient(mx-5);
    //scanf("%d",&t);
    while(t--)solve();
    return 0;
}
