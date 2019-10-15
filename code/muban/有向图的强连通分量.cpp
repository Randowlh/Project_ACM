void dfs(int x) {
	int i, y;
	id[x] = low[x] = ++cnt; instack[x] = 1; sta[stc++] = x;
	for(i = first[x]; i; i = next[i])
		if (!id[y = to[i]])
			dfs(y), down(low[x], low[y]);
		else if (instack[y])
			down(low[x], id[y]);
	if (id[x] == low[x])
		for (y = 0; y != x; )
			y = sta[--stc], instack[y] = 0, top[y] = x;
}