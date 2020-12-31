int Findparent(int x)
{
    return (x==parent[x])?x:(parent[x]=Findparent(parent[x]));
}

void Union(int x,int y)
{
    parent[Findparent(x)]=parent[Findparent(y)];
}

void initialize()
{
    for(int i=0;i<=n;i++)parent[i]=i;
}
