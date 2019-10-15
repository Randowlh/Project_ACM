void Dsum() {
	int i, j, k, l, n, sq, _;
	for (i = 1; i <= cnt && v[i] < N; ++i) Mu[i] = smu[v[i]], Phi[i] = sphi[v[i]];
	for (; i <= cnt; ++i) {
		int &m = Mu[i]; ll &p = Phi[i];
		n = v[i], sq = sqrt(n), m = 1, p = n * (n + 1ll) / 2, l = n / (sq + 1);
		for (j = sq; j; --j) {
			_ = (k = n / j) - l, m -= _ * smu[j], p -= _ * sphi[j], l = k;
			if (j != 1 && k > sq) m -= Mu[_ = ID(k)], p -= Phi[_];
		}
	}
}