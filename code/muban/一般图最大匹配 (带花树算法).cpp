#define unknown -1
#define boy 0
#define girl 1

int LCA(int x, int y) {
	for (++hash_cnt; x; y ? swap(x, y) : (void)0) {
		x = ancestor(x);
		if (hash[x] == hash_cnt) return x; // visited
		hash[x] = hash_cnt;
		x = prev[match[x]];
	}
	return 0x131a371;
}

void blossom(int x, int y, int root, int &t) { // vertices in blossoms are all boys !
	for (int z; ancestor(x) != root; y = z, x = prev[y]) {
		prev[x] = y; z = match[x];
		if (col[z] == girl) que[t++] = z, col[z] = boy;
		if (ancestor(x) == x) p[x] = root;
		if (ancestor(z) == z) p[z] = root;
	}
}

bool bfs(int st) {
	int h, t = 1, i, x, y, b, g;
	que[0] = st; col[st] = boy;
	for (h = 0; h < t; ++h)
		for (i = first[x = que[h]]; i; i = next[i])
			if (col[y = to[i]] == unknown) { // common step
				prev[y] = x; col[y] = girl;
				if (!match[y]) { // augment (change mates) !!!
					for (g = y; g; swap(match[b], g))
						match[g] = b = prev[g];
					return true;
				}
				col[que[t++] = match[y]] = boy;
			} else if(col[y] == boy && ancestor(x) != ancestor(y)) { // flower !!!
				b = LCA(x, y); blossom(x, y, b, t); blossom(y, x, b, t);
			}
	return false;
}

// main process
for (i = 1; i <= V; ++i) {
	for (v = 1; v <= V; ++v) col[v] = unknown, p[v] = v;
	if (!match[i] && bfs(i)) ++ans;
}