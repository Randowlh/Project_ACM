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
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
struct Edges{
    int w,to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
void add(int u,int v,int w){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    edge[ecnt].w=w;
    head[u]=ecnt;
}
const int maxn = 1e5+5;
const double alpha = 0.75;
struct Node
{
    int l,r,val;
    int size,fact;
    bool exist;
}tzy[maxn];
int cnt,root;
void newnode(int &now,int val)
{
    now=++cnt;
    tzy[now].val=val;
    tzy[now].size=tzy[now].fact=1;
    tzy[now].exist=true;
}
bool imbalence(int now)
{
    if(std::max(tzy[tzy[now].l].size,tzy[tzy[now].r].size)>tzy[now].size*alpha
       ||tzy[now].size-tzy[now].fact>tzy[now].size*0.3)
        return true;
    return false;
}
#include <vector>
vector<int> v;
void ldr(int now)
{
    if(!now) return;
    ldr(tzy[now].l);
    if(tzy[now].exist)
        v.push_back(now);
    ldr(tzy[now].r);
}
void lift(int l,int r,int &now)
{
    if(l==r)
    {
        now=v[l];
        tzy[now].l=tzy[now].r=0;
        tzy[now].size=tzy[now].fact=1;
        return;
    }
    int m = (l+r)>>1;
    while(l<m&&tzy[v[m]].val==tzy[v[m-1]].val)
        m--;
    now = v[m];
    if(l<m) lift(l,m-1,tzy[now].l);
    else tzy[now].l=0;
    lift(m+1,r,tzy[now].r);
    tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
    tzy[now].fact=tzy[tzy[now].l].fact+tzy[tzy[now].r].fact+1;
}
void rebuild(int &now)
{
    v.clear();
    ldr(now);
    if(v.empty())
    {
        now=0;
        return;
    }
    lift(0,v.size()-1,now);
}
void update(int now,int end)
{
    if(!now) return;
    if(tzy[end].val<tzy[now].val)
        update(tzy[now].l,end);
    else update(tzy[now].r,end);
    tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
}
void check(int &now,int end)
{
    if(now==end) return;
    if(imbalence(now))
    {
        rebuild(now);
        update(root,now);
        return;
    }
    if(tzy[end].val<tzy[now].val)
        check(tzy[now].l,end);
    else check(tzy[now].r,end);
}
void ins(int &now,int val)
{
    if(!now)
    {
        newnode(now,val);
        check(root,now);
        return;
    }
    tzy[now].size++;
    tzy[now].fact++;
    if(val<tzy[now].val)
        ins(tzy[now].l,val);
    else ins(tzy[now].r,val);
}
void del(int now,int val)
{
    if(tzy[now].exist&&tzy[now].val==val)
    {
        tzy[now].exist=false;
        tzy[now].fact--;
        check(root,now);
        return;
    }
    tzy[now].fact--;
    if(val<tzy[now].val)
        del(tzy[now].l,val);
    else del(tzy[now].r,val);
}
int getrank(int val)
{
    int now=root,rank=1;
    while(now)
    {
        if(val<=tzy[now].val)
            now=tzy[now].l;
        else 
        {
            rank+=tzy[now].exist+tzy[tzy[now].l].fact;
            now=tzy[now].r;
        }
    }
    return rank;
}
int getnum(int rank)
{
    int now=root;
    while(now)
    {
        if(tzy[now].exist&&tzy[tzy[now].l].fact+tzy[now].exist==rank)
            break;
        else if(tzy[tzy[now].l].fact>=rank)
            now=tzy[now].l;
        else 
        {
            rank-=tzy[tzy[now].l].fact+tzy[now].exist;
            now=tzy[now].r;
        }
    }
    return tzy[now].val;
}
int dp[220][220][220];
int datea[1100],dateb[1100],datec[1100];
bool ck(int a,int b,int c){
    if(a<0)
    return false;
    if(b<0)
    return false;
    if(c<0)
    return false;
    return true;
}
int dfs(int a,int b,int c){
    int ans=0;
    if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    if(a&&b)
        ans=max(datea[a]*dateb[b]+dfs(a-1,b-1,c),ans);
    if(a&&c)
        ans=max(datea[a]*datec[c]+dfs(a-1,b,c-1),ans);
    if(b&&c)
        ans=max(dateb[b]*datec[c]+dfs(a,b-1,c-1),ans);
    dp[a][b][c]=ans;
    return ans;
}
void work()
{
    memset(dp,-1,sizeof(dp));
    int a,b,c;
    cin>>a>>b>>c;    
    for(int i=1;i<=a;i++)
        cin>>datea[i];
    for(int i=1;i<=b;i++)
        cin>>dateb[i];
    for(int i=1;i<=c;i++)
        cin>>datec[i];
    sort(datea+1,datea+a+1);
    sort(dateb+1,dateb+b+1);
    sort(datec+1,datec+c+1);
    int ans=dfs(a,b,c);
    cout<<ans<<endl;
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