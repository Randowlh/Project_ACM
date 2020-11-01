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
const int maxm= 210000;
const int maxn = 210000;
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
int n;
int dis[maxn];
void dij(int a){
   for(int i=1;i<=n;i++)
      dis[i]=llinf;
   dis[a]=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
   q.push(pair<int,int>(0,a));
   while(!q.empty()){
      pair<int,int> t=q.top();
      q.pop();
      if(dis[t.second]<t.first)
         continue;
        for(int i=head[t.second];i;i = eg[i].nxt){
            int& to=eg[i].to;
            if(eg[i].w+dis[t.second]<dis[to]){
                dis[to]=eg[i].w+dis[t.second];
                q.push(make_pair(dis[to],to));
            }
        }
    }
}
int root[maxn];
int tt=0;
struct chair_man_tree{
    struct node{
        int l,r;
    } tree[maxn<<5];
    int tot=0,tot2=0;
    int fa[maxn<<2];
    int depth[maxn<<2];
    inline int getnew(int pos){
        tree[++tot]=tree[pos];
        return tot;
    }
    int build(int l,int r){
        if(l==r){
            fa[++tot2]=l;
            return tot2;
        }
        int now=++tot;
        int mid=(l+r)>>1;
        tree[now].l=build(l,mid);
        tree[now].r=build(mid+1,r);
        return now;
    }
    int update(int rt,int l,int r,int pos,int val,int dep){
        if(l==r){
            fa[++tot2]=val;
            return tot2;
        }
        int now=getnew(rt);
        int mid=(l+r)>>1;
        if(pos<=mid)
            tree[now].l=update(tree[now].l,l,mid,pos,val,dep);
        else tree[now].r=update(tree[now].r,mid+1,r,pos,val,dep);
        return now;
    }
    int query(int rt,int l,int r,int pos){
        if(l==r)
            return rt;
        int mid=(l+r)>>1;
        if(pos<=mid)
            return query(tree[rt].l,l,mid,pos);
        else return query(tree[rt].r,mid+1,r,pos);
    }
    inline int find(int rt,int l,int r,int pos){
        int t=0;
        while(true){
            t=query(rt,l,r,pos);
            if(fa[t]==pos)
                return t;
            else pos=fa[t];
        }
    }
    int merge(int rt,int a,int b){
        
    }
};
struct nn{
    int u,v;
    int h;
    bool operator < (nn a){
        return h<a.h;   
    }
}edgs[210000];
void work()
{
    int n,m;
    rd(n),rd(m);
    int u,v,w,h;
    for(int i=1;i<=n;i++){
        rd(u),rd(v),rd(w),rd(h);
        add(u,v,w);
        add(v,u,w);
        edgs[i].u=u,edgs[i].v=v,edgs[i].w=w;
    }
    sort(edgs+1,edgs+n+1);
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
rd(t);
//cin>>t;
while (t--)
{
work();
}
return 0;
}