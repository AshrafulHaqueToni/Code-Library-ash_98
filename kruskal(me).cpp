///***Bismillahir Rahmanir Rahim***///

///*********************************///
///******Ashraful Haque Toni********///
///********Dept. of CSE,JnU*********///
///email:ashrafulhaquetoni@gmail.com///
///*******contact:01640690531*******///
///*********************************///


#include<bits/stdc++.h>

using namespace std;

#define         ash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         pb push_back
#define         mp make_pair
#define         sc(n) scanf("%d",&n);
#define         scl(n) scanf("%I64d",&n);
#define         sc2(m,n) scanf("%d%d",&m,&n);
#define         sc2l(m,n) scanf("%I64d%I64d",&m,&n);
#define         pf printf
#define         Big(x,y) max(x,y);
#define         Small(x,y) min(x,y);
#define         input(array,size) for(int i=0;i<size;i++)cin>>array[i];
#define         newline pf("\n");
#define         f(s,l,in) for(ll i=s;i<l;i+=in)
#define         Max INT_MAX
#define         Min INT_MIN
#define         pi acos(-1.0)
#define         Memset(a,val) memset(a,val,sizeof(a));

const int mod =1e9+7;
const int N =5e6+5;
typedef long long ll;

vector<pair<int,pair<int,int> > >graph;
vector<pair<int,int> >va[200005];
vector<int>parent(200005);
int node,edge;


int Findparent(int x)
{
    if(x!=parent[x])
    {
        while(1){
            if(x==parent[x])break;
            x=parent[x];
        }
    }
    return x;
}

void Union(int x,int y)
{
    parent[Findparent(x)]=parent[Findparent(y)];
}

void kruskal()
{
    //cout<<0;
    for(int i=0;i<graph.size();i++)
    {
      int u=graph[i].second.first;
      int v=graph[i].second.second;
      int w=graph[i].first;

      if(Findparent(u)!=Findparent(v)){
        va[u].pb({v,w});
        va[v].pb({u,w});
        cout<<"("<<u<<","<<v<<","<<w<<")";
        Union(u,v);
      }
    }
}

void initialize()
{
    //cout<<0;
    for(int i=0;i<node;i++)parent[i]=i;
}


int main()
{

    ash;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int a1,a2,w;
        cin>>a1>>a2>>w;
        graph.pb({w,{a1,a2}});
    }
    sort(graph.begin(),graph.end());
    reverse(graph.begin(),graph.end());
    initialize();
    kruskal();



    return 0;
}


