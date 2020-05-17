struct node
{
    int x,y,idx;
    node(int x,int y,int idx)
    {
        this->x=x;
        this->y=y;
        this->idx=idx;
    }
    bool operator<(const node& other)const
    {
        if(x-y<other.x-other.y)return true;             ///condition
        else if(x-y==other.x-other.y)return idx<other.idx;
        return false;
    }
    ///sort korte chaile vector<node>v niye sort korte hobe.sort(v.begin(),v.end())
    /// push korte v.push_back(node(parameter....)
};
