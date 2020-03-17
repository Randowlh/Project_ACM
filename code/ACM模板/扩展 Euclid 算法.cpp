ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b) {ll d = exgcd(b, a % b, y, x); y -= a / b * x; return d;}
	else {x = 1; y = 0; return a;}
}