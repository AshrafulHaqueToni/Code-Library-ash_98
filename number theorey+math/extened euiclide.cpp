#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct GCD_type { ll x, y, d; };

GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

int main()
{
  ll a,b;
  scanf("%lld%lld",&a,&b);
  auto pom=ex_GCD(a,b);
  printf("%lld\n",pom.d);
  printf("%lld %lld\n",pom.x,pom.y);
}
