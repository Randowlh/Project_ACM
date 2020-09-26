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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
int date[110000];
int tree[410000];
int lazy[410000];

inline void pushup(int pos){
    tree[pos]=max(tree[lson(pos)],tree[rson(pos)]);
}
inline void pushdown(int pos){
    if(lazy[pos]==-1)
        return;
    lazy[lson(pos)]=lazy[rson(pos)]=lazy[pos];
    tree[lson(pos)]=tree[rson(pos)]=lazy[pos];
    lazy[pos]=-1;
}
void cl(int pos,int l,int r){
    lazy[pos]=-1;
    if(l==r){
        tree[pos]=date[l];
        return;
    }
    int mid=(l+r)>>1;
    cl(lson(pos),l,mid);
    cl(rson(pos),mid+1,r);
    pushup(pos);
} 
void update(int pos,int l,int r,int ql,int qr,int v){
    if(l>=ql&&r<=qr){
        lazy[pos]=v;
        tree[pos]=v;
        return;
    }
    pushdown(pos);
    int mid=(l+r)>>1;
    if(ql<=mid)
        update(lson(pos),l,mid,ql,qr,v);
    if(qr>=mid+1)
        update(rson(pos),mid+1,r,ql,qr,v);
    pushup(pos);
}
int query(int pos,int l,int r,int ql,int qr){
    if(l>=qr&&r<=qr){
        return tree[pos];
    }
    pushdown(pos);
    int ans=-1;
    int mid=(l+r)>>1; 
    if(ql<=mid)
        MAX(ans,query(lson(pos),l,mid,ql,qr));
    if(qr>=mid)
        MAX(ans,query(rson(pos),mid+1,r,ql,qr));
    return ans;
}
void work()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    cl(1,1,n);
    int l,r;
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        update(1,1,n,l,r,0);
        cout<<tree[1]<<endl;
    }
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
cin>>t;
while (t--)
{
work();
}
return 0;
}