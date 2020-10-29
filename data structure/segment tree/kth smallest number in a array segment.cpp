#include<bits/stdc++.h>
using namespace std;

#define mx 100005
vector<int>seg[mx*4];

void built(int node,int be,int en,pair<int,int>* p)
{
    if(be==en)
    {
        seg[node].push_back(p[be].second);
        return;
    }

    int mid=(be+en)/2;

    built(node*2+1,be,mid,p);
    built(node*2+2,mid+1,en,p);

    merge(seg[node*2+1].begin(),seg[node*2+1].end(),
          seg[node*2+2].begin(),seg[node*2+2].end(),
          back_inserter(seg[node]));

}

int query(int node,int be,int en,int l,int r,int k)
{
    if(be==en)return seg[node][0];

    int pos= upper_bound(seg[node*2+1].begin(),seg[node*2+1].end(),r)
    -lower_bound(seg[node*2+1].begin(),seg[node*2+1].end(),l);

    int mid=(be+en)/2;

    if(pos>=k)
    {
        return query(node*2+1,be,mid,l,r,k);
    }
    else return query(node*2+2,mid+1,en,l,r,k-pos);
}



int main()
{
    int n;
    scanf("%d",&n);

    int a[n];

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    pair<int,int>p[n];

    for(int i=0;i<n;i++)
    {
        p[i]={a[i],i};

    }
    sort(p,p+n);

    built(0,0,n-1,p);

    while(1)
    {
    int l,r,kth;
    scanf("%d%d%d",&l,&r,&kth);
    l--,r--;

    int pos=query(0,0,n-1,l,r,kth);

     printf("%d\n",a[pos]);

    }


    return 0;

}
