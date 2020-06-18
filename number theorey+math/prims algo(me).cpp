#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> >v[100005];

vector<int> color(100005,0),parent(100005,0);

map<int,int>dis;

int edge,Node;
bool flag;


void span(int start)
{

    for(int i=0; i<=100005; i++)
        dis[i]=INT_MAX;

    dis[start]=0;

    parent[start]=-1;

    set<pair<int,int> > s;

    s.insert({dis[start],start});


    while(!s.empty())
    {
        auto it=s.begin();

        int node=it->second;

        s.erase(it);

        color[node]=1;

        for(int i=0; i<v[node].size(); i++)
        {
            int n1=v[node][i].first;

            if(n1==Node)flag=true;

            int cost=v[node][i].second+dis[node];

            if(cost<dis[n1] && !color[n1])
            {
                auto fi=s.find({dis[n1],n1});

                if(fi!=s.end())
                {
                    s.erase(fi);
                }

                dis[n1]=cost;
                s.insert({dis[n1],n1});
                parent[n1]=node;
            }
        }
    }
}

void findpath(int target)
{
    if(!flag)
    {
        printf("-1\n");
        return;
    }

    stack<int>s;
    s.push(target);

    while(1)
    {
        if(parent[target]==-1)
            break;
        s.push(parent[target]);
        target=parent[target];
    }


    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
}


int main()
{
    scanf("%d%d",&Node,&edge);

    for(int i=0; i<edge; i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }

    span(1);

    findpath(Node);

    return 0;
}


