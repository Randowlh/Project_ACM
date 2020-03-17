const ll mod[3] = {900000011, 998244353, 1000000007};
const ll bas[3] = {4493, 8111, 8527};
// you can choose your bases and modulos

char s[S];
ll pw[3][S], Hash[3][S];

inline ll getHash(int id, int L, int R){ // str[L..R-1]
	ll J = (Hash[id][R] - Hash[id][L] * pw[id][R - L]) % mod[id];
	return J < 0 ? J + mod[id] : J;
}

// following is the pretreatment
ll *f, *g;
for(j = 0; j < 3; j++){
	f = Hash[j]; f[0] = 0;
	g = pw[j]; g[0] = 1;
	for(i = 0; i < n; i++){
		f[i + 1] = (f[i] * bas[j] + (s[i] - 'a')) % mod[j];
		g[i + 1] = g[i] * bas[j] % mod[j];
	}
}