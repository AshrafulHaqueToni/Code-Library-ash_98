namespace Segment_Tree
{
	const int N=200005;
	int Tree[N*4];
	int Lazy[mx*4];
	int ar[N];

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
		Relax(node,be,en);
		if(be> pos || en<pos)return;
		if(be==en)
		{
			Tree[node]+=val;
			return;
		}
		int mid=(be+en)/2;
		update(node*2,be,mid,pos,val);
		update(node*2+1,mid+1,en,pos,val);
		Tree[node]=max(Tree[node*2],Tree[node*2+1]);
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
		Relax(node,be,en);
		if(be>j || en<i)return 0;
		if(be>=i && en<=j)return Tree[node];
		int mid=(be+en)/2;
		return max(query(node*2,be,mid,i,j),query(node*2+1,mid+1,en,i,j));
	}

	void dbg_test(int node,int be,int en)
	{
		if(be==en)return;
		int mid=(be+en)/2;
		dbg_test(node*2,be,mid);
		dbg_test(node*2+1,mid+1,en);
	}
}
