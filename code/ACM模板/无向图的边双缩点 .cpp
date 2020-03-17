void dfs(int x, int px = 0) {
	int i, y;
	id[x] = low[x] = ++cnt; stack[stc++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = to[i]]) {
			dfs(y, i), down(low[x], low[y]);
			if (id[x] < low[y]) bridge[ad(i)] = bridge[i] = true;
		} else if (px - 1 ^ i - 1 ^ 1)
			down(low[x], id[y]);
	if (id[x] == low[x])
		for (y = 0; y != x; )
			y = stack[--stc], top[y] = x;
}