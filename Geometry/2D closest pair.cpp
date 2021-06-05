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
