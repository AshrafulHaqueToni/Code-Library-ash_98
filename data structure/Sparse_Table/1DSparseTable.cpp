///it will be work for range min,max,or,and with no update

int ar[mx];
int n,m,ii,k;
int ST[mx][MAX_logN];
int Jump_LOG[mx];

void Build_Sparse()
{
	for(int i=1;i<=n;i++)ST[i][0]=ar[i];

	for(int i=2;i<=n;i++)Jump_LOG[i]=Jump_LOG[i-1]+!(i&(i-1));

	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;(i+(1<<j)-1)<=n;i++)
		{
           ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int i,int j)
{
	int boro_lav=Jump_LOG[j-i+1];
	return min(ST[i][boro_lav],ST[j-(1<<boro_lav)+1][boro_lav]);
}
