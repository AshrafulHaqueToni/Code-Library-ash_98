///range ye element jog kore///

#include<bits/stdc++.h>
using namespace std;

#define mx 100005

struct me
{
    int c1;
    me()
    {
        c1=0;
    }
}sum[4*mx],zero;


int lazy[4*mx];

me Merge(me p1,me p2)
{
    me re;

    re.tree=p1.tree+p2.tree;

    return re;
}


void relax2(int node,int be,int en,int val)
{
    sum[node].tree+=(en-be+1)*val;
    if(en!=be)
    {
        lazy[node*2]+=val;
        lazy[node*2+1]+=val;
    }
    lazy[node]=0;
}

void relax(int node,int be,int en)
{
    sum[node].tree+=(en-be+1)*lazy[node];
    if(en!=be)
    {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}

me query(int node,int be,int en,int i,int j)
{
    if(i>en||j<be)return zero;///totally out

    if(lazy[node])
    {
        relax(node,be,en);
    }

    if(i<=be&&j>=en)return sum[node];///totally in

    int left=node*2;
    int right=left+1;
    int mid=(be+en)/2;

    me p1=query(left,be,mid,i,j);
    me p2=query(right,mid+1,en,i,j);

    return Merge(p1,p2);
}

void rangeupdate(int node,int be,int en,int i,int j,int val)
{
    if(lazy[node])
    {
        relax(node,be,en);
    }
    if(i>en||j<be)return;///totally out

    if(i<=be&&j>=en)///totally in

    {
        lazy[node]+=val;
        relax(node,be,en);
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(be+en)/2;

    rangeupdate(left,be,mid,i,j,val);
    rangeupdate(right,mid+1,en,i,j,val);

    sum[node].tree=sum[left].tree+sum[right].tree;


}


void update(int node,int be,int en,int pos,int val)
{
    if(pos<be||pos>en)return;

    if(be==en){
        sum[node].tree+=val;
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(be+en)/2;


    update(left,be,mid,pos,val);
    update(right,mid+1,en,pos,val);

    sum[node].tree=sum[left].tree+sum[right].tree;
}


int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        update(1,1,n,i,a);
    }

    for(int i=1;i<=n*4;i++)
    {
        cout<<sum[i].tree<<" ";
    }
    cout<<endl;

    cout<<"range for update & value\n";
    int ii,jj,val;
    cin>>ii>>jj>>val;

    memset(lazy,0,sizeof(lazy));
    rangeupdate(1,1,n,ii,jj,val);

    for(int i=1;i<=n*4;i++)
    {
        cout<<sum[i].tree<<" ";
    }
    cout<<endl;

    while(1)
    {
        cout<<"enter querey range\n";
        int s,e;
        cin>>s>>e;

        me re=query(1,1,n,s,e);
        cout<<re.tree<<"\n";
    }
    return 0;
}
