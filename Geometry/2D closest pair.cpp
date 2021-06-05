// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int m,ii,k;

ll closest_pair(vector<pair<int,int>>point)
{
    sort(point.begin(),point.end());
    set<pair<int,int>>event;
    ll re=4e18;
    int id=0;
    int n=point.size();
    for(int i=0;i<n;i++)
    {
        int sq_re=ceil(sqrt(re));
        while(point[i].first-point[id].first>=re)
        {
            event.erase(event.find({point[id].second,point[id].first}));
            id++;
        }
        pair<int,int>a={point[i].second-sq_re,point[i].first};
        pair<int,int>b={point[i].second+sq_re,point[i].first};

        auto it1=event.lower_bound(a);
        auto it2=event.upper_bound(b);

        while(it1!=it2)
        {
            int dx=point[i].first-it1->second;
            int dy=point[i].second-it1->first;
            re=min(re,1LL*dx*dx+1LL*dy*dy);
            it1++;
        }
        event.insert({point[i].second,point[i].first});
    }

    return re;

}

void solve()
{
    vector<pair<int,int>>point;
    int n;
    scanf("%d",&n);
    int csum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        csum+=x;
        point.push_back({i,csum});
    }
    printf("%lld\n",closest_pair(point));


}
 
int main()
{
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
    return 0;
}
