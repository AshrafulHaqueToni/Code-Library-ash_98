/// taken from https://codeforces.com/blog/entry/57496
/// https://atcoder.jp/contests/abc187/tasks/abc187_f
 
int ChromaticNumber(const vector<int> &g) {
    //g[i] is the binary string indicating neighbors of i
    if (n == 0) return 0;
 
    //randomly choose a large prime
    const int modulo = 1077563119;

    int all = 1 << n;

    vector<int> ind(all), s(all);
    
    //inclusion-exclusion precomputation
    for (int i = 0; i < all; i ++) s[i] = ((n - __builtin_popcount(i)) & 1 ? -1 : 1);
 
    //count the number of independent sets over all subsets of vertices
    ind[0] = 1;
    for (int i = 1; i < all; i ++) {
            int ctz = __builtin_ctz(i);
            //if X is the subset represented by the mask i, then ctz is a vertex of X
            //any independent set of X either does not contain ctz or it contains ctz 
            //ind[1 - (1<<ctz)] counts the first case, while ind[(i - (1 << ctz)) & ~g[ctz]] counts the second case
            //note that (i - (1 << ctz)) & ~g[ctz] denotes the vertices in X that are NOT neighbors of ctz
            ind[i] = ind[i - (1 << ctz)] + ind[(i - (1 << ctz)) & ~g[ctz]];
            if (ind[i] >= modulo) ind[i] -= modulo;
    }
 
    //to see why c(k) = \sum (-1)^{n - |i|} * ind(i)^k:
    //1. If the union of k independent sets is G (entire graph), then 1 is added to both sides
    //2. Otherwise, 0 is added to LHS, and all the -1s and 1s cancel on the RHS because there 
    //are an equal amount of odd-sized and even-sized subsets containing the union of the k independent sets
    
    //compute the chromatic number (= \sum (-1)^{n - |i|} * ind(i)^k)
    for (int k = 1; k < n; k ++) {
            long long sum = 0;
            for (int i = 0; i < all; i ++) {
                    long long cur = ((s[i] * (long long) ind[i]) % modulo);
                    s[i] = cur;
                    sum += cur;
            }
            if (sum % modulo != 0) return k;
    }
    return n;
}

void solve()
{
	scanf("%d%d",&n,&m);
	vector<int>g(n,(1<<(n+1))-1);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		g[x]-=(1<<y);
		g[y]-=(1<<x);
	}
	printf("%d\n",ChromaticNumber(g));
}
