namespace Centroid {
	int V, Gm, G, size[N];

	void init(int _V) {V = _V; Gm = INT_MAX;}

	int get(int x, int px = 0) {
		int i, y, Max = 0; size[x] = 1;
		for (i = first[x]; i; i = next[i])
			if ((y = to[i]) != px && !fy[y]) {
				get(y, x); up(Max, size[y]);
				size[x] += size[y];
			}
		up(Max, V - size[x]);
		return Max <= Gm ? (Gm = Max, G = x) : G;
	}
}

#define get_centroid(x, y) (Centroid::init(y), Centroid::get(x))

void dfs(int x, int px = 0, int dep = 1) {
	int i, y; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px && !fy[y])
			dfs(y, x, dep + 1), size[x] += size[y];
}

void solve(int x) {
	int i, y, G;
	fy[x] = 1; dfs(x);
	// do something
	for (i = first[x]; i; i = next[i])
		if (!fy[y = to[i]])
			G = get_centroid(y, size[y]), solve(G);
}

// main
G = get_centroid(1, n); solve(G);