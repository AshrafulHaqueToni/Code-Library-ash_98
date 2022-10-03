#define LL long long
#define VI vector<LL>
const int M = 998244353;
/*
7340033, 5, 4404020, 1<<20
13631489, 11799463,6244495, 1<<20
23068673, 177147,17187657, 1<<21
463470593, 428228038, 182429, 1<<21
415236097, 73362476, 247718523, 1<<22
918552577, 86995699, 324602258, 1<<22
998244353, 15311432, 469870224, 1<<23
167772161, 243, 114609789, 1<<25
469762049, 2187, 410692747, 1<<26
*/

LL power(LL a, LL p, LL mod) {
    if (p==0)   return 1;
    LL ans = power(a, p/2, mod);
    ans = (ans * ans)%mod;
    if (p%2)    ans = (ans * a)%mod;
    return ans;
}

struct NTT {
    int N;
    vector<int> perm;
    int mod, root, inv, pw;
    NTT(int mod, int root, int inv, int pw) :
        mod(mod), root(root), inv(inv), pw(pw) {}
    void precalculate() {
        perm.resize(N);
        perm[0] = 0;
        for (int k=1; k<N; k<<=1) {
            for (int i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }
    }
    void fft(VI &v, bool invert = false) {
        if (v.size() != perm.size()) {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }
 
        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);
 
        for (int len = 2; len <= N; len <<= 1) {
            LL factor = invert ? inv : root;
            for (int i = len; i < pw; i <<= 1)
                factor = (factor * factor) % mod;
 
            for (int i=0; i<N; i+=len) {
                LL w = 1;
                for (int j=0; j<len/2; j++) {
                    LL x = v[i+j], y = (w * v[i+j+len/2])%mod;
                    v[i+j] = (x+y)%mod;
                    v[i+j+len/2] = (x-y+mod)%mod;
                    w = (w * factor)%mod;
                }
            }
        }
        if (invert) {
            LL n1 = power(N, mod-2, mod);
            for (LL &x : v) x=(x*n1)%mod;
        }
    }
 
    VI multiply(VI a, VI b) {
        while (a.back() == 0 && a.size())   a.pop_back();
        while (b.back() == 0 && b.size())   b.pop_back();
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        a.resize(n);
        b.resize(n);
        fft(a);
        fft(b);
        for (int i=0; i<n; i++) a[i] = (a[i] * b[i])%mod;
        fft(a, true);
        return a;
    }
    VI bigMod(VI &base, int p) {
        if(p==0)return {1};
        VI ans = bigMod(base, p/2);
        ans = multiply(ans, ans);
        if (p%2)ans = multiply(ans, base);
        return ans;
    }
};
NTT ntt(998244353, 15311432, 469870224, 1<<23);
