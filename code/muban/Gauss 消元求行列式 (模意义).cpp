int gauss(int n) {
	int i, j, k, det = 1; ll coe;
	static int *m[N];
	for (i = 0; i < n; ++i) m[i] = mat[i];
	for (i = 0; i < n; ++i) {
		for (j = i; j < n && !m[j][i]; ++j);
		if (j == n) return 0;
		if (i != j) det = mod - det, std::swap(m[i], m[j]);
		det = (ll)det * m[i][i] % mod;
		coe = PowerMod(m[i][i], mod - 2);
		for (j = 0; j < n; ++j) m[i][j] = m[i][j] * coe % mod;
		for (k = i + 1; k < n; ++k)
			for (coe = mod - m[k][i], j = i; j < n; ++j) m[k][j] = (m[k][j] + coe * m[i][j]) % mod;
	}
	return det;
}