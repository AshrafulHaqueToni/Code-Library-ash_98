// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx][2];
char ch[mx];
int n,m,ii,k;

namespace Segment_Tree
{
    const int N=200005;
    vector<int>Tree[N*4][2];

    void init(int node,int f,int be,int en)
    {
        Tree[node][f].clear();
        if(be==en)
        {
            if(ar[be][f])Tree[node][f].push_back(ar[be][f]);
            return;
        }
        int mid=(be+en)/2;
        init(node*2,f,be,mid);
        init(node*2+1,f,mid+1,en);
        merge(Tree[node*2][f].begin(),Tree[node*2][f].end(),
            Tree[node*2+1][f].begin(),Tree[node*2+1][f].end(),
            back_inserter(Tree[node][f]));
    }

    int query(int node,int f,int be,int en,int i,int j,int val)
    {
        if(be>j || en<i)return 0;
        if(be>=i && en<=j)
        {
            int re=0;
            int s=0,e=Tree[node][f].size()-1;
            int tot=e+1;
            if(f)
            {
                while(s<=e)
                {
                    int j=(e+s)/2;
                    if(Tree[node][f][j]>val)e=j-1;
                    else
                    {
                        re=j+1;
                        s=j+1;
                    }
                }
            }
            else
            {
                 while(s<=e)
                {
                    int j=(e+s)/2;
                    if(Tree[node][f][j]<val)s=j+1;
                    else
                    {
                        re=tot-j;
                        e=j-1;
                    }
                }
            }
            return re;
        }
        int mid=(be+en)/2;
        return query(node*2,f,be,mid,i,j,val)+query(node*2+1,f,mid+1,en,i,j,val);
    }

    void dbg_test(int node,int be,int en)
    {
        if(be==en)return;
        int mid=(be+en)/2;
        dbg_test(node*2,be,mid);
        dbg_test(node*2+1,mid+1,en);
    }
}
using namespace Segment_Tree;
 
void solve()
{
    scanf("%d%d",&n,&m);

    memset(ar,0,sizeof(ar));
    
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<=y)
        {
           ar[x][0]=y;
        }
        else
        {
            ar[x][1]=y;
        }
    }
    init(1,0,1,n+m);
    init(1,1,1,n+m);

    ll re=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        re+=query(1,1,1,n+m,x+1,n+m,y);
        re+=query(1,0,1,n+m,1,x-1,y); 
    }
    printf("Case %d: %lld\n",++ii,re );

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
