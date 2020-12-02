#define mx 505
#define MAX_logN 9
#define ll long long
#define mod 1000000007

int ar[mx][mx];
int n,m,ii,k;
int ST[mx][mx][MAX_logN][MAX_logN];  

void Build_2D_Sparse()
{

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ST[i][j][0][0]=ar[i][j];
		}
	
		for(int l=1;(1<<l)<=n;l++)
		{
			int pre=1<<(l-1);

			for(int j=1;j+pre<=n;j++)
			{
				ST[i][j][0][l]=min(ST[i][j][0][l-1],ST[i][j+pre][0][l-1]);
			}
		}
	}

	for(int l=1;(1<<l)<=n;l++)
	{
		int pre=1<<(l-1);

		for(int i=1;i+pre<=n;i++)
		{
			for(int k=0;(1<<k)<=n;k++)
			{
				for(int j=1;j<=n;j++)
				{
					ST[i][j][l][k]=min(ST[i][j][l-1][k],ST[i+pre][j][l-1][k]);
				}
			}
		}
	}
}

int query(int i,int j,int p,int q)  /// two point
{
	int boro_jum1=log2(p-i+1);
	int boro_jum2=log2(q-j+1);
	int pre1=1<<boro_jum1;
	int pre2=1<<boro_jum2;

	int re1=min(ST[i][j][boro_jum1][boro_jum2],ST[i][q-pre2+1][boro_jum1][boro_jum2]);
	int re2=min(ST[p-pre1+1][j][boro_jum1][boro_jum2],ST[p-pre1+1][q-pre2+1][boro_jum1][boro_jum2]);

	return min(re1,re2);
}
