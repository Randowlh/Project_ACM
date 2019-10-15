#define lg2(x) (31 - __builtin_clz(x))

int cnt, id[N], st[21][M], *ord = *st;

inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}

void dfs(int x, int px = 0) {
	int i, y;
	ord[cnt] = x; id[x] = cnt++;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px)
			dep[y] = dep[x] + 1, dfs(y, x), ord[cnt++] = x;
}

void build_st_table() {
	int *f, *g = ord, i, j, k = cnt;
	for (j = 0; 1 << j + 1 <= cnt; ++j) {
		f = g; g = st[j + 1]; k -= 1 << j;
		for (i = 0; i < k; ++i)
			g[i] = dmin(f[i], f[i + (1 << j)]);
	}
}

inline int LCA(int x, int y) {
	int L = std::min(id[x], id[y]), R = (id[x] ^ id[y] ^ L) + 1, c = lg2(R - L);
	return dmin(st[c][L], st[c][R - (1 << c)]);
}