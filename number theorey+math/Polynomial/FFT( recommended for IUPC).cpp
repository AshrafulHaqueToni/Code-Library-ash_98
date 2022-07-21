typedef complex<double> CD;
typedef long long LL;
typedef long long ll;
typedef vector<LL> vi;
const double PI = acos(-1);
struct FFT
{
    int N;
    vector<int> perm;
    void precalculate() {
        perm.resize(N);
        perm[0] = 0;
        for(int k = 1; k < N; k <<= 1) {
            for(int i = 0; i < k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1+perm[i];
            }
        }
    }
    void fft(vector<CD> &v, bool invert = false) {
        if(v.size() != perm.size()) {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }
        for(int i = 0; i < N; i++) {
            if(i < perm[i]) swap(v[i], v[perm[i]]);
        }
        for(int len = 2; len <= N; len <<= 1) {
            double angle = 2*PI/len;
            if(invert) angle = -angle;
            CD factor = polar(1.0, angle);
            for(int i = 0; i < N; i += len) {
                CD w(1);
                for(int j = 0; j < len/2; j++) {
                    CD x = v[i+j], y = w*v[i+j+len/2];
                    v[i+j] = x+y;
                    v[i+j+len/2] = x-y;
                    w *= factor;
                }
            }
        }
        if(invert) {
            for(CD &x: v) x /= N;
        }
    }
    vi Multiply(const vi &a, const vi &b) {
        vector<CD> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while(n < a.size()+b.size()) n <<= 1;
        fa.resize(n);fb.resize(n);
        fft(fa);fft(fb);
        for(int i = 0; i < n; i++) fa[i] *= fb[i];
        fft(fa, true);
        vi ans(n);
        for(int i = 0; i < n; i++) ans[i] = round(fa[i].real());
        return ans;
    }
};
