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
#define j1 it_is_just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxn = 510000;
vector<int> root;
int n,m;
struct chair_man_tree{
    struct node{
        int l,r;
        int v;
    }tree[maxn<<5];
    int tail=0;
    inline void pushup(int pos){tree[pos].v=min(tree[tree[pos].l].v,tree[tree[pos].r].v);}
    inline int getnew(int pos){tree[++tail]=tree[pos];return tail;}
    int build(int l,int r){
        int now=++tail;
        tree[now].v=0;
        if(l==r){
            tree[now].l=tree[now].r=0;
            return now;
        }
        int mid=(l+r)>>1;
        tree[now].l=build(l,mid);
        tree[now].r=build(mid+1,r);
        return now;
    }
    int update(int pos,int l,int r,int x,int val){
        int now=getnew(pos);
        if(l==r){
            tree[now].v=val;
            return now;
        }
        int mid=(l+r)>>1;
        if(mid>=x)
            tree[now].l=update(tree[now].l,l,mid,x,val);
        else tree[now].r=update(tree[now].r,mid+1,r,x,val);
        pushup(now);
        return now;
    }
    int query(int pos,int l,int r,int val){
        if(l==r)
            return l;
        int mid=(l+r)>>1;
        if(tree[tree[pos].l].v<val)
            return query(tree[pos].l,l,mid,val);
        else return query(tree[pos].r,mid+1,r,val);
    }
}a;
void work()
{   
    rd(n),rd(m);
    root.push_back(a.build(1,n+1));
    int tmp;
    for(int i=1;i<=n;i++){
        rd(tmp);
        tmp++;
        if(tmp>n){
            root.push_back(root[root.size()-1]);
            continue;
        }
        root.push_back(a.update(root[root.size()-1],1,n+1,tmp,i));
    }
    int l,r;
    for(int i=0;i<m;i++){
        rd(l),rd(r);
        wt(a.query(root[r],1,n+1,l)-1);
        putchar('\n');
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}