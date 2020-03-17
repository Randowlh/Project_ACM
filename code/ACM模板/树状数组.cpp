最大公约数 (gcd) [#nt01]:
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
快速幂 (递归版本) [#nt02]:
ll PowerMod(ll a, ll n, ll m = mod) {
	if (!n || a == 1) return 1ll;
	ll s = PowerMod(a, n >> 1, m);
	s = s * s % m;
	return n & 1 ? s * a % m : s;
}
快速幂 (非递归版本) [#nt03]:
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}
扩展 Euclid 算法 (exgcd) [#nt04]:
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b) {ll d = exgcd(b, a % b, y, x); y -= a / b * x; return d;}
	else {x = 1; y = 0; return a;}
}
线性推逆元 [#nt05]:
for (inv[1] = 1, i = 2; i <= n; ++i) inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
线性筛素数 (筛最小素因子) [#nt06]:
int pn = 0, c[N], p[78540];

void sieve(int n) {
	int i, j, v;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++;
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
	}
}
Miller-Rabin 素数测试 [#nt07]:
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
分解质因数 [#nt08]:
// version 1
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
线性筛 Euler φ 函数 [#nt09]:
void sieve(int n) {
	int i, j, v; phi[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, phi[i] = i - 1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, phi[v] = phi[i] * (p[j] - 1);
		if (v <= n) c[v] = j, phi[v] = phi[i] * p[j];
	}
}
线性筛 Möbius μ 函数 [#nt10]:
void sieve(int n) {
	int i, j, v; mu[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, mu[i] = -1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, mu[v] = -mu[i];
		if (v <= n) c[v] = j;
	}
}
遍历 ⌊n / i⌋ 的所有可能值 (分块，版本 1) [#nt11]:
#define next(n, i) (n / (n / i + 1))
for(i = n; i >= 1; i = j){
	j = next(n, i);
	// do something
}
遍历 ⌊n / i⌋ 的所有可能值 (分块，版本 2) [#nt12]:
#define _next(n, i) (n / (n / (i + 1)))
for(i = 0; i < n; i = j){
	j = _next(n, i);
	// do something
}

// 0 1 100 1 2 50 2 3 33 3 4 25 4 5 20 5 6 16 16 6 7 14 7 8 12 8 9 11 9 10 10 10 11 9 11 12 8 12 13 7 14 15 6 16 17 5 20 21 4 25 26 3 33 34 2 50 51 1 100 101 0 ?
杜教筛 (杜氏求和法) [#nt13]:
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
大小步离散对数 [#nt14]:
int Boy_Step_Girl_Step(){
	mii :: iterator it;
	ll boy = 1, girl = 1, i, t;
	for(i = 0; i < B; i++){
		m.insert(pr((int)boy, i)); // if there exists in map, then ignore it
		(boy *= a) %= p;
	}
	for(i = 0; i * B < p; i++){
		t = b * inv(girl) % p;
		it = m.find((int)t);
		if(it != m.end())
			return i * B + it->second;
		(girl *= boy) %= p;
	}
	return -1;
} 

// input p and then B = (int)sqrt(p - 1);
// inv(x) is the multiplicative inverse of x in Z[p].
// mii: map <int, int> and m is a variable of which.
Pollard-Rho 素因数分解 [#nt15]:
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
字符串 Hash [#str01]:
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
KMP 模式匹配 [#str02]:
// pretreatment (border) 
for(i = 1; i < s_n; ){
	while(j >= 0 && s[j] != s[i]) j = f[j];
	f[++i] = ++j;
}

// KMP
for(i = 0; i < m_n; i++){
	while(j >= 0 && s[j] != m[i]) j = f[j];
	if(++j == s_n) printf("%d ", i - s_n + 2);
}
字典树 [#str03]:
void append(char *s){
	char *p = s;
	int t = 1, id; // t = 0 is also OK
	for(; *p; ++p){
		id = *p - 97;
		t = d[t][id] ? d[t][id] : (d[t][id] = ++V);
	}
	++val[t];
}

// the process of matching is just like going on a DFA, so omit it.
Aho-Corasick 自动机 [#str04]:
void build(){
	int h, ta = 1, i, t, id;
	que[0] = 1;
	f[1] = 0;
	for(h = 0; h < ta; ++h)
		for(i = que[h], id = 0; id < 26; ++id){ // 26 is the size of char-set
			t = (f[i] ? d[f[i]][id] : 1); // 1 or 0 depend on the root of trie
			int &u = d[i][id];
			if(!u) {u = t; continue;}
			f[u] = t; val[u] |= val[t]; que[ta++] = u;
			la[u] = (v[t] ? t : la[t]);
		}
}
后缀数组 (倍增构造) [#str05]:
// definitions
int n, i, j, p, m;
char s[MAX];
int sa[MAX], r1[MAX], r2[MAX], wv[MAX], wt[MAX];
int Ht[MAX];

// s is the original string, n is the length of s
x = r1; y = r2; m = 27; // the size of char-set + 1
for(i = 0; i < n; i++) {sa[i] = i; x[i] = s[i] - '`';}
x[n] = 0;
sort(sa, sa + n, cmp);
for(j = 1; j < n; j <<= 1, m = ++p){
	p = 0;
	for(i = n - j; i < n; i++) y[p++] = i;
	for(i = 0; i < n; i++)
		if(sa[i] >= j)
			y[p++] = sa[i] - j;
	memset(wt, 0, m << 2);
	for(i = 0; i < n; i++) {wv[i] = x[y[i]]; ++wt[wv[i]];}
	for(i = 1; i < m; i++) wt[i] += wt[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wt[wv[i]]] = y[i];
	swap(x, y);
	x[sa[0]] = p = 1;
	for(i = 1; i < n; i++)
		x[sa[i]] = cmp2(y, sa[i - 1], sa[i], j) ? p : ++p;
	x[n] = 0;
}
// now the sa[] is the suffix array, number from 0. (0 ~ n-1)
// and the x[] is the ranking array, number from 1. (1 ~ n)
Ht[0] = p = 0;
for(i = 0; i < n; i++){
	p ? --p : 0;
	if(x[i] == 1) continue;
	for(j = sa[x[i] - 2]; s[i + p] == s[j + p]; p++);	
	Ht[x[i] - 1] = p;
}
// now Ht[i] is the longest common prefix of sa[i-1] and sa[i]
后缀自动机 [#str06]:
#define q d[p][x]
int extend(int x) {
	for (p = np, val[np = ++cnt] = val[p] + 1; p && !q; q = np, p = pa[p]);
	if (!p) pa[np] = 1;
	else if (val[p] + 1 == val[q]) pa[np] = q;
	else {
		int nq = ++cnt;
		val[nq] = val[p] + 1, memcpy(d[nq], d[q], 104);
		pa[nq] = pa[q], pa[np] = pa[q] = nq;
		for (int Q = q; p && q == Q; q = nq, p = pa[p]);
	}
	return f[np] = 1, np;
}
#undef q
根据后缀自动机构造后缀树和后缀数组 [#str07]:
// the first line of extend(x) will be:
for(p = np, val[np = ++cnt] = val[p] + 1, key[np] = Key; p && !q; q = np, p = pa[p]);

// and then
void child_init(){
	int i, j, pos;
	for(used[1] = 1, i = 2; i <= cnt; i++)
		if(~key[i])
			for(pos = n, j = i; !used[j]; j = pa[j]){
				pos += val[pa[j]] - val[j];
				child[pa[j]][s[pos] - 'a'] = j;
				used[j] = 1;
			}
}

void dfs(int x){
	if(~key[x]) sa[sat++] = key[x];
	for(int i = 0; i < 26; i++)
		if(child[x][i])
			dfs(child[x][i]);
}

// and ranking array [0..n-1]
for(i = 0; i < n; i++) rk[sa[i]] = i;

// and lcps
for(i = 0; i < n; i++){
	p ? --p : 0;
	if(!rk[i]) continue;
	for(j = sa[rk[i] - 1]; s[i + p] == s[j + p]; ++p);
	ht[rk[i] - 1] = p;
}
// ht[i] is the lcp of sa[i] and sa[i+1]
Z 算法 [#str08]:
void Z() {
	int i, Max = 0, M = 0;
	for (i = 1; i < n; ++i) {
		z[i] = (i < Max ? std::min(z[i - M], Max - i) : 0);
		for (; s[z[i]] == s[i + z[i]]; ++z[i]);
		if (i + z[i] > Max) Max = i + z[i], M = i; 
	}
}
Manacher 回文串 [#str09]:
void Manacher() {
	int n = 2, i, Max = 0, M = 0;
	t[0] = 2, t[1] = 1;
	for (i = 0; i < S; ++i) t[n++] = s[i], t[n++] = 1; t[n++] = 3;
	for (i = 0; i < n; ++i){
		f[i] = (i < Max ? std::min(f[M * 2 - i], Max - i) : 1);
		for(; t[i + f[i]] == t[i - f[i]]; ++f[i]);
		if (i + f[i] > Max) Max = i + f[i], M = i;
	}
}
回文自动机 [#str10]:
int get_fail(int x) {for (; ptr[~val[x]] != *ptr; x = fail[x]); return x;}

int extend(int x) {
	int &q = d[p = get_fail(p)][x];
	if (!q) fail[++cnt] = d[get_fail(fail[p])][x], val[q = cnt] = val[p] + 2;
	return p = q;
}

val[1] = -1, p = 0, *fail = cnt = 1;
深度优先搜索 (dfs，大法师) [#tr01]:
// implementation 1
void dfs(int x){
	int i, y;
	// do something
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != p[x]){
			p[y] = x;
			// do something
			dfs(y);
			// do something
		}
	// do something
}

// implementation 2
void dfs(int x, int px){
	int i, y;
	// do something
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != px){
			// do something
			dfs(y, x);
			// do something
		}
	// do something
}
最近公共祖先 (LCA) 的倍增算法 (树上倍增的基本模板) [#tr02]:
void dfs(int x) {
	int i, y;
	for (i = 0; P[i][x]; ++i) P[i + 1][x] = P[i][P[i][x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, dfs(y);
}

int jump_until(int x, int d) {
	for (int i = LN - 1; i >= 0; --i)
		if (dep[x] - (1 << i) >= d)
			x = P[i][x];
	return x;
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	if (x = jump_until(x, dep[y]), x == y) return x;
	for (int i = LN - 1; i >= 0; --i)
		if (P[i][x] != P[i][y])
			x = P[i][x], y = P[i][y];
	return p[x];
}
最近公共祖先 (LCA) 的 ST 表算法 [#tr03]:
#define lg2(x) (31 - __builtin_clz(x))

int cnt, id[N], st[21][M], *ord = *st;

inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}

void dfs(int x, int px = 0) {
	int i, y;
	ord[cnt] = x; id[x] = cnt++;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px)
			dep[y] = dep[x] + 1, dfs(y, x), ord[cnt++] = x;
}

void build_st_table() {
	int *f, *g = ord, i, j, k = cnt;
	for (j = 0; 1 << j + 1 <= cnt; ++j) {
		f = g; g = st[j + 1]; k -= 1 << j;
		for (i = 0; i < k; ++i)
			g[i] = dmin(f[i], f[i + (1 << j)]);
	}
}

inline int LCA(int x, int y) {
	int L = std::min(id[x], id[y]), R = (id[x] ^ id[y] ^ L) + 1, c = lg2(R - L);
	return dmin(st[c][L], st[c][R - (1 << c)]);
}
轻重链剖分 (Heavy-Light Decomposition) [#tr04]:
int p[N], dep[N], size[N];
int cnt = 0, id[N], prf[N], top[N];

void dfs_wt(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x, dep[y] = dep[x] + 1;
			dfs_wt(y), size[x] += size[y];
			size[y] > size[z] ? z = y : 0;
		}
}

void dfs_hld(int x, int r) {
	int i, y; id[x] = ++cnt, top[x] = r;
	if (!prf[x]) return;
	dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
}

int solve(int u, int v) {
	int x = top[u], y = top[v];
	for (; x != y; u = p[x], x = top[u]) {
		if (dep[x] < dep[y]) {swap(u, v); swap(x, y);}
		// do something on [x, u]
	}
	if (dep[u] > dep[v]) {swap(u, v); swap(lx, ly);}
	// do something on [u, v]
	// return something
}
树分治 (静态点分治) [#tr05]:
namespace Centroid {
	int V, Gm, G, size[N];

	void init(int _V) {V = _V; Gm = INT_MAX;}

	int get(int x, int px = 0) {
		int i, y, Max = 0; size[x] = 1;
		for (i = first[x]; i; i = next[i])
			if ((y = to[i]) != px && !fy[y]) {
				get(y, x); up(Max, size[y]);
				size[x] += size[y];
			}
		up(Max, V - size[x]);
		return Max <= Gm ? (Gm = Max, G = x) : G;
	}
}

#define get_centroid(x, y) (Centroid::init(y), Centroid::get(x))

void dfs(int x, int px = 0, int dep = 1) {
	int i, y; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px && !fy[y])
			dfs(y, x, dep + 1), size[x] += size[y];
}

void solve(int x) {
	int i, y, G;
	fy[x] = 1; dfs(x);
	// do something
	for (i = first[x]; i; i = next[i])
		if (!fy[y = to[i]])
			G = get_centroid(y, size[y]), solve(G);
}

// main
G = get_centroid(1, n); solve(G);
虚树 (深度栈算法) [#tr06]:
inline bool idcmp(const int A, const int B) {return Tree::id[A] < Tree::id[B];}

void build() {
	using Tree::dep;
	int i, x, y;
	memcpy(_h, h, m << 2);
	std::sort(h, h + m, idcmp); cnt = 0;
	for(; top; --top) stack[top] = 0;
	for(i = 0; i < m; ++i) {
		x = h[i];
		if (!top) {stack[++top] = v[++cnt] = x; continue;}
		stack[top + 1] = 0;
		for (y = Tree::LCA(x, stack[top]); dep[stack[top]] > dep[y]; --top);
		p[stack[top + 1]] = y;
		if (stack[top] != y) {p[y] = stack[top]; stack[++top] = v[++cnt] = y;}
		p[x] = stack[top]; stack[++top] = v[++cnt] = x;
	}
	std::sort(v + 1, v + (cnt + 1), idcmp);
}
长链剖分 (Long-Short Decomposition) [#tr07]:
void dfs_len(int x) {
	int i, y, &z = prf[x];
	for (i = 0; i < LN && P[i][x]; ++i) P[i + 1][x] = P[i][P[i][x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x; dep[y] = dep[x] + 1;
			dfs_len(y);
			up(f[x], f[y] + 1);
			f[y] > f[z] ? z = y : 0;
		}
}

void dfs_lsd(int x, int r, int l = 1) { // long-short decomposition
	int i, y;
	id[x] = ++cnt; top[x] = r;
	if (!prf[x]) {len[x] = l; return;}
	dfs_lsd(prf[x], r, l + 1); len[x] = len[prf[x]];
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]])
			dfs_lsd(y, y);
}

int ancestor(int x, int k) {
	if (dep[x] < k) return 0;
	if (!k) return x;
	int i = lg2(k); x = P[i][x]; k ^= 1 << i;
	if (!k) return x;
	i = dep[x] - dep[top[x]] - k;
	return near[top[x]][i];
}

void init() {
	int i, j, x, *pt;
	*f = *dep = -1; dfs_len(1); dfs_lsd(1, 1);
	for (i = 1; i < N; ++i)
		if (top[i] == i) {
			near[i] = (new int[len[i] * 2 + 1]) + len[i]; pt = near[i]; *pt = i;
			for (j = 1, x = p[i]; j <= len[i] && x; ++j, x = p[x]) pt[-j] = x;
			for (j = 1, x = prf[i]; j <= len[i] && x; ++j, x = prf[x]) pt[j] = x;
		}
}
双向邻接表 [#gr01]:
inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}
有向图的强连通分量 [#gr02]:
void dfs(int x) {
	int i, y;
	id[x] = low[x] = ++cnt; instack[x] = 1; sta[stc++] = x;
	for(i = first[x]; i; i = next[i])
		if (!id[y = to[i]])
			dfs(y), down(low[x], low[y]);
		else if (instack[y])
			down(low[x], id[y]);
	if (id[x] == low[x])
		for (y = 0; y != x; )
			y = sta[--stc], instack[y] = 0, top[y] = x;
}
有向无环图的拓扑排序 [#gr03]:
void Toposort(){
	int h, t = 0, x, y, i;
	for (i = 1; i <= V; ++i) if (!deg[i]) que[t++] = i;
	for (h = 0; h < t; ++h)
		for (i = first[x = que[h]]; i; i = next[i])
			if (!--deg[y = to[i]]) que[t++] = y;
}
无向图的桥边 [#gr04]:
void dfs(int x, int px){
	int i, y;
	id[x] = low[x] = ++cnt;
	for(i = first[x]; i; i = next[i])
		if(!id[y = to[i]]){
			dfs(y, x);
			down(low[x], low[y]);
			if(id[x] < low[y]) // edge i is a bridge
		}else
			low[x] = min(low[x], id[y]);
}
无向图的割点 [#gr05]:
void dfs(int x, int px){
	int i, y, M = 0;
	id[x] = low[x] = ++cnt;
	for(i = first[x]; i; i = next[i])
		if(!id[y = to[i]]){
			++M;
			dfs(y, x);
			down(low[x], low[y]);
			if(id[x] <= low[y]) // vertex x is a cut-point
		}else
			low[x] = min(low[x], id[y]);
	if(px == -1 && M > 1) // vertex x is a cut-point
}
无向图的边双缩点 [#gr06]:
void dfs(int x, int px = 0) {
	int i, y;
	id[x] = low[x] = ++cnt; stack[stc++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = to[i]]) {
			dfs(y, i), down(low[x], low[y]);
			if (id[x] < low[y]) bridge[ad(i)] = bridge[i] = true;
		} else if (px - 1 ^ i - 1 ^ 1)
			down(low[x], id[y]);
	if (id[x] == low[x])
		for (y = 0; y != x; )
			y = stack[--stc], top[y] = x;
}
无向图的点双缩点 [#gr07]:
void dfs(int x, int px) {
	int i, y, z;
	id[x] = low[x] = ++cnt; stack[top++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = to[i]]) {
			dfs(y, i), down(low[x], low[y]);
			if (id[x] <= low[y])
				for (link(++bcc_cnt + V, x), z = 0; z != y; )
					link(bcc_cnt + V, z = stack[--top]);
		} else if (i - 1 ^ px - 1 ^ 1)
			down(low[x], id[y]);
}
带权 edge 结构体 [#gr08]:
struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
};
单源最短路 (Dijkstra) [#gr09]:
#include <ext/pb_ds/priority_queue.hpp>
using __gnu_pbds::priority_queue;

struct node{
	int to, dist;
	node (int to0 = 0, int dist0 = 0): to(to0), dist(dist0) {}
	inline bool operator < (const node &b) const {return dist > b.dist;}
};

priority_queue <node> pq;

void Dijkstra(int s){
	int i, y; node t;
	for(i = 1; i <= V; i++) d[i] = (i == s ? 0 : INF);
	for(pq.push(node(s, 0)); !pq.empty(); ){
		t = pq.top(); pq.pop();
		if(d[t.to] < t.dist) continue;
		for(i = first[t.to]; i; i = next[i])
			if(t.dist + e[i].w < d[y = e[i].v]){
				d[y] = t.dist + e[i].w;
				pq.push(node(y, d[y]));
			}
	}
}
所有点对的最短路 (Floyd) [#gr10]:
int Floyd(){
	int i, j, k;
	for(k = 1; k <= V; k++)
		for(i = 1; i <= V; i++)
			for(j = 1; j <= V; j++)
				down(d[i][j], d[i][k] + d[k][j]);
	return 0;
}
最小生成树 (Kruskal) [#gr11]:
struct edge{
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0): u(u0), v(v0), w(w0) {}
	bool operator < (const edge &b) const {return w < b.w;}
};

void Kruskal(){
	uf.resize(V);
	sort(e + 1, e + (E + 1));
	for(i = 1; i <= E; i++)
		if(!uf.test(e[i].u, e[i].v, true)){
			// e is an edge of minimum spanning tree
			if(++Es >= V - 1) return;
		}
}
网络流 edge 结构体 [#gr12]:
struct edge{
	int u, v, f; // f is remaining flow
	edge(int u0 = 0, int v0 = 0, int f0 = 0): u(u0), v(v0), f(f0) {}
};
最大流 (Dinic) [#gr13]:
namespace Flow {
	#define ad(x) ((x - 1 ^ 1) + 1)

	const int N = 2000, M = 100000;

	struct edge {
		int u, v, f;
		edge (int u0 = 0, int v0 = 0, int f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, flow;
	int first[N], next[M];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, int f) {
		e[++E] = edge(u, v, f); next[E] = first[u]; first[u] = E;
		e[++E] = edge(v, u); next[E] = first[v]; first[v] = E;
	}

	bool bfs() {
		int h, t = 1, i, x, y;
		memset(dep, -1, sizeof dep);
		que[0] = si; dep[si] = 0;
		for (h = 0; h < t; h++) {
			if ((x = que[h]) == ti) return true;
			for (i = first[x]; i; i = next[i])
				if (dep[y = e[i].v] == -1 && e[i].f) {
					que[t++] = y;
					dep[y] = dep[x] + 1;
				}
		}
		return false;
	}

	int dfs(int x, int lim) {
		int a, c, f = 0;
		if (x == ti || !lim) return lim;
		for (int &i = cur[x]; i; i = next[i])
			if (dep[e[i].v] == dep[x] + 1 && e[i].f) {
				a = std::min(lim - f, e[i].f);
				c = dfs(e[i].v, a);
				e[i].f -= c; e[ad(i)].f += c;
				if((f += c) == lim) return f;
			}
		return f;
	}

	int Dinic() {
		for (flow = 0; bfs(); flow += dfs(si, INT_MAX))
			memcpy(cur, first, sizeof cur);
		return flow;
	}
}
最小费用最大流 (Dinic) [#gr14]:
namespace CF{
	#define ad(x) ((x - 1 ^ 1) + 1)
	#define INF 0x7f7f7f7f
	struct edge{
		int u, v, c, f;
		edge (int u0 = 0, int v0 = 0, int c0 = 0, int f0 = 0): u(u0), v(v0), c(c0), f(f0) {}
	}e[M];

	int V, E, si = 1, ti = 2, flow, cost;
	int first[N], next[M];
	int dep[N], cur[N], que[M << 1];
	char in_que[N], used[N];

	inline void addedge(int u, int v, int c, int f){
		e[++E] = edge(u, v, c, f); next[E] = first[u]; first[u] = E;
		e[++E] = edge(v, u, -c); next[E] = first[v]; first[v] = E;
	}

	bool bfs(){
		int h = M, t = h + 1, i, x, y;
		memset(dep, 127, sizeof dep);
		que[h] = ti; dep[ti] = 0; in_que[ti] = 1;
		for(; h < t; ){
			x = que[h++]; in_que[x] = 0;
			for(i = first[x]; i; i = next[i])
				if(dep[y = e[i].v] > dep[x] - e[i].c && e[ad(i)].f){
					dep[y] = dep[x] - e[i].c;
					if(!in_que[y]){
						in_que[y] = 1;
						(dep[y] >= dep[que[h]] ? que[t++] : que[--h]) = y;
					}
				}
		}
		return dep[si] < INF;
	}

	int dfs(int x, int lim){
		int a, c, f = 0;
		if(x == ti || !lim) return lim;
		used[x] = 1;
		for(int &i = cur[x]; i; i = next[i])
			if(dep[e[i].v] == dep[x] - e[i].c && e[i].f && !used[e[i].v]){
				a = min(lim - f, e[i].f);
				c = dfs(e[i].v, a);
				e[i].f -= c; e[ad(i)].f += c;
				if((f += c) == lim) return f;
			}
		return f;
	}

	void Dinic(){
		int f;
		for(cost = flow = 0; bfs(); ){
			memcpy(cur, first, sizeof cur);
			memset(used, 0, sizeof used);
			flow += f = dfs(si, INF);
			cost += dep[si] * f;
		}
	}
}
二分图最大匹配 (增广路算法) [#gr15]:
bool dfs(int x){
	for(int i = 1; i <= n_g; i++)
		if(e[x][i] && !used[i]){
			used[i] = 1;
			if(!boy[i] || dfs(boy[i])){
				boy[i] = x; girl[x] = i; return true;
			}
		}
	return false;
}
一般图最大匹配 (带花树算法) [#gr16]:
#define unknown -1
#define boy 0
#define girl 1

int LCA(int x, int y) {
	for (++hash_cnt; x; y ? swap(x, y) : (void)0) {
		x = ancestor(x);
		if (hash[x] == hash_cnt) return x; // visited
		hash[x] = hash_cnt;
		x = prev[match[x]];
	}
	return 0x131a371;
}

void blossom(int x, int y, int root, int &t) { // vertices in blossoms are all boys !
	for (int z; ancestor(x) != root; y = z, x = prev[y]) {
		prev[x] = y; z = match[x];
		if (col[z] == girl) que[t++] = z, col[z] = boy;
		if (ancestor(x) == x) p[x] = root;
		if (ancestor(z) == z) p[z] = root;
	}
}

bool bfs(int st) {
	int h, t = 1, i, x, y, b, g;
	que[0] = st; col[st] = boy;
	for (h = 0; h < t; ++h)
		for (i = first[x = que[h]]; i; i = next[i])
			if (col[y = to[i]] == unknown) { // common step
				prev[y] = x; col[y] = girl;
				if (!match[y]) { // augment (change mates) !!!
					for (g = y; g; swap(match[b], g))
						match[g] = b = prev[g];
					return true;
				}
				col[que[t++] = match[y]] = boy;
			} else if(col[y] == boy && ancestor(x) != ancestor(y)) { // flower !!!
				b = LCA(x, y); blossom(x, y, b, t); blossom(y, x, b, t);
			}
	return false;
}

// main process
for (i = 1; i <= V; ++i) {
	for (v = 1; v <= V; ++v) col[v] = unknown, p[v] = v;
	if (!match[i] && bfs(i)) ++ans;
}
并查集 (不封装，按秩合并) [#ds01]:
int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

bool test(int x, int y, bool un = false) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	if (un) size[x] > size[y] ? std::swap(x, y) : (void)0, p[x] = y, size[y] += size[x];
	return false;
}
并查集 (封装) [#ds02]:
struct UFind{
	int sz, *p;
	UFind (): sz(0) {p = NULL;}
	~UFind () {if(p) delete [] (p);}
	void resize(int size){
		if(p) delete [] (p); p = new int[(sz = size) + 1];
		for(int i = 0; i <= sz; i++) p[i] = i;
	}
	int ancestor(int x) {return x == p[x] ? x : p[x] = ancestor(p[x]);}
	bool test(int x, int y, bool un = false){
		if((x = ancestor(x)) == (y = ancestor(y))) return true;
		if(un) p[x] = y; return false;
	}
};
树状数组 (不封装) [#ds03]:
#define lowbit(x) (x & -x)

int sum(int h){
	int s = 0;
	while(h){
		s += a[h];
		h -= lowbit(h);
	}
	return s;
}

int add(int h, int v){
	while(h <= n){
		a[h] += v;
		h += lowbit(h);
	}
	return v;
}
树状数组 (封装) [#ds04]:
#define lowbit(x) (x & -x)

struct BIT{
	int sz, *x;
	BIT (): sz(0) {x = NULL;}
	~BIT () {if(x) delete [] (x);}
	void resize(int size) {sz = size; if(x) delete [] (x); x = new int[sz + 5]; memset(x, 0, sz + 5 << 2);}
	int sum(int h) {int s = 0; if(h <= 0) return s; while(h) {s += x[h]; h -= lowbit(h);} return s;}
	int range(int l, int r) {return sum(r) - sum(l - 1);} 
	void add(int h, int v) {while(h <= sz) {x[h] += v; h += lowbit(h);}}
};
线段树 (不封装) [#ds05]:
#define segc int M = L + R - 1 >> 1, lc = id << 1, rc = lc | 1

void add(int id, int L, int R, int h, int v){
	if(L == R) return void(st[id] += v);
	segc; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v);
	x[id].v = x[lc].v + x[rc].v;
}

int range(int id, int L, int R, int ql, int qr){
	if(ql <= L && qr >= R) return st[id];
	segc, s = 0;
	if(ql <= M) s += range(lc, L, M, ql, min(qr, M));
	if(qr > M) s += range(rc, M + 1, R, max(ql, M + 1), qr);
	return s;
}
线段树 (封装) [#ds06]:
struct ST{
	#define segc int M = L + R - 1 >> 1, lc = id << 1, rc = lc | 1
	int sz;
	struct node {int v, f; bool zero;} *x;
	ST (): sz(0) {x = NULL;}
	~ST () {if(x) delete [] (x);}
	void resize(int size) {sz = size; int sz0 = sz << 3; if(x) delete [] (x);
		x = new node[sz0]; memset(x, 0, sz0 * sizeof(node));}

	void add(int h, int v) {add(1, 1, sz, h, v);}
	int range(int l, int r) {return query(1, 1, sz, l, r);}

	void add(int id, int L, int R, int h, int v){
		if(L == R) return void(x[id].v += v);
		segc; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v);
		x[id].v = x[lc].v + x[rc].v;
	}

	int query(int id, int L, int R, int ql, int qr){
		if(ql <= L && R <= qr) return x[id].v;
		segc, s = 0;
		if(ql <= M) s += query(lc, L, M, ql, min(qr, M));
		if(qr > M) s += query(rc, M + 1, R, max(ql, M + 1), qr);
		return s;
	}
};
可持久化线段树 (add 操作) [#ds07]:
int add(int _id, int L, int R, int h, int v){
	int id = ++cnt; x[id] = x[_id]; x[id].v += v;
	if(L == R) return id;
	int M = L + R - 1 >> 1;
	if(h <= M) x[id].lc = add(x[id].lc, L, M, h, v);
	else x[id].rc = add(x[id].rc, M + 1, R, h, v);
	return id;
}
伸展树 (Splay)[#ds08]:
#define pa p[nd]
#define root nd[0].c[0]
struct node {int v, sz, p, c[2]; ll sum;} nd[N];

inline int dir(int x) {return x == x[nd].pa.c[1];}

inline void update(int x){
	x[nd].sz = x[nd].c[0][nd].sz + x[nd].c[1][nd].sz + 1;
	x[nd].sum = x[nd].c[0][nd].sum + x[nd].c[1][nd].sum + x[nd].v;
}

void rotate(int x){
	int y = x[nd].p, d = !dir(x);
	nd[y[nd].c[!d] = x[nd].c[d]].p = y;
	x[nd].p = y[nd].p;
	y[nd].pa.c[dir(y)] = x;
	nd[x[nd].c[d] = y].p = x;
	update(y);
}

void splay(int x, int g = 0){
	for(; x[nd].p != g; rotate(x))
		if(x[nd].pa.p != g) rotate(dir(x) ^ dir(x[nd].p) ? x : x[nd].p);
	update(x);
}

void insert(int x){
	int y = 0, d = 0;
	if(root) for(y = root; d = (val[x] < y[nd].v), y[nd].c[d]; y = y[nd].c[d]);
	y[nd].c[d] = x;
	nd[x].v = nd[x].sum = val[x]; nd[x].sz = 1; nd[x].p = y; nd[x].c[0] = nd[x].c[1] = 0;
	splay(x);
}

void erase(int x){
	if(x[nd].p) splay(x);
	if(!(x[nd].c[0] && x[nd].c[1])){
		int d = (x[nd].c[1] > 0);
		x[nd].c[d][nd].p = 0;
		root = x[nd].c[d];
	}else{
		int y;
		for(y = x[nd].c[1]; y[nd].c[0]; y = y[nd].c[0]);
		splay(y, x);
		nd[y[nd].c[0] = x[nd].c[0]].p = y;
		y[nd].p = 0; root = y;
		update(y);
	}
}

int kth(int x, int v){
	if(x[nd].sz < v) return -1;
	for(int j; ; ){
		j = x[nd].c[0][nd].sz;
		if(v == j + 1) return x;
		x = x[nd].c[v > j]; v > j ? (v -= j + 1) : v;
	}
}
动态树 (Link-Cut Tree) [#ds09]:
namespace LCT {
	#define pa p[nd]
	struct node {bool rev; int v, p, c[2];} nd[N];
	inline int dir(int x) {return !nd[x].p ? -1 : x == nd[x].pa.c[0] ? 0 : x == nd[x].pa.c[1] ? 1 : -1;}
	inline void reverse(int x) {x && (std::swap(nd[x].c[0], nd[x].c[1]), nd[x].rev = !nd[x].rev);}
	void push_down(int x) {if (nd[x].rev) reverse(nd[x].c[0]), reverse(nd[x].c[1]), nd[x].rev = false;}
	void pull_down(int x) {if (~dir(x)) pull_down(nd[x].p); push_down(x);}
	inline void update(int x) {const int l = nd[x].c[0], r = nd[x].c[1]; nd[x].v = (l ? nd[l].v : 0) + (r ? nd[r].v : 0);}
	void rotate(int x) {
		int y = nd[x].p, d = !dir(x);
		nd[nd[y].c[!d] = nd[x].c[d]].p = y;
		nd[x].p = nd[y].p;
		if (~dir(y)) nd[y].pa.c[dir(y)] = x;
		nd[nd[x].c[d] = y].p = x;
		update(y);
	}
	void splay(int x) {for (pull_down(x); ~dir(x); rotate(x)) if (~dir(nd[x].p)) rotate(dir(x) ^ dir(nd[x].p) ? x : nd[x].p); update(x);}
	void access(int x) {for (int y = 0; x; y = x, x = nd[x].p) splay(x), nd[x].c[1] = y, update(x);}
	void make_root(int x) {access(x), splay(x), reverse(x);}
	int find_root(int x) {for (access(x), splay(x); push_down(x), nd[x].c[0]; x = nd[x].c[0]); return splay(x), x;}
	int split(int x, int y) {return make_root(x), access(y), splay(y), y;}
	void link(int x, int y) {make_root(x), nd[x].p = y;}
	void cut(int x, int y) {split(x, y), nd[x].p = nd[y].c[0] = 0, update(y);}
	void trylink(int x, int y) {x == y || (split(x, y), ~dir(x)) || (nd[x].p = y);}
	void trycut(int x, int y) {split(x, y), nd[y].c[0] == x && !nd[x].c[1] && (nd[x].p = nd[y].c[0] = 0, update(y), 0);}
}
树堆 (Treap) [#ds10]:
struct random_t{
	ull seed;
	static const ull multiplier = 0x5deece66dll;;
	static const ull addend = 0xbll;
	static const ull mask = 0xffffffffffffll;

	random_t () {char *x = new char; seed = (ull)x; delete x;}

	unsigned int next(){
		seed = (seed * multiplier + addend) & mask;
		return seed >> 16;
	}

	unsigned int next(unsigned int n){
		return n * (ull)next() >> 32;
	}
}rnd;

#define pa p[nd]
#define C(x) c[x][nd]
#define root nd[0].c[0]

struct node {int v, sz, pt; int c[2], p; unsigned priority;} nd[N];
int cnt = 0;

inline int dir(int x) {return x == nd[x].pa.c[1];}

inline void update(int x){
	nd[x].sz = nd[x].C(0).sz + nd[x].C(1).sz + nd[x].pt;
}

void rotate(int x){
	int y = nd[x].p, d = !dir(x);
	nd[nd[y].c[!d] = nd[x].c[d]].p = y;
	nd[x].p = nd[y].p;
	nd[y].pa.c[dir(y)] = x;
	nd[nd[x].c[d] = y].p = x;
	update(y); update(x);
}

void push_up(int x) {for(; x; x = nd[x].p) update(x);}

void rotation(int x) {for(; nd[x].p && nd[x].priority < nd[x].pa.priority; ) rotate(x);}

void insert(int v){
	int x = 0, y = 0, d = 0;
	if(root) for(y = root; nd[y].v != v && nd[y].c[d = v > nd[y].v]; y = nd[y].c[d]);
	if(nd[y].v == v) {++nd[y].pt; push_up(y); return;}
	nd[y].c[d] = x = ++cnt;
	nd[x].v = v; nd[x].sz = nd[x].pt = 1; nd[x].p = y; nd[x].c[0] = nd[x].c[1] = 0;
	nd[x].priority = rnd.next(); push_up(y);
	rotation(x);
}

void erase(int v){
	int x = 0, y = 0, d = 0;
	if(root) for(x = root; nd[x].v != v && nd[x].c[d = v > nd[x].v]; x = nd[x].c[d]);
	if(nd[x].v != v) return;
	if(nd[x].pt > 1) {--nd[x].pt; push_up(x); return;}
	for(; nd[x].c[0] && nd[x].c[1]; rotate(nd[x].c[d]))
		d = nd[x].C(0).priority > nd[x].C(1).priority;
	d = nd[x].c[1] > 0; y = nd[x].c[d];
	nd[y].p = nd[x].p; nd[x].pa.c[dir(x)] = y; push_up(nd[y].p);
}

int rank(int v){
	int x = 0, d = 0, k = 0;
	if(root) for(x = root; nd[x].v != v && nd[x].c[d = v > nd[x].v]; x = nd[x].c[d])
		if(d) k += nd[x].C(0).sz + nd[x].pt;
	if(nd[x].v != v) return -1;
	return k + nd[x].C(0).sz;
}

int kth(int k){
	int x = root;
	if(nd[x].sz < k) return -1;
	for(int j, z; ; ){
		j = nd[x].C(0).sz; z = nd[x].pt;
		if(j <= k && k < j + z) return x;
		x = nd[x].c[k > j]; k > j ? (k -= j + z) : k;
	}
}

int prev(int v){
	int x = 0, r = -1, d = 0;
	if(root) for(x = root; x; x = nd[x].c[d]) if(d = v > x[nd].v) up(r, nd[x].v); // too little
	return r;
}

int succ(int v){
	int x = 0, r = INT_MAX, d = 0;
	if(root) for(x = root; x; x = nd[x].c[d]) if(!(d = v >= x[nd].v)) down(r, nd[x].v); // too large
	return r;
}
IO 优化 [#ed01]:
#define ID isdigit(c = *next++)
#define IS isspace(c = *next++)

struct Istream {
	int size; char *next, buf[20030731];
	Istream & init(FILE *f = stdin) {fread(buf, 1, sizeof buf, f); next = buf; return *this;}
	Istream & operator >> (int &x) {
		int c; x = 0;
		for (; !ID; ) if (!~c) return *this;
		for (x = c & 15; ID; x = x * 10 + (c & 15));
		return *this;
	}
	Istream & operator >> (char *x) {
		int c;
		for (; IS; ) if (!~c) return *this;
		for (*x++ = c; !IS; *x++ = c) if (!~c) break;
		return *x = 0, *this;
	}
	char get() {return *next++;}
} cin;

struct Ostream {
	char *next, buf[20030731], _buf[34];
	Ostream () {next = buf;}
	void flush(FILE *f = stdout) {fwrite(buf, 1, next - buf, f); next = buf;}
	Ostream & operator << (int x) {
		if (!x) return put(48), *this;
		int i;
		for (i = 0; x; x /= 10) _buf[++i] = x % 10 | 48;
		for (; i; --i) put(_buf[i]);
		return *this;
	}
	Ostream & operator << (char c) {return put(c), *this;}
	Ostream & operator << (const char *s) {for (char *p = (char*)s; *p; ++p) put(*p); return *this;}
	void put(char c) {*next++ = c;}
} cout;
动态规划的转移 [#ed02]:
inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void add(int &x, const int y) {(x += y) >= mod ? x -= mod : 0;}
inline void sub(int &x, const int y) {(x -= y) < 0 ? x += mod : 0;}
乘模函数 (64 bit 大整数相乘取模) [#ed03]:
inline ll MulMod(ll a, ll b, ll m){
	ll t = (a * b - (ll)((ld)a * b / m) * m) % m;
	return t + (t >> 63 & m);
}
ST 表 [#ed04]:
#define lg2(x) (31 - __builtin_clz(x)) // if (__builtin_clz(x)) is can't be used, you can implement it in a table

void build_st_table() {
	int *f, *g = *st, i, j, k = cnt;
	for (j = 0; 1 << j + 1 <= cnt; ++j) {
		f = g; g = st[j + 1]; k -= 1 << j;
		for (i = 0; i < k; ++i)
			g[i] = min(f[i], f[i + (1 << j)]);
	}
}

inline int range(int L, int R){ // [L, R)
	int D = R - L, c = lg2(D);
	return min(st[c][L], st[c][R - (1 << c)]);
}
离散化 [#ed05]:
namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}
Hash Map [#ed06]:
class hash_map{
public:
	static const int HASH_MAX = 0xffffff, N = 8000000;
	int cnt, first[HASH_MAX + 2], next[N]; data z[N];
	inline int getHash(int key) {return (key ^ key << 3 ^ key >> 2) & HASH_MAX;}

	void clear() {for(; cnt > 0; --cnt) first[z[cnt].hash] = 0;}

	data * find(int key, bool inserted){
		int x = getHash(key), i;
		for(i = first[x]; i; i = next[i]) if(z[i].key == key) return z + i;
		if(!inserted) return NULL;
		z[++cnt] = data(key, 0, x); next[cnt] = first[x]; first[x] = cnt;
		return z + cnt;
	}
};
快速 Fourier 变换 (Fast Fourier Transform) [#ed07]:
// 'Fast Number Theory Transform' is in memos/12.html.
namespace Poly {
	typedef std::complex <double> C;

	const int N = 530000;
	int l, n, rev[N];
	C x[N], y[N], B1[N], B2[N], B3[N];

	void FFT_init(int len) {
		if (l == len) return; n = 1 << (l = len);
		int i; double angle = M_PI;
		for (i = l - 1; i >= 0; angle *= .5, --i) x[1 << i] = C(cos(angle), sin(angle));
		for (i = 3; i < n; ++i) if (i & (i - 1)) x[i] = x[i & -i] * x[i ^ (i & -i)];
		*x = C(1.), *rev = 0;
		for (i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DFT(C *d, C *t) {
		int i, len = 1, delta = n; C *j, *k, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = y[k - j] * k[len], k[len] = *k - R, *k += R;
			len <<= 1;
		}
	}

	void Mul(int degA, int degB, double *a, double *b, double *c) {
		if (!(degA || degB)) {*c = *a * *b; return;}
		FFT_init(lg2(degA + degB) + 1);
		int i; double iv = 1.0 / n;
		for (i = 0; i <= degA; ++i) B1[i] = C(a[i]); std::fill(B1 + i, B1 + n, C());
		for (i = 0; i <= degB; ++i) B2[i] = C(b[i]); std::fill(B2 + i, B2 + n, C());
		DFT(B1, B3), DFT(B2, B1);
		for (i = 0; i < n; ++i) B1[i] *= B3[i];
		DFT(B1, B3), std::reverse(B3 + 1, B3 + n);
		for (i = 0; i <= degA + degB; ++i) c[i] = B3[i].real() * iv;
	}
}
Gauss 消元法 [#ed08]:
// Gauss elimination with type 'double'
struct LnEqn{
	int sz;
	double **m, *b;
	LnEqn (): sz(0) {m = NULL; b = NULL;}
	void resize(int size){
		sz = size; m = new double *[sz];
		for(int i = 0; i < sz; i++){
			m[i] = new double[sz];
			memset(m[i], 0, sz << 3);
		}
		b = new double[sz];
		memset(b, 0, sz << 3);
	}
	~LnEqn (){
		if(m) {for(int i = 0; i < sz; i++) delete [] (m[i]); delete [] (m);}
		if(b) delete [] (b);
	}
	bool solve(){
		int i, j, k, maxi; double coe;
		for(k = 0; k < sz; k++){
			maxi = k;
			for(i = k + 1; i < sz; i++)
				if(fabs(m[i][k]) > fabs(m[maxi][k]))
					maxi = i;
			if(fabs(m[maxi][k]) < 1e-8) return false;
			if(maxi != k){
				swap(m[maxi], m[k]);
				swap(b[maxi], b[k]);
			}
			coe = 1.0 / m[k][k];
			for(j = 0; j < sz; j++)
				m[k][j] *= coe;
			m[k][k] = 1.0;
			b[k] *= coe;
			for(i = 0; i < sz; i++){
				if(i == k) continue;
				coe = m[i][k];
				for(j = 0; j < sz; j++)
					m[i][j] -= coe * m[k][j];
				m[i][k] = 0.0;
				b[i] -= coe * b[k];
			}
		}
		return true;
	}
};
线性规划 (xₚ ≥ 0, bₚ ≥ 0) [#ed09]:
const double eps = 1e-8;

int id[N + E];

double m[E][N], b[E], *c = m[0], ans[N + E];

void pivot(int toFree, int toBasic); // basic(1,m) -> free, free(1,n) -> basic

void pivot(int r, int c){
	int i, j; double coe = 1.0 / m[r][c];
	swap(id[n + r], id[c]);
	m[r][c] = 1.0;
	for(j = 1; j <= n; ++j)
		m[r][j] *= coe;
	b[r] *= coe;
	for(i = 0; i <= e; ++i){
		if(i == r) continue;
		coe = m[i][c]; m[i][c] = 0.0;
		for(j = 1; j <= n; ++j)
			m[i][j] -= coe * m[r][j];
		b[i] -= coe * b[r];
	}
}

bool simplex(){
	int i, j, basic, free; double G;
	for(; ; ){
		basic = free = 0; G = INFINITY;
		for(i = 1; i <= n; ++i) // free (nonbasic) variable
			if(c[i] > c[free]) free = i;
		if(!free) return true;
		for(j = 1; j <= e; ++j) // basic variable
			if(m[j][free] > eps && b[j] < G * m[j][free]){
				G = b[j] / m[j][free]; basic = j;
			}
		if(!basic) return puts("Unbounded"), false;
		pivot(basic, free);
	}
}

// initialize :
for(j = 1; j <= n + e; ++j) id[j] = j;
c[0] = eps;

// output:
if(simplex()){
	printf("%.8lg\n", -*b);
	for(i = 1; i <= e; ++i) ans[id[n + i]] = b[i];
	for(j = 1; j <= n; ++j) printf("%.8lg%c", ans[j], j == n ? 10 : 32);
}
Gauss 消元求行列式 (模意义) [#ed10]:
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
二维向量/点、计算几何基础 [#cg01]:
const double eps = 1e-8;

#define lt(x, y) ((x) < (y) - eps)
#define gt(x, y) ((x) > (y) + eps)
#define le(x, y) ((x) <= (y) + eps)
#define ge(x, y) ((x) >= (y) - eps)
#define eq(x, y) (le(x, y) && ge(x, y))
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

struct vec2 {
	double x, y;
	vec2 (double x0 = 0.0, double y0 = 0.0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%lf%lf", &x, &y); return this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline vec2 operator * (double k) const {return vec2(x * k, y * k);}
	inline vec2 operator / (double k) const {return *this * (1.0 / k);}
	inline double operator * (const vec2 &B) const {return x * B.x + y * B.y;}
	inline double operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline double norm2() const {return x * x + y * y;}
	inline double norm() const {return sqrt(x * x + y * y);}
	inline bool operator < (const vec2 &B) const {return lt(x, B.x) || le(x, B.x) && lt(y, B.y);}
	inline bool operator == (const vec2 &B) const {return eq(x, B.x) && eq(y, B.y);}
	inline bool operator << (const vec2 &B) const {return lt(y, 0) ^ lt(B.y, 0) ? lt(B.y, 0) : gt(*this ^ B, 0) || ge(*this ^ B, 0) && ge(x, 0) && lt(B.x, 0);}
	inline vec2 trans(double a11, double a12, double a21, double a22) const {return vec2(x * a11 + y * a12, x * a21 + y * a22);}
};

/*
operator * : Dot product
operator ^ : Cross product
norm2() : |v|^2 = v.v
norm() : |v| = sqrt(v.v)
operator < : Two-key compare
operator << : Polar angle compare
trans : Transition with a 2x2 matrix
*/
直线及其函数 [#cg02]:
struct line {
	double A, B, C; // Ax + By + C = 0, > 0 if it represents halfplane.
	line (double A0 = 0.0, double B0 = 0.0, double C0 = 0.0) : A(A0), B(B0), C(C0) {}
	line (const vec2 &u, const vec2 &v) : A(u.y - v.y), B(v.x - u.x), C(u ^ v) {} // left > 0
	inline vec2 normVec() const {return vec2(A, B);}
	inline double norm2() const {return A * A + B * B;}
	inline double operator () (const vec2 &P) const {return A * P.x + B * P.y + C;}
};

inline vec2 intersection(const line u, const line v) {
	double Det = 1.0 / (u.A * v.B - u.B * v.A);
	return vec2(u.B * v.C - u.C * v.B, u.C * v.A - u.A * v.C) * Det;
}

inline bool parallel(const line u, const line v) {double p = u.normVec() ^ v.normVec(); return eq(p, 0);}

inline bool perpendicular(const line u, const line v) {double p = u.normVec() * v.normVec(); return eq(p, 0);}

inline bool sameDir(const line u, const line v) {return parallel(u, v) && gt(u.normVec() * v.normVec(), 0);}

inline line bisector(const vec2 u, const vec2 v) {return line(v.x - u.x, v.y - u.y, 0.5 * (u.norm2() - v.norm2()));}

inline double dis2(const vec2 P, const line l) {return l(P) * l(P) / l.norm2();}

inline vec2 projection(const vec2 P, const line l) {return P - l.normVec() * (l(P) / l.norm2());}

inline vec2 symmetry(const vec2 P, const line l) {return P - l.normVec() * (2 * l(P) / l.norm2());}
多边形操作 [#cg03]:
// Relation of 3 points. (2 inside, 1 outside, 0 not collinear)
inline int collinear(const vec2 u, const vec2 v, const vec2 P) {double p = cross(P, u, v); return eq(p, 0) ? 1 + le(dot(P, u, v), 0) : 0;}

// Perimeter of a polygon
double perimeter(int n, vec2 *poly) {
	double ret = (poly[n - 1] - *poly).norm();
	for (int i = 1; i < n; ++i) ret += (poly[i - 1] - poly[i]).norm();
	return ret;
}

// Directed area of a polygon (positive if CCW)
double area(int n, vec2 *poly) {
	double ret = poly[n - 1] ^ *poly;
	for (int i = 1; i < n; ++i) ret += poly[i - 1] ^ poly[i];
	return ret * 0.5;
}

// Point in polygon (2 on boundary, 1 inside, 0 outside)
int contain(int n, vec2 *poly, const vec2 P) {
	int in = 0; vec2 *r = poly + (n - 1), *u, *v;
	for (int i = 0; i < n; r = poly, ++poly, ++i) {
		if (collinear(*r, *poly, P) == 2) return 2;
		gt(r->y, poly->y) ? (u = poly, v = r) : (u = r, v = poly);
		if (ge(P.y, v->y) || lt(P.y, u->y)) continue;
		in ^= gt(cross(P, *u, *v), 0);
	}
	return in;
}
平面凸包 (Graham Scan) [#cg04]:
int graham(int n, vec2 *p, vec2 *dest) {
	int i; vec2 *ret = dest;
	std::iter_swap(p, std::min_element(p, p + n));
	std::sort(p + 1, p + n, [p] (const vec2 A, const vec2 B) {double r = cross(*p, A, B); return gt(r, 0) || (ge(r, 0) && lt(A.norm2(), B.norm2()));});
	for (i = 0; i < 2 && i < n; ++i) *ret++ = p[i];
	for (; i < n; *ret++ = p[i++])
		for (; ret != dest + 1 && ge(cross(ret[-2], p[i], ret[-1]), 0); --ret);
	return *ret = *p, ret - dest;
}
旋转卡壳求凸集直径 [#cg05]:
double convDiameter(int n, vec2 *poly) {
	int l = std::min_element(poly, poly + n) - poly, r = std::max_element(poly, poly + n) - poly, i = l, j = r;
	double diam = (poly[l] - poly[r]).norm2();
	do {
		(ge(poly[(i + 1) % n] - poly[i] ^ poly[(j + 1) % n] - poly[j], 0) ? ++j : ++i) %= n;
		up(diam, (poly[i] - poly[j]).norm2());
	} while (i != l || j != r);
	return diam;
}
三角形外心 & 最小圆覆盖 [#cg06]:
inline vec2 circumCenter(const vec2 A, const vec2 B, const vec2 C) {
	vec2 a = B - A, b = C - A, AO;
	double det = 0.5 / (a ^ b), na = a.norm2(), nb = b.norm2();
	AO = vec2((na * b.y - nb * a.y) * det, (nb * a.x - na * b.x) * det);
	return A + AO;
}

double minCircleCover(int n, vec2 *p, vec2 *ret = NULL) {
	int i, j, k; double r2 = 0.0;
	std::random_shuffle(p + 1, p + (n + 1));
	vec2 C = p[1];
	for (i = 2; i <= n; ++i)
		if (gt((p[i] - C).norm2(), r2))
			for (C = p[i], r2 = 0, j = 1; j < i; ++j)
				if (gt((p[j] - C).norm2(), r2))
					for (C = (p[i] + p[j]) * 0.5, r2 = (p[j] - C).norm2(), k = 1; k < j; ++k)
						if (gt((p[k] - C).norm2(), r2))
							C = circumCenter(p[i], p[j], p[k]), r2 = (p[k] - C).norm2();
	return ret ? *ret = C : 0, r2;
}
半平面交 (平行处理版) [#cg07]:
inline bool HPIcmp(const line u, const line v) {return sameDir(u, v) ? gt((fabs(u.A) + fabs(u.B)) * v.C, (fabs(v.A) + fabs(v.B)) * u.C) : u.normVec() << v.normVec();}

inline bool geStraight(const vec2 A, const vec2 B) {return lt(A ^ B, 0) || le(A ^ B, 0) && lt(A * B, 0);}

inline bool para_nega_test(const line u, const line v) {
	return parallel(u, v) && lt(u.normVec() * v.normVec(), 0) && (fabs(u.A) + fabs(u.B)) * v.C + (fabs(v.A) + fabs(v.B)) * u.C < -7e-14;
}

int HPI(int n, line *l, vec2 *poly, vec2 *&ret) { // -1 : Unbounded, -2 : Infeasible
	int h = 0, t = -1, i, j, que[n + 5];
	std::sort(l, l + n, HPIcmp);
	n = std::unique(l, l + n, sameDir) - l;
	for (j = i = 0; i < n && j < n; ++i) {
		for (up(j, i + 1); j < n && !geStraight(l[i].normVec(), l[j].normVec()); ++j);
		if (para_nega_test(l[i], l[j])) return -2;
	}
	if (n <= 2 || geStraight(l[n - 1].normVec(), l->normVec())) return -1;
	for (i = 0; i < n; ++i) {
		if (geStraight(l[que[t]].normVec(), l[i].normVec())) return -1;
		for (; h < t && le(l[i](poly[t - 1]), 0); --t);
		for (; h < t && le(l[i](poly[h]), 0); ++h);
		que[++t] = i; h < t ? poly[t - 1] = intersection(l[ que[t - 1] ], l[ que[t] ]) : 0;
	}
	for (; h < t && le(l[ que[h] ](poly[t - 1]), 0); --t);
	return h == t ? -2 : (poly[t] = intersection(l[ que[t] ], l[ que[h] ]), ret = poly + h, t - h + 1);
}
平面上的圆几何 [#cg08]:
inline double angle(const vec2 u, const vec2 v) {return atan2(u ^ v, u * v);}

// intersection of circle and line
void intersection(double r2, const vec2 O, const line l, vec2 *ret) {
	double d2 = dis2(O, l); vec2 j = l.normVec();
	if (gt(d2, r2)) {ret[0] = ret[1] = vec2(INFINITY, INFINITY); return;}
	if (ge(d2, r2)) {ret[0] = ret[1] = projection(O, l); return;}
	if (le(d2, 0)) {
		j = j * sqrt(r2 / j.norm2());
		ret[0] = O + j.trans(0, -1, 1, 0);
		ret[1] = O + j.trans(0, 1, -1, 0);
	} else {
		double T = copysign(sqrt((r2 - d2) / d2), l(O)); j = j * (-l(O) / j.norm2());
		ret[0] = O + j.trans(1, T, -T, 1);
		ret[1] = O + j.trans(1, -T, T, 1);
	}
}

// area of intersection(x^2 + y^2 = r^2, triangle OBC)
double interArea(double r2, const vec2 B, const vec2 C) {
	if (eq(B ^ C, 0)) return 0;
	vec2 is[2]; intersection(r2, vec2(), line(B, C), is);
	if (!std::isfinite(is->x)) return 0.5 * r2 * angle(B, C);
	bool b = gt(B.norm2(), r2), c = gt(C.norm2(), r2);
	if (b && c) return 0.5 * (lt(dot(*is, B, C), 0) ? r2 * (angle(B, *is) + angle(is[1], C)) + (is[0] ^ is[1]) : r2 * angle(B, C));
	else if (b) return 0.5 * (r2 * angle(B, *is) + (*is ^ C));
	else if (c) return 0.5 * ((B ^ is[1]) + r2 * angle(is[1], C));
	else return 0.5 * (B ^ C);
}
三维计算几何基础 [#cg09]:
#define triple(x, y, z) ((x) * ((y) ^ (z)))

struct vec3 {
	double x, y, z;
	vec3 (double x0 = 0, double y0 = 0, double z0 = 0) : x(x0), y(y0), z(z0) {}
	vec3 * read() {scanf("%lf%lf%lf", &x, &y, &z); return this;}
	inline vec3 operator - () const {return vec3(-x, -y, -z);}
	inline vec3 operator + (const vec3 &B) const {return vec3(x + B.x, y + B.y, z + B.z);}
	inline vec3 operator - (const vec3 &B) const {return vec3(x - B.x, y - B.y, z - B.z);}
	inline vec3 operator * (double k) const {return vec3(x * k, y * k);}
	inline vec3 operator / (double k) const {return *this * (1.0 / k);}
	inline double operator * (const vec3 &B) const {return x * B.x + y * B.y + z * B.z;}
	inline vec3 operator ^ (const vec3 &B) const {return vec3(y * B.z - z * B.y, z * B.x - x * B.z, x * B.y - y * B.x);}
	inline double norm2() const {return x * x + y * y + z * z;}
	inline double norm() const {return sqrt(x * x + y * y + z * z);}
	inline bool operator < (const vec3 &B) const {return lt(x, B.x) || le(x, B.x) && (lt(y, B.y) || le(y, B.y) && lt(z, B.z));}
	inline bool operator == (const vec3 &B) const {return eq(x, B.x) && eq(y, B.y) && eq(z, B.z);}
};

// Positive if Right-hand rule
inline double volume(const vec3 A, const vec3 B, const vec3 C, const vec3 D) {return triple(B - A, C - A, D - A);}

struct line3 {
	vec3 P, t;
	line3 (vec3 _P = vec3(), vec3 _t = vec3()) : P(_P), t(_t) {}
};

inline double dis2(const vec3 P, const line3 l) {return ((P - l.P) ^ l.t).norm2() / l.t.norm2();}

struct plane {
	double A, B, C, D; // Ax + By + Cz + D = 0
	plane (double A0 = 0.0, double B0 = 0.0, double C0 = 0.0, double D0 = 0.0) : A(A0), B(B0), C(C0), D(D0) {}
	plane (const vec3 &u, const vec3 &v, const vec3 &w) {vec3 t = (v - u) ^ (w - u); A = t.x, B = t.y, C = t.z, D = -triple(u, v, w);} // > 0 if it follows Right-hand rule
	inline vec3 normVec() const {return vec3(A, B, C);}
	inline double norm2() const {return A * A + B * B + C * C;}
	inline double operator () (const vec3 &P) const {return A * P.x + B * P.y + C * P.z + D;}
};

inline double dis2(const vec3 P, const plane F) {return F(P) * F(P) / F.norm2();}
三维凸包 (卷包裹法) [#cg10]:
namespace CH3D {
	typedef std::pair <int, int> pr;
	typedef std::set <pr> set;

	struct triangle {vec3 A, B, C;} tr[N];

	vec3 p[N], q[N], r[N];
	set E;
	int n, cnt;

	inline vec3 randvec3() {return vec3((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);}

	void wrap(int u, int v) {
		if (E.find({u, v}) == E.end()) {
			int i, w = -1;
			for (i = 0; i < n; ++i)
				if (i != u && i != v && (!~w || ge(volume(q[w], q[u], q[v], q[i]), 0))) w = i;
			if (~w) {
				tr[cnt++] = (triangle){p[u], p[v], p[w]};
				E.emplace(u, v); E.emplace(v, w); E.emplace(w, u);
				wrap(w, v); wrap(u, w);
			}
		}
	}

	void main(int _n, vec3 *_p) {
		int i;
		n = _n; cnt = 0; E.clear();
		memcpy(p, _p, n * sizeof(vec3));
		std::iter_swap(p, std::min_element(p, p + n));
		for (i = 0; i < n; ++i) q[i] = p[i] + randvec3() * 1e-6;
		for (i = 2; i < n; ++i)
			if (ge(cross(q[0], q[i], q[1]).z, 0)) std::swap(p[1], p[i]), std::swap(q[1], q[i]);
		wrap(0, 1);
	}
}
自适应 Simpson 积分 [#cg11]:
double Simpson(double L, double M, double R, double fL, double fM, double fR, double eps) {
	double LM = (L + M) * 0.5, fLM = f(LM), MR = (M + R) * 0.5, fMR = f(MR);
	double A = (fL + fM * 4.0 + fR) * (R - L) * sixth,
		   AL = (fL + fLM * 4.0 + fM) * (M - L) * sixth,
		   AR = (fM + fMR * 4.0 + fR) * (R - M) * sixth;
	if (fabs(AL + AR - A) < eps) return (2.0 * (AL + AR) + A) * third;
	return Simpson(L, LM, M, fL, fLM, fM, eps * 0.6) + Simpson(M, MR, R, fM, fMR, fR, eps * 0.6);
}