inline ll MulMod(ll a, ll b, ll m){
	ll t = (a * b - (ll)((ld)a * b / m) * m) % m;
	return t + (t >> 63 & m);
}