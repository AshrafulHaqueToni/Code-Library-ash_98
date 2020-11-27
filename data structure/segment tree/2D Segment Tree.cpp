namespace Segment_Tree
{
	const int N=400005;
	int Tree[N*4][2];
	int Lazy[N*4][2];

	void Relax(int node,int be,int en,int f)
	{
		if(!Lazy[node][f])return;

		Tree[node][f]+=Lazy[node][f];
		if(be!=en)
		{
			Lazy[node*2][f]+=Lazy[node][f];
			Lazy[node*2+1][f]+=Lazy[node][f];
		}
		Lazy[node][f]=0;
	}
	
	void init(int node,int be,int en,int f)
	{
		Lazy[node][f]=0;
		if(be==en)
		{
			Tree[node][f]=ar[be];
			return;
		}
		int mid=(be+en)/2;
		init(node*2,be,mid,f);
		init(node*2+1,mid+1,en,f);
		Tree[node][f]=Tree[node*2][f]+Tree[node*2+1][f];
	}

	void update(int node,int be,int en,int pos,int val,int f)
	{
		Relax(node,be,en,f);
		if(be> pos || en<pos)return;
		if(be==en)
		{
			Tree[node][f]+=val;
			return;
		}
		int mid=(be+en)/2;
		update(node*2,be,mid,pos,val,f);
		update(node*2+1,mid+1,en,pos,val,f);
		Tree[node][f]=max(Tree[node*2][f],Tree[node*2+1][f]);
	}

	void Rupdate(int node,int be,int en,int i,int j,int val,int f)
	{
		Relax(node,be,en,f);
		if(be>j || en<i)return ;
		if(be>=i && en<=j)
		{
			Lazy[node][f]+=val;
			Relax(node,be,en,f);
			return;
		}
		int mid=(be+en)/2;
		Rupdate(node*2,be,mid,i,j,val,f);
		Rupdate(node*2+1,mid+1,en,i,j,val,f);
		Tree[node][f]=max(Tree[node*2][f],Tree[node*2+1][f]);
	}

	int query(int node,int be,int en,int i,int j,int f)
	{
		Relax(node,be,en,f);
		if(be>j || en<i)return 0;
		if(be>=i && en<=j)return Tree[node][f];
		int mid=(be+en)/2;
		return max(query(node*2,be,mid,i,j,f),query(node*2+1,mid+1,en,i,j,f));
	}

	void dbg_test(int node,int be,int en,int f)
	{
		if(be==en)return;
		int mid=(be+en)/2;
		dbg_test(node*2,be,mid,f);
		dbg_test(node*2+1,mid+1,en,f);
	}
}
