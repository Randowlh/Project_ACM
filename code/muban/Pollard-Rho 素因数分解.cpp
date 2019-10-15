ll Pollard_Rho(ll n, int c) {
	ll i = 1, k = 2, x = rand() % (n - 1) + 1, y = x, p;
	for (; k <= 131072; ) {
		x = (MulMod(x, x, n) + c) % n;
		p = gcd<ll>((ull)(y - x + n) % n, n);
		if (p != 1 && p != n) return p;
		if (++i == k) y = x, k <<= 1;
	}
	return 0;
}

inline void push(ll prime, int alpha) {
	map::iterator it = result.find(prime);
	it == result.end() ? (void)result.insert(pr(prime, alpha)) : (void)(it->second += alpha);
}

void factor(ll n) {
	int i, j, k; ll p;
	for (i = 0; n != 1; )
		if (n >= MAX) {
			if (Miller_Rabin(n)) {push(n, 1); return;}
			for (k = 97; !(p = Pollard_Rho(n, k)); --k);
			factor(p); n /= p;
		} else {
			i = (c[n] ? c[n] : n);
			for (j = 0; !(n % i); n /= i, ++j);
			push(i, j);
		}
}