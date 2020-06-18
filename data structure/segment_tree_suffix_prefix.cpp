#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define INF 200000000000
typedef  long long ll;

typedef struct me
{
    ll max_pref,max_suf,ans,sum,r_sum;
} Node;

Node tree[4*mx];

ll ar[mx];

me Merge(me p1,me p2)
{
    me re;
    re.r_sum=p1.r_sum+p2.r_sum;
    re.sum=p1.sum+p2.sum;
    re.max_pref=max(p1.max_pref,p1.sum+p2.max_pref);
    re.max_suf=max(p2.max_suf,p2.sum+p1.max_suf);
    re.ans=max(max(p1.ans,p2.ans),p1.max_suf+p2.max_pref);
    return re;
}


void built(int node,int be,int en)
{
    if(be==en)
    {
        tree[node].sum=tree[node].max_pref=tree[node].max_suf=tree[node].ans=tree[node].r_sum=ar[be];
        return;
    }
    int mid=(be+en)/2;
    built(node*2,be,mid);
    built(node*2+1,mid+1,en);

    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}

void update(int node,int be,int en,int i,ll val)
{
    if(be>i||en<i||be>en)
        return;

    if(be==en)
    {
        tree[node].sum=tree[node].max_pref=tree[node].max_suf=tree[node].ans=tree[node].r_sum=val;
        return;
    }
    int mid=(be+en)/2;
    update(node*2,be,mid,i,val);
    update(node*2+1,mid+1,en,i,val);

    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}

Node query(int node,int be,int en,int i,int j)
{
    Node result;
    result.sum = result.max_pref =result.max_suf =result.ans =-INF;
    result.r_sum=0;

    if(j<be || i>en)
        return result;

    if(i<=be && j>=en)
        return tree[node];

    int mid=(be+en)/2;

    if(i>mid)
        return query(node*2+1,mid+1,en,i,j);
    if(j<=mid)
        return query(node*2,be,mid,i,j);

    Node left=query(node*2,be,mid,i,j);
    Node right=query(node*2+1,mid+1,en,i,j);

    return Merge(left,right);

}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,q;
        scanf("%lld%lld",&n,&q);

        for(int i=1; i<=n; i++)
            scanf("%lld",&ar[i]);

        built(1,1,n);
//    for(int i=1;i<=2*n;i++)
//    {
//        cout<<tree[i].sum<<" "<<tree[i].max_pref<<" "<<tree[i].max_suf<<endl;
//    }

        for(int i=1; i<=q; i++)
        {
            char cc;
            scanf(" %c",&cc);
            ll x,y;
            scanf("%lld%lld",&x,&y);
            ll re=0;
            if(cc=='Q')
            {
                re+=query(1,1,n,x,y).r_sum;
                //cout<<re<<endl;
                if(x>1)
                    re+=max(query(1,1,n,1,x-1).max_suf,0LL);
                if(y<n)
                    re+=max(query(1,1,n,y+1,n).max_pref,0LL);
                printf("%lld\n",re);
            }
            else
                update(1,1,n,x,y);
        }
    }
    return 0;
}
