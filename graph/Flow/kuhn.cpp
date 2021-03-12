/// for weight see lightoj 1150 solution

#define mx 10005
#define ll long long
int n,m,ii,k;
struct BPM
{
	bool Done[mx];
    vector<int>g[mx];
    int macth[mx];

    void addEdge(int u,int v)
    {
        g[u].push_back(v);
    }

    void init()
    {
    	for(int i=0;i<mx;i++)g[i].clear();
    }

    bool Tem_Matching(int u)
    {
        for(int i=0;i<(int)g[u].size();i++)
        {
        	int v=g[u][i];
            if(Done[v]) continue;
            Done[v] = true;
            if(macth[v]==-1 || Tem_Matching(macth[v]))
            {
                macth[v] = u;
                return true;
            }
        }
        return false;
    }
    int Max_Matching(int num)
    {
	// Be Careful with this section. when passin num.
        memset(macth,-1,sizeof(macth));
        int re = 0;
        for(int i=1;i<=num;i++)
        {
            memset(Done,false,sizeof(Done));
            if(Tem_Matching(i)) re++;
            
        }
        return re;
    }
 
 
};

BPM bp;
