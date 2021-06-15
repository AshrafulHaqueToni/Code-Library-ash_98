#define mx 40005
#define INF (1<<28)

struct Hopcroft_Karp
{
	vector< int > g[mx];
	int n, m, Matching[mx], Distance[mx]; /// m na nileo hobe
	// n: number of nodes on left side, nodes are numbered 1 to n
	// m: number of nodes on right side, nodes are numbered n+1 to n+m
	// G = 0[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

	void init(int num)
	{
        for(int i=0;i<=num;i++)Matching[i]=0,Distance[i]=0,g[i].clear();
	}
    
    void addEdge(int u,int v)
    {
    	g[u].push_back(v);
    }

	bool bfs() {
	    int i, u, v, len;
	    queue< int > q;
	    for(i=1; i<=n; i++) {
	        if(Matching[i]==0) {
	            Distance[i] = 0;
	            q.push(i);
	        }
	        else Distance[i] = INF;
	    }
	    Distance[0] = INF;
	    while(!q.empty()) {
	        u = q.front(); q.pop();
	        if(u!=0) {	           
	            for(int v:g[u]) {
	             	    if(Distance[Matching[v]]==INF) {
	                    Distance[Matching[v]] = Distance[u] + 1;
	                    q.push(Matching[v]);
	                }
	            }
	        }
	    }
	    return (Distance[0]!=INF);
	}

	bool dfs(int u) {
	    int i, v, len;
	    if(u!=0) {
	        for(int v:g[u]) {
	            if(Distance[Matching[v]]==Distance[u]+1) {
	                if(dfs(Matching[v])) {
	                    Matching[v] = u;
	                    Matching[u] = v;
	                    return true;
	                }
	            }
	        }
	        Distance[u] = INF;
	        return false;
	    }
	    return true;
	}

	int hopcroft_karp() {
	    int Matchinging = 0, i;
	    while(bfs())
	        for(i=1; i<=n; i++)
	            if(Matching[i]==0 && dfs(i))
	                Matchinging++;
	    return Matchinging;
	}
};

Hopcroft_Karp hk;
