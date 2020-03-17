
inline bool idcmp(const int A, const int B) {return Tree::id[A] < Tree::id[B];}

void build() {
	using Tree::dep;
	int i, x, y;
	memcpy(_h, h, m << 2);
	std::sort(h, h + m, idcmp); cnt = 0;
	for(; top; --top) stack[top] = 0;
	for(i = 0; i < m; ++i) {
		x = h[i];
		if (!top) {stack[++top] = v[++cnt] = x; continue;}
		stack[top + 1] = 0;
		for (y = Tree::LCA(x, stack[top]); dep[stack[top]] > dep[y]; --top);
		p[stack[top + 1]] = y;
		if (stack[top] != y) {p[y] = stack[top]; stack[++top] = v[++cnt] = y;}
		p[x] = stack[top]; stack[++top] = v[++cnt] = x;
	}
	std::sort(v + 1, v + (cnt + 1), idcmp);
}