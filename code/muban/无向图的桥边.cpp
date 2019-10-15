void dfs(int x, int px){
	int i, y;
	id[x] = low[x] = ++cnt;
	for(i = first[x]; i; i = next[i])
		if(!id[y = to[i]]){
			dfs(y, x);
			down(low[x], low[y]);
			if(id[x] < low[y]) // edge i is a bridge
		}else
			low[x] = min(low[x], id[y]);
}