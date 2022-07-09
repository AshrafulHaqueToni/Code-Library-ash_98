// Complexity : O(n log n)
// dp[i][j] = min(dp[i-1][k-1] + C[k][j]) [ k <= j ]
// To use D&Q, its sufficient to prove the following :
// Cost(L + 1 , j + 1) - Cost(L + 1, j) <= Cost(k + 1, j + 1) - Cost(k + 1, j) for any(L < k < j) For Max Query
// Cost(L + 1 , j + 1) - Cost(L + 1, j) >= Cost(k + 1, j + 1) - Cost(k + 1, j) for any(L < k < j) For Min Query
// tested : https://codeforces.com/contest/1527/problem/E
ll dp[2][mx];
void divide_conquer(int part,int l,int r,int optl,int optr){
    if(l>r)return;
    int mid=(l+r)/2;
    int optnow=-1;
    dp[part&1][mid]=1e18;
    for(int i=optl;i<=min(optr,mid);i++){
        ll tmp=dp[(part&1)^1][i-1]+cost(i,mid);
        if(tmp<=dp[part&1][mid]){
            dp[part&1][mid]=tmp;
            optnow=i;
        }
    }
    divide_conquer(part,l,mid-1,optl,optnow);
    divide_conquer(part,mid+1,r,optnow,optr);
}
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    for(int i=1;i<=n;i++)dp[1][i]=cost(1,i);
    for(int i=2;i<=k;i++)divide_conquer(i,1,n,1,n);
    printf("%lld\n",dp[k&1][n]);
}
