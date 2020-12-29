// Created by ash_98

///https://toph.co/p/miguel-and-his-dream-house

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll unsigned long long
#define mod 1000000007

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

char ch[mx];
int n,m,ii,k;
ll Rand[2000005];

namespace Segment_Tree
{
	const int N=100005;
	ll Tree[N*4];
	int Lazy[N*4];
	int Present[N*4];
	ll ar[N];

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
		//Lazy[node]=0;
        if(be==en)
        {
        	Tree[node]=ar[be];
        	Present[node]=1;
        	return;
        }
        int mid=(be+en)/2;
        init(node*2,be,mid);
        init(node*2+1,mid+1,en);
        Tree[node]=Tree[node*2]^Tree[node*2+1];
        Present[node]=Present[node*2]+Present[node*2+1];
	}

	void update(int node,int be,int en,int pos,int val,int ace)
	{
		//Relax(node,be,en);
		if(be> pos || en<pos)return;
		if(be==en)
		{
			Tree[node]=val;
			Present[node]=ace;
			return;
		}
		int mid=(be+en)/2;
		update(node*2,be,mid,pos,val,ace);
		update(node*2+1,mid+1,en,pos,val,ace);
		Tree[node]=Tree[node*2]^Tree[node*2+1];
        Present[node]=Present[node*2]+Present[node*2+1];
	}

	void Rupdate(int node,int be,int en,int i,int j,int val)
	{
		//Relax(node,be,en);
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

	ll query(int node,int be,int en,int i,int j)
	{
		//Relax(node,be,en);
		if(be>j || en<i)return 0;
		if(be>=i && en<=j)return Tree[node];
		int mid=(be+en)/2;
		return query(node*2,be,mid,i,j)^query(node*2+1,mid+1,en,i,j);
	}

	int id_query(int node,int be,int en,int pos)
	{
		if(be==en)return be;
		int mid=(be+en)/2;
		if(Present[node*2]>=pos)
		{
			return id_query(node*2,be,mid,pos);
		}
		else return id_query(node*2+1,mid+1,en,pos-Present[node*2]);
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
	int q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=2000000;i++)Rand[i]=rng();
	for(int i=1;i<=n;i++)scanf("%llu",&ar[i]),ar[i]=Rand[ar[i]];
	init(1,1,n);

   // for(int i=1;i<=15;i++)printf("%llu ",Rand[i] );
  //  printf("\n");

    for(int i=1;i<=q;i++)
    {
    	int ti,x,y;
    	scanf("%d%d",&ti,&x);

    	if(ti==1)
    	{
    		scanf("%d",&y);
    		int id=id_query(1,1,n,x);
    		update(1,1,n,id,Rand[y],1);
    	}
    	else if(ti==2)
    	{
    		int id=id_query(1,1,n,x);
    		update(1,1,n,id,0,0);
    	}
    	else
    	{
    		scanf("%d",&y);
    		int id1=id_query(1,1,n,x);
    		int id2=id_query(1,1,n,y);
    		if(id2<id1)swap(id1,id2);
    		ll val=query(1,1,n,id1,id2);
    		if(val==0)printf("Happy\n");
    		else printf("Unhappy\n");
    	}

    }
}

int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}
