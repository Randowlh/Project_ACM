void dfs_len(int x) {
	int i, y, &z = prf[x];
	for (i = 0; i < LN && P[i][x]; ++i) P[i + 1][x] = P[i][P[i][x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x; dep[y] = dep[x] + 1;
			dfs_len(y);
			up(f[x], f[y] + 1);
			f[y] > f[z] ? z = y : 0;
		}
}

void dfs_lsd(int x, int r, int l = 1) { // long-short decomposition
	int i, y;
	id[x] = ++cnt; top[x] = r;
	if (!prf[x]) {len[x] = l; return;}
	dfs_lsd(prf[x], r, l + 1); len[x] = len[prf[x]];
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]])
			dfs_lsd(y, y);
}

int ancestor(int x, int k) {
	if (dep[x] < k) return 0;
	if (!k) return x;
	int i = lg2(k); x = P[i][x]; k ^= 1 << i;
	if (!k) return x;
	i = dep[x] - dep[top[x]] - k;
	return near[top[x]][i];
}

void init() {
	int i, j, x, *pt;
	*f = *dep = -1; dfs_len(1); dfs_lsd(1, 1);
	for (i = 1; i < N; ++i)
		if (top[i] == i) {
			near[i] = (new int[len[i] * 2 + 1]) + len[i]; pt = near[i]; *pt = i;
			for (j = 1, x = p[i]; j <= len[i] && x; ++j, x = p[x]) pt[-j] = x;
			for (j = 1, x = prf[i]; j <= len[i] && x; ++j, x = prf[x]) pt[j] = x;
		}
}