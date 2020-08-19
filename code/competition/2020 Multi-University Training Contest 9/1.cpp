#include <bits/stdc++.h>
#pragma GCC optimize(2)
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 210000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
#define lowbit(x) (x&-x);
int n;
int date[maxn];
vector<int> root;
struct chair_man_tree{
    struct node{
        int v;
        int lson,rson;
    }tree[maxn<<5];
    int tail=0;
    int addnew(int now){
        tail++;
        tree[tail]=tree[now];
        return  tail;
    }
    int build(int l,int r){
        int now=tail++;
        if(l==r){
            tree[now].v=date[l];
            tree[now].lson=tree[now].rson=-1;
            return now;
        }
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int update(int pos,int l,int r,int x,int val){
        int now=addnew(pos);
        if(l==r){
            tree[now].v=val;
            return now;
        }
        int mid=(l+r)>>1;
        if(x<=mid)
            tree[now].lson=update(tree[now].lson,l,mid,x,val);
        if(x>mid)
            tree[now].rson=update(tree[now].rson,mid+1,r,x,val);
        return now;
    }
    int query(int pos,int l,int r,int x){
        if(l==r)
            return tree[pos].v;
        int  mid=(l+r)>>1;
        if(x<=mid)
            return query(tree[pos].lson,l,mid,x);
        else return query(tree[pos].rson,mid+1,r,x);
    }
} arr;
class seg_tree{
    #define lson(pos) (pos<<1)
    #define rson(pos) (pos<<1|1)
    struct node{
        int v;
        int lazy;
    }tree[maxn<<2];
    inline void pushup(int now){
        tree[now].v=min(tree[lson(now)].v,tree[rson(now)].v);
    }
    inline void pushdown(int now){
        if(!tree[now].lazy)
            return;
        
    }
};

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