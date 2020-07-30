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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline int gcd(int a, int b){ return b ? gcd(b, a % b) : a;}
char lt[maxn];
vector<int> mp[maxn];
bool ans[maxn];
int n,m;
int sz[maxn],hson[maxn],depth[maxn];
int cnt[30];
void init(int now){
    sz[now]=1,hson[now]=-1;
    int mx=0;
    for(int i=0;i<mp[now].size();i++){
        init(mp[now][i]);
        sz[now]+=sz[mp[now][i]];
        if(mx<sz[mp[now][i]])
        mx=sz[mp[now][i]],hson[now]=mp[now][i];
    }
}
void dfs(int now,int v){
    cnt[lt[now]-'a']+=v;
    for(int i=0;i<mp[now].size();i++)
        dfs(mp[now][i],v);
}
void solve(int x,int op,int d){
    for(int i=0;i<mp[x].size();i++)
        solve(mp[x][i],mp[x][i]!=hson[x]);
    cnt[lt[x]-'a']++;
    for(int i=0;i<mp[x].size();i++)
        if(mp[x][i]!=hson[x])
        dfs(mp[x][i],1);
    int flag=0;
    for(int i=0;i<26;i++)
        if(cnt[i]&1)flag++;
    if(flag>1) ans[x]=false;else ans[x]=true;
    if(op){
        cnt[lt[x]-'a']--;
        for(int i=0;i<mp[x].size();i++)
        dfs(mp[x][i],-1);
    }
}
void work()
{
    rd(n),rd(m);
    int tmp;
    for(int i=2;i<=n;i++)
        rd(tmp),mp[tmp].push_back(i);
    scanf("%s",lt+1);
    dfs(1,0,1);
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