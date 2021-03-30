for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j || dis[i][j]>0)continue;
			dis[i][j]=1e18;
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
