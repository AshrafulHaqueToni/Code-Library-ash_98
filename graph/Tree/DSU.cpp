int Size[mx];

int Findparent(int x)
{
    return (x==parent[x])?x:(parent[x]=Findparent(parent[x]));
}

void Union(int x,int y)
{
    int px=Findparent(x);
    int py=Findparent(y);
    if(px==py)return;
    if(Size[px]>Size[py])
    {
        Size[px]+=Size[py];
        parent[py]=px;
        parent[x]=parent[y]=px;
    }
    else
    {
        Size[py]+=Size[px];
        parent[px]=py;
        parent[x]=parent[y]=py;
    }
}

void initialize()
{
    for(int i=0;i<=n;i++)parent[i]=i,Size[i]=1;
}
