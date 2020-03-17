inline void push(ll prime, int alpha) {pr[cnt] = prime, al[cnt++] = alpha;}

// version 2
inline void push(ll prime, int alpha) {
	map::iterator it = result.find(prime);
	it == result.end() ? (void)result.emplace(prime, alpha) : (void)(it->second += alpha);
}

void factor(ll n) {
	int i, j; cnt = 0; // result.clear();
	for (i = 0; n > 1; ) {
		if (n >= N) {
			for (; (ll)p[i] * p[i] <= n && n % p[i]; ++i);
			if (n % p[i]) return push(n, 1);
		} else i = c[n];
		for (j = 0; !(n % p[i]); n /= p[i], ++j); push(p[i], j);
	}
}