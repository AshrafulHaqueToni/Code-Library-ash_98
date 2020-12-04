// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 20005
#define ll long long
#define mod 1000000007

char ch[mx];
int n,m,ii,k;
int Block_Id[mx];

struct node
{
   int l,r,id;
   node(){}
   node(int l,int r,int id)
   {
     this->l=l;
     this->r=r;
     this->id=id;
   }
   bool operator < (const node& u)
   {
        int a=Block_Id[l],b=Block_Id[u.l];

        if(a==b)
        {
            return (a & 1 ? (r > u.r) : (r < u.r));
        }
        else return a<b;
   }
};

node que[mx];
int ans[mx];

namespace Segment_Tree
{
    const int N=20005;
    int Tree[N*4];
    int Lazy[mx*4];
    int ar[N],br[N];

    void Relax(int node,int be,int en)
    {
        if(!Lazy[node])return;

        Tree[node]+=Lazy[node];
        if(be!=en)
        {
            Lazy[node*2]+=Lazy[node];
            Lazy[node*2+1]+=Lazy[node];
        }
        Lazy[node]=0;
    }

    void init(int node,int be,int en)
    {
        Lazy[node]=0;
        if(be==en)
        {
            Tree[node]=ar[be];
            return;
        }
        int mid=(be+en)/2;
        init(node*2,be,mid);
        init(node*2+1,mid+1,en);
        Tree[node]=Tree[node*2]+Tree[node*2+1];
    }

    void update(int node,int be,int en,int pos,int val)
    {
       // Relax(node,be,en);
        if(be> pos || en<pos)return;
        if(be==en)
        {
            Tree[node]+=val;
            return;
        }
        int mid=(be+en)/2;
        update(node*2,be,mid,pos,val);
        update(node*2+1,mid+1,en,pos,val);
        Tree[node]=Tree[node*2]+Tree[node*2+1];
    }

    void Rupdate(int node,int be,int en,int i,int j,int val)
    {
        Relax(node,be,en);
        if(be>j || en<i)return ;
        if(be>=i && en<=j)
        {
            Lazy[node]+=val;
            Relax(node,be,en);
            return;
        }
        int mid=(be+en)/2;
        Rupdate(node*2,be,mid,i,j,val);
        Rupdate(node*2+1,mid+1,en,i,j,val);
        Tree[node]=max(Tree[node*2],Tree[node*2+1]);
    }

    int query(int node,int be,int en,int i,int j)
    {
        //Relax(node,be,en);
        if(be>j || en<i)return 0;
        if(be>=i && en<=j)return Tree[node];
        int mid=(be+en)/2;
        return query(node*2,be,mid,i,j)+query(node*2+1,mid+1,en,i,j);
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
    scanf("%d",&n);
    int sz=sqrt(n);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]),br[i]=ar[i],Block_Id[i]=i/sz;
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        que[i]=node(x,y,i);
    }

    sort(que+1,que+1+q);

    // Compressing Coordinates . its a alternative of map
    sort(br+1,br+n+1);
    k = unique(br+1,br+n+1)-br-1;
    for(int i=1;i<=n;i++) ar[i]=lower_bound(br+1,br+k+1,ar[i])-br;

    int left=que[1].l;
    int right=left-1;
    int re=0;

    for(int i=1;i<=q;i++)
    {
        node Now=que[i];
      
        while(left<Now.l)
        {
             re-=query(1,1,n,1,ar[left]-1);
            update(1,1,n,ar[left],-1);
            left++;
        }

        while(left>Now.l)
        {
            re+=query(1,1,n,1,ar[--left]-1);
            update(1,1,n,ar[left],1);    
        }

        while(right<Now.r)
        {
            re+=query(1,1,n,ar[++right]+1,n);
            update(1,1,n,ar[right],1);
        }
        while(right>Now.r)
        {
            re-=query(1,1,n,ar[right]+1,n);
            update(1,1,n,ar[right],-1);
            right--;
        }
        ans[Now.id]=re;
    }

    for(int i=1;i<=q;i++)printf("%d\n",ans[i] );
}

int main()
{
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
    return 0;
}
