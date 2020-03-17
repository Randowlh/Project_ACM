void sieve(int n) {
	int i, j, v; mu[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, mu[i] = -1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, mu[v] = -mu[i];
		if (v <= n) c[v] = j;
	}
}