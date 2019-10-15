void Toposort(){
	int h, t = 0, x, y, i;
	for (i = 1; i <= V; ++i) if (!deg[i]) que[t++] = i;
	for (h = 0; h < t; ++h)
		for (i = first[x = que[h]]; i; i = next[i])
			if (!--deg[y = to[i]]) que[t++] = y;
}