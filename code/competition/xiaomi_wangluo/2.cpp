#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
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
void work()
{
    
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}