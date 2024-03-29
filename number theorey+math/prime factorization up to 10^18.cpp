#include<bits/stdc++.h>
#include <bits/stdtr1c++.h>
using namespace std;
 

#define ll long long

namespace ftor{
    /// Note use only for factorization
    #define MLIM 1000 /// Used in Brent Pollard Rho
    #define PLIM 10  /// Miller-Rabin Test depth
    #define MAX 10000 /// Small primes generated in this range
    #define SQR 101 /// Square root of MAX

    int p, P[MAX];
    bitset <MAX> prime;
    tr1::unordered_map <long long, long long> mp;

    inline void Sieve(){
        int i, j, d;
        prime.reset();
        prime[2] = true;
        for (i = 3; i < MAX; i++, i++) prime[i] = true;

        for (i = 3; i < SQR;){
            d = i << 1;
            for (j = (i * i); j < MAX; j += d) prime[j] = false;

            do{
                i++;
            } while (!prime[++i]);
        }

        p = 0;
        for (i = 0; i < MAX; i++){
            if (prime[i]) P[p++] = i;
        }
    }

    inline long long mul(long long a, long long b, long long m, long double fuck) {
       long long c = (long long)(fuck * a * b);
       a *= b;
       a -= c * m;
       if (a >= m) a -= m;
       if (a < 0) a += m;
       return a;
    }

    inline long long expo(long long x, long long n, long long m, long double fuck){
        long long res = 1;

        while (n){
            if (n & 1) res = mul(res, x, m, fuck);
            x = mul(x, x, m, fuck);
            n >>= 1;
        }

        return res;
    }

    inline bool miller_rabin(long long p, long double fuck, int lim){
        long long a, s, m, x, y;
        s = p - 1, y = p - 1;
        while (!(s & 1)) s >>= 1;

        while (lim--){
            x = s;
            a = (((rand() << 15) ^ rand()) % y) + 1;
            m = expo(a, x, p, fuck);

            while ((x != y) && (m != 1) && (m != y)){
                m = mul(m, m, p, fuck);
                x <<= 1;
            }
            if ((m != y) && !(x & 1)) return false;
        }

        return true;
    }

    inline unsigned long long gcd(unsigned long long u, unsigned long long v){
        if (!u) return v;
        if (!v) return u;
        if (u == 1 || v == 1) return 1;

        int shift = __builtin_ctzll(u | v);
        u >>= __builtin_ctzll(u);
        do{
            v >>= __builtin_ctzll(v);
            if (u > v)
                v ^= u ^= v ^= u;
            v = v - u;
        } while (v);

        return u << shift;
    }

    inline long long brent_pollard_rho(long long n){
        long double fuck = (long double)1 / n;
        if (miller_rabin(n, fuck, PLIM)) return n;

        const long long m = MLIM;
        long long i, k, a, x, y, ys, r, q, g;
        g = mp[n];
        if (g) return g;

        do{
            a = ((rand() << 15) ^ rand()) % n;
        }
        while (!a || a == (n - 2));

        r = 1, q = 1;
        y = ((rand() << 15) ^ rand()) % n;

        do{
            x = y;
            for (i = 0; i < r; i++){
                y = mul(y, y, n, fuck);
                y += a;
                if (y < a) y += (ULLONG_MAX - n) + 1;
                y %= n;
            }

            k = 0;
            do{
                for (i = 0; (i < m) && (i < (r - k)); i++){
                    ys = y;
                    y = mul(y, y, n, fuck) + a;
                    if (y < a) y += (ULLONG_MAX - n) + 1;
                    y %= n;
                    q = mul(q, abs(x - y), n, fuck);
                }

                g = gcd(q, n);
                k += m;

            }
            while ((k < r) && (g == 1));

            r <<= 1;
        }
        while (g == 1);

        if (g == n){
            do{
                ys = mul(ys, ys, n, fuck) + a;
                if (ys < a) ys += (ULLONG_MAX - n) + 1;
                ys %= n;
                g = gcd(abs(x - ys), n);
            }
            while (g == 1);
        }

        return (mp[n] = g);
    }

    vector <long long> factorize(long long n){
        int i, d, len;
        long long m, k, x;
        vector <long long> v, factors;

        for (i = 0; i < p; i++){
            while (!(n % P[i])){
                n /= P[i];
                v.push_back(P[i]);
            }
        }
        if (n == 1) return v;

        x = brent_pollard_rho(n);
        factors.push_back(x);
        factors.push_back(n / x);
        len = factors.size();

        do{
            m = factors[len - 1];
            factors.pop_back(), len--;

            if (m > 1){
                if (miller_rabin(m, (long double)1 / m, PLIM)){
                    v.push_back(m);
                    for (i = 0; i < len; i++){
                        k = factors[i];
                        while (!(k % m)){
                            k /= m;
                            v.push_back(m);
                        }
                        factors[i] = k;
                    }
                }
                else{
                    x = brent_pollard_rho(m);
                    factors.push_back(x);
                    factors.push_back(m / x);
                    len += 2;
                }
            }
        }
        while (len);

        sort(v.begin(), v.end());
        // v.resize(distance(v.begin(),unique(v.begin(), v.end())));
        return v;
    }

    void init(){
        Sieve();
        mp.clear();
        srand(time(0));
    }
}

using namespace ftor;
