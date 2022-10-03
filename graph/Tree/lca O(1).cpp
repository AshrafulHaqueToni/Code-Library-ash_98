template <class T>
struct RMQ{ /// 0 base index
    vector<vector<T>>rmq;
    T kInf = numeric_limits<T>::max();
    void build(const vector<T>&v){
        int n=v.size(),l=1,d=1;
        while(l<n)l*=2,d++;
        rmq.assign(d,v);
        for(int i=0;i<d-1;i++)
            for(int j=0;j<n;j++)
                rmq[i+1][j]=min(rmq[i][j],rmq[i][min(n-1,j+(1<<i))]);       
    }
    T query(int a,int b){
        if(b<=a)return kInf;
        int d=31-__builtin_clz(b-a);//log(b-a)
        return min(rmq[d][a],rmq[d][b-(1<<d)]);
    }
};

struct LCA{//0 base
    vector<int>st,en,d;
    vector<vector<int>>g;
    vector<pair<int,int>>linear;
    RMQ<pair<int,int>>rmq;
    int timer=0;
    LCA(){}
    LCA(int n):st(n,-1),en(n,-1),d(n),g(n),linear(2*n){}
    void dfs(int u,int l){
        linear[timer]={l,u};
        st[u]=timer++;
        d[u]=l;
        for(int v:g[u])
        if(st[v]==-1){
            dfs(v,l+1);
            linear[timer++]={l,u};
        }
        en[u]=timer;
    }
    void addedge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build(int root){
        dfs(root,0);
        rmq.build(linear);
    }
    int query(int a,int b){
        a=st[a],b=st[b];
        return rmq.query(min(a,b),max(a,b)+1).second;
    }
    int dist(int a,int b){
        return d[a]+d[b]-2*d[query(a,b)];
    }
};
