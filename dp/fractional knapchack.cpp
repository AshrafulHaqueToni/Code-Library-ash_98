#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 100005
#define PII pair<int,int>

int a[mx+10];
char ch[mx+10];
int n;
vector<PII>v;

bool cmp(PII A,PII B)
{
    return A.second*B.first>A.first*B.second;
}

void solve(int ii)
{
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int weight,price;
        scanf("%d%d",&weight,&price);
        v.push_back(PII(weight,price));
    }

    sort(v.begin(),v.end(),cmp);

    int weight;
    scanf("%d",&weight);

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int z=min(weight,v[i].first);
        weight-=z;
        ans+=z*v[i].second;
    }

    printf("Maximum Cost: %d\n",ans);

   return;
}

int main()
{
    int t=1;

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}

