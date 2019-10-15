void dfs(int x) {
	int i, y;
	for (i = 0; P[i][x]; ++i) P[i + 1][x] = P[i][P[i][x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, dfs(y);
}

int jump_until(int x, int d) {
	for (int i = LN - 1; i >= 0; --i)
		if (dep[x] - (1 << i) >= d)
			x = P[i][x];
	return x;
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	if (x = jump_until(x, dep[y]), x == y) return x;
	for (int i = LN - 1; i >= 0; --i)
		if (P[i][x] != P[i][y])
			x = P[i][x], y = P[i][y];
	return p[x];
}