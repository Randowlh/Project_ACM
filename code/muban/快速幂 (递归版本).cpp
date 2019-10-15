ll PowerMod(ll a, ll n, ll m = mod) {
	if (!n || a == 1) return 1ll;
	ll s = PowerMod(a, n >> 1, m);
	s = s * s % m;
	return n & 1 ? s * a % m : s;
}