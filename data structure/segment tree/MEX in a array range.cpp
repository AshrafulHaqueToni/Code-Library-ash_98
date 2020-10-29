#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}



int m,n,k,ii,q;
int Tree[mx*4];
int ans[mx],ar[mx];
vector<pair<int,int>>point[mx];


void update(int node,int be,int en,int val,int pos)
{
  if(pos>en || pos<be)return;
  if(be==en)
  {
    Tree[node]=val;
    return;
  }
  int mid=(be+en)/2;
  update(node*2+1,be,mid,val,pos);
  update(node*2+2,mid+1,en,val,pos);
  Tree[node]=min(Tree[node*2+1],Tree[node*2+2]);
}

int query(int node,int be,int en,int left)
{
  if(be==en)return be;
  int mid=(be+en)/2;
  if(Tree[node*2+1]<left)return query(node*2+1,be,mid,left);
  else return query(node*2+2,mid+1,en,left);
}


void solve()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&ar[i]);   /// Let 0<=ar[i]<=n
  scanf("%d",&q);
  for(int i=1;i<=q;i++)
  {
    int l,r;
    scanf("%d%d",&l,&r);
    point[r].push_back({l,i});
  }
  for(int i=1;i<=n;i++)
  {
    sort(point[i].rbegin(),point[i].rend());
  }

  for(int i=1;i<=n;i++)
  {
     update(0,0,n,i,ar[i]);
     for(auto it:point[i])
     {
        ans[it.second]=query(0,0,n,it.first);
     }
  }

  for(int i=1;i<=q;i++)printf("%d\n",ans[i] );


}

int main()
{
  IO();
  int t=1;
 // scanf("%d",&t);
  while(t--)
  {
    solve();
  }
  return 0;
}
