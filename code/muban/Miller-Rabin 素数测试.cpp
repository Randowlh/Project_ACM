// No pseudoprime below 2^64 to base 2, 3, 5, 7, 11, 13, 82, 373.
const int test[8] = {2, 3, 5, 7, 11, 13, 82, 373};
bool Miller_Rabin(ll n) {
	if (n < MAX) return !c[n] && n > 1;
	int c, i, j; ll s = n - 1, u, v;
	for (c = 0; !(s & 1); ++c, s >>= 1);
	for (i = 0; i < 8; ++i) {
		if (!(n % test[i])) return false;
		u = PowerMod(test[i], s, n);
		for (j = 0; j < c; ++j, u = v)
			if (v = MulMod(u, u, n), u != 1 && u != n - 1 && v == 1) return false;
		if (u != 1) return false;
	}
	return true;
}