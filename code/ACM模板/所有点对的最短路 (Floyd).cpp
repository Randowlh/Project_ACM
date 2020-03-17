int Floyd(){
	int i, j, k;
	for(k = 1; k <= V; k++)
		for(i = 1; i <= V; i++)
			for(j = 1; j <= V; j++)
				down(d[i][j], d[i][k] + d[k][j]);
	return 0;
}