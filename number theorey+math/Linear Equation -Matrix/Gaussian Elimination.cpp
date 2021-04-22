//Gaussian Elimination
//format : (a[0]*x[0]+a[1]*x[1] ... a[m-1]*x[m-1]) % k = a[m], where 0 <= ai < k
//number of solution : k^(number of free variable) = k^(n-rank)
ll A[105][105];
ll X[105];
int Rank;

ll gcdExtended(ll a, ll b, ll& x, ll& y){
    if(a==0) {x=0;y=1; return b;}
    ll x1,y1;
    ll gcd = gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return gcd;
}

ll modinverse(ll x,ll y) {ll a,b; gcdExtended(x,y,a,b); return a;}

//n equations (n rows), m variables (m+1 columns)
void Gauss(int n,int m,int k){
    int r,c;
    for(r=0,c=0;r<n && c<m;c++){
        for(int i=r+1;i<n;i++) if(abs(A[i][c])>abs(A[r][c])) swap(A[i],A[r]);
        if(!A[r][c]) continue;
        ll s = modinverse(A[r][c],k);
        for(int i=r+1;i<n;i++) if(A[i][c]){
            ll w = (s*A[i][c])%k;
            /* s bhag hobe r A[i][c] gun hobe*/
            for(int j=c;j<=m;j++){A[i][j]-=(A[r][j]*w)%k; A[i][j]%=k; if(A[i][j]<0) A[i][j]+=k;}
        }
        r++;
    }
    //Rank = r
    for(int i=r;i<n;i++) if(A[i][m]) return;  //No solution

    //Unique Solution for r variables
    for(int i=r-1;i>=0;i--){
        X[i]=A[i][m];
        for(int j=i+1;j<m;j++) {X[i]-=(A[i][j]*X[j])%k; X[i]%=k; if(X[i]<0) X[i]+=k;}

        ll inv=modinverse(A[i][i],k);
        X[i]=(X[i]*inv)%k; if(X[i]<0) X[i]+=k;
    }
}
