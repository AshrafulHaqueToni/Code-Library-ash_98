#define mx 505
#define MAX_logN 9

int ar[mx][mx];
int n,m,ii,k;
int ST[mx][mx][MAX_logN][MAX_logN];  
int Jump_LOG[505];

void pre()
{
    for(int i=2;i<=500;i++)Jump_LOG[i]=Jump_LOG[i-1]+!(i&(i-1));
}

void Build_2D_Sparse()
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ST[i][j][0][0]=ar[i][j];
        }
    
        for(int l=1;(1<<l)<=m;l++)
        {
            int pre=1<<(l-1);

            for(int j=1;j+pre<=m;j++)
            {
                ST[i][j][0][l]=max(ST[i][j][0][l-1],ST[i][j+pre][0][l-1]);
            }
        }
    }

    for(int l=1;(1<<l)<=n;l++)
    {
        int pre=1<<(l-1);

        for(int i=1;i+pre<=n;i++)
        {
            for(int k=0;(1<<k)<=m;k++)
            {
                for(int j=1;j<=m;j++)
                {
                    ST[i][j][l][k]=max(ST[i][j][l-1][k],ST[i+pre][j][l-1][k]);
                }
            }
        }
    }
}

int query(int i,int j,int p,int q)  /// two point
{
    int boro_jum1=Jump_LOG[p-i+1];
    int boro_jum2=Jump_LOG[q-j+1];
    int pre1=1<<boro_jum1;
    int pre2=1<<boro_jum2;

    int re1=max(ST[i][j][boro_jum1][boro_jum2],ST[i][q-pre2+1][boro_jum1][boro_jum2]);
    int re2=max(ST[p-pre1+1][j][boro_jum1][boro_jum2],ST[p-pre1+1][q-pre2+1][boro_jum1][boro_jum2]);

    return max(re1,re2);
}
