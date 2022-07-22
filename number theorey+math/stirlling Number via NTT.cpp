NTT ntt(998244353, 15311432, 469870224, 1<<23);


VI v[MAX];
//Stirling1 (n,k) = co-eff of x^k in x*(x+1)*(x+2)*....(x+n-1)
int Stirling1(int n, int r) {
    int nn = 1;
    while(nn < n) nn <<= 1;

    for(int i = 0; i < n; ++i) {v[i].push_back(i); v[i].push_back(1);}
    for(int i = n; i < nn; ++i) v[i].push_back(1);

    for(int j = nn; j > 1; j >>= 1) {
        int hn = j >> 1;
        for(int i = 0; i < hn; ++i) v[i]=ntt.multiply(v[i], v[i + hn]);
    }
    return v[0][r];
}

#define mod 100000007
//Stirling2 (n,k) = co-eff of x^k in product of polynomials A & B
//where A(i) = (-1)^i / i!  and B(i) = i^n / i!
int Stirling2(int n, int r) {
    vector<ll>a,b,res;
    a.resize(n+1); b.resize(n+1);
    for(int i = 0; i <= n; i++){
        a[i] = invfct[i];
        if(i % 2 == 1) a[i] = mod - a[i];
    }

    for(int i = 0; i <= n; i++){
        b[i] = power(i, n, mod);
        b[i] = (b[i] * invfct[i]) % mod;
    }

    res=ntt.multiply(a,b);
    return res[r];
}
