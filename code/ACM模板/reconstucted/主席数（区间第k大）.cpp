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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n,m;
int date[200010];
int lsh[200010];
int root[200010];
int lk[200010];
map<int,int> rvs;
struct chair_man_tree{
    struct node{
        int v;
        int lson,rson;
    }tree[200010<<5];
    int tail=0;
    inline int addnode(int pos){
        tree[++tail]=tree[pos];
        return tail;
    }
    int build(int l,int r){
        int now=++tail;
        tree[now].v=0;
        if(l==r){
            return now;
        }
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int update(int pos,int l,int r,int x){
        int now=addnode(pos);
        tree[now].v++;
        if(l<r){
            int  mid=(l+r)>>1;
            if(x<=mid)tree[now].lson=update(tree[pos].lson,l,mid,x);
            else tree[now].rson=update(tree[pos].rson,mid+1,r,x);
        }
        return now;
    }
    int query(int u,int v,int l,int r,int k){
        if(l==r)
        return l;
        int x=tree[tree[v].lson].v-tree[tree[u].lson].v;
        int mid=(l+r)>>1;
        if(x>=k)
            return query(tree[u].lson,tree[v].lson,l,mid,k);
        else return query(tree[u].rson,tree[v].rson,mid+1,r,k-x);
    }
}a;
void work()
{ 
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
    rd(date[i]),lsh[i]=date[i];
    sort(lsh+1,lsh+ n + 1);
    int cnt=0;
    cnt=unique(lsh+1,lsh+n+1)- lsh-1;
    for(int i=1;i<=cnt;i++)
        rvs[lsh[i]]=i;
    a.build(1,cnt);
    for(int i=1;i<=n;i++){
        root[i]=a.update(root[i-1],1,cnt,rvs[date[i]]);
    }
    int ll,rr,kk;
    for(int i=0;i<m;i++){
        rd(ll), rd(rr), rd(kk);
        printf("%d\n",lsh[a.query(root[ll-1],root[rr],1,cnt,kk)]);
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}