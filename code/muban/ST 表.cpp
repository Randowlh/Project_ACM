#define lg2(x) (31 - __builtin_clz(x)) // if (__builtin_clz(x)) is can't be used, you can implement it in a table

void build_st_table() {
	int *f, *g = *st, i, j, k = cnt;
	for (j = 0; 1 << j + 1 <= cnt; ++j) {
		f = g; g = st[j + 1]; k -= 1 << j;
		for (i = 0; i < k; ++i)
			g[i] = min(f[i], f[i + (1 << j)]);
	}
}

inline int range(int L, int R){ // [L, R)
	int D = R - L, c = lg2(D);
	return min(st[c][L], st[c][R - (1 << c)]);
}