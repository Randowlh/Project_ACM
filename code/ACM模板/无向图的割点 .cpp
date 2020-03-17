void dfs(int x, int px){
	int i, y, M = 0;
	id[x] = low[x] = ++cnt;
	for(i = first[x]; i; i = next[i])
		if(!id[y = to[i]]){
			++M;
			dfs(y, x);
			down(low[x], low[y]);
			if(id[x] <= low[y]) // vertex x is a cut-point
		}else
			low[x] = min(low[x], id[y]);
	if(px == -1 && M > 1) // vertex x is a cut-point
}