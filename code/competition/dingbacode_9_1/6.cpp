#include <bits/stdc++.h>
using namespace std;
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
struct seg{
	#define rson(pos) (pos<<1|1)
	#define lson(pos) (pos<<1)
	int T[2010000];
	inline void pushup(int pos){
		MAX(T[pos],T[lson(pos)]);
		MAX(T[pos],T[lson(pos)]);
	}
	void update(int pos,int l,int r,int x,int val){
		if(l==r){
			T[pos]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)
			update(lson(pos),l,mid,x,val);
		else update(rson(pos),mid+1,r,x,val);
		pushup(pos);
	}
	int query(int pos,int l,int r,int ql,int qr){
		if(ql>=l&&qr<=r){
			return T[pos];
		}
		int ans=-llinf;
		int mid=(l+r)>>1;
		if(ql<=mid)
			MIN(ans,query(lson(pos),l,mid,ql,mid));
		if(qr>=mid+1)
			MIN(ans,query(rson(pos),mid+1,r,mid+1,qr));
	}
}a;
void work()
{
	
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}