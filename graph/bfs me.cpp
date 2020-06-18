#include<bits/stdc++.h>
using namespace std;

#define white 1
#define gray 2
#define black 3

map<string,int>mp1;
map<int,string>mp2;
vector<int>v[1000];
vector<int>parent(1000),dis(1000),color(1000);

int node;

void bfs(int startnode)
{
    for(int i=0;i<node;i++)
    {
        color[i]=white;
        parent[i]=-1;
        dis[i]=-1;
    }
    queue<int>q;
    q.push(startnode);
    dis[startnode]=0;

    while(!q.empty())
    {
        int x=q.front();
        cout<<mp2[x]<<" ";
        q.pop();
        color[x]=gray;

        for(int i=0;i<v[x].size();i++)
        {
            if(color[v[x][i]]==white)
            {
                q.push(v[x][i]);
                if(dis[v[x][i]]<0)
                {
                    dis[v[x][i]]=dis[x]+1;
                    parent[v[x][i]]=x;
                }

            }
        }
        color[x]=black;

    }
   puts("");

}

int main()
{
    int edge;
    cin>>edge;
    int k=0;
    for(int i=0;i<edge;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(mp1.find(s1)==mp1.end())
        {
           mp1[s1]=k;
           mp2[k]=s1;
           k++;
        }
        if(mp1.find(s2)==mp1.end())
         {

          mp1[s2]=k;
          mp2[k]=s2;
          k++;
         }
         v[mp1[s1]].push_back(mp1[s2]);
         v[mp1[s2]].push_back(mp1[s1]);


    }
   /* for(int i=0;i<k;i++)
    {
        cout<<mp2[i]<<"->";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<mp2[v[i][j]]<<" ";
        }
        cout<<endl;
    }*/
    node=k;
    bfs(0);
    cout<<mp2[parent[mp1["D"]]]<<" "<<dis[mp1["D"]]<<endl;

}
