int p[N], dep[N], size[N];
int cnt = 0, id[N], prf[N], top[N];

void dfs_wt(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x, dep[y] = dep[x] + 1;
			dfs_wt(y), size[x] += size[y];
			size[y] > size[z] ? z = y : 0;
		}
}

void dfs_hld(int x, int r) {
	int i, y; id[x] = ++cnt, top[x] = r;
	if (!prf[x]) return;
	dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
}

int solve(int u, int v) {
	int x = top[u], y = top[v];
	for (; x != y; u = p[x], x = top[u]) {
		if (dep[x] < dep[y]) {swap(u, v); swap(x, y);}
		// do something on [x, u]
	}
	if (dep[u] > dep[v]) {swap(u, v); swap(lx, ly);}
	// do something on [u, v]
	// return something
}