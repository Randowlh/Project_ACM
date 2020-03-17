void dfs(int x, int px) {
	int i, y, z;
	id[x] = low[x] = ++cnt; stack[top++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = to[i]]) {
			dfs(y, i), down(low[x], low[y]);
			if (id[x] <= low[y])
				for (link(++bcc_cnt + V, x), z = 0; z != y; )
					link(bcc_cnt + V, z = stack[--top]);
		} else if (i - 1 ^ px - 1 ^ 1)
			down(low[x], id[y]);
}