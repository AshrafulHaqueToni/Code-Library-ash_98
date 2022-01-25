#define mx 1005
#define ll long long
 
int dp[mx][mx],ar[mx][mx];
int ST[mx][mx][10];
int n,m,ii,k;
int Jump_LOG[mx];

void pre()
{
    for(int i=2;i<=1000;i++)Jump_LOG[i]=Jump_LOG[i-1]+!(i&(i-1));
}

void Build_sparse_square(int N)
{
    for(int l=0;(1<<l)<=N;l++)
    {
        for(int i=1;i+(1<<l)<N;i++)
        {
            for(int j=1;j+(1<<l)<N;j++)
            {
                if(l==0)ST[i][j][l]=dp[i][j];
                else
                {
                    int val1=max(ST[i][j][l-1],ST[i+(1<<(l-1))][j][l-1]);
                    int val2=max(ST[i][j+(1<<(l-1))][l-1],ST[i+(1<<(l-1))][j+(1<<(l-1))][l-1]);
                    ST[i][j][l]=max(val1,val2);
                }
            }
        }
    }
}

int query(int i,int j,int l)
{
    int lg=Jump_LOG[l];
    int add=1<<lg;
    int re1=max(ST[i][j][lg],ST[i+l-add][j][lg]);
    int re2=max(ST[i][j+l-add][lg],ST[i+l-add][j+l-add][lg]);
    return max(re1,re2);

}
