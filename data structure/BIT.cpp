struct BIT
{
    int Tree[N+5];
    void init()
    {
    	memset(Tree,0,sizeof(Tree));
    }
    int query(int idx)
    {
        int re=0;
        while(idx)
        {
            re+=Tree[idx];
            idx-=idx&-idx;
        }
        return re;
    }
    void update(int idx,int val)
    {
        while(idx<=N)
        {
            Tree[idx]+=val;
            idx+=idx&-idx;
        }
    }
    int Rquery(int l,int r)
    {
        return query(r)-query(l-1);
    }
    void Rupdate(int l,int r,int val)
    {
        update(l,val);
        update(r+1,val*-1);
    }
};
