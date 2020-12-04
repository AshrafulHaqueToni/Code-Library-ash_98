	// Compressing Coordinates . its a alternative of map
	sort(br+1,br+n+1);
	k = unique(br+1,br+n+1)-br-1;
	for(int i=1;i<=n;i++) ar[i]=lower_bound(br+1,br+k+1,ar[i])-br;
