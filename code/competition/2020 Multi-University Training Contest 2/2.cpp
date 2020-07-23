#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
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
typedef long long ll;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const int mod = (0 ? 1000000007 : 998244353);
const int mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node{
    int a, b, c, d;
    node(int aa,int bb,int cc,int dd):a(aa),b(bb),c(cc),d(dd){}
};
int aa=100, bb=100, cc=100, dd=100;
//int a[1 << 25], b[1 << 25], c[1 << 25], d[1 << 25];
int tg[51];
vector<node> arr[51];
vector<vector<node>> dg;
ll ans = 0;
void dfs(int aa,int bb,int cc,int dd,int step){
    if(step==dg.size()){
        ans = max(ans, (ll)aa * (ll)bb *(ll)cc * (ll)dd);
        return;
    }
    for (int i = 0;i<dg[i].size();i++)
        dfs(aa + dg[step][i].a, bb + dg[step][i].b, cc + dg[step][i].c, dd + dg[step][i].d, step + 1);
}
void work()
{dg.clear();
    ans = 0;
    for (int i = 0; i < 50;i++){
        arr[i].clear();
    }
    int tll = 0;
    int n, k;
    rd(n), rd(k);
    int tp, a, b, c, d;
    for (int i = 0; i < n;i++){
        rd(tp), rd(a), rd(b), rd(c),rd(d);
        arr[tp].push_back(node(a, b, c, d));
    }
    
    for (int i = 1; i <= k;i++){
        if(!arr[i].size())
        continue;
        if(arr[i].size()==1){
            aa+=arr[i][0].a,bb+=arr[i][0].b,cc+=arr[i][0].c,dd+=arr[i][0].d;
            continue;
        }
        dg.push_back(arr[i]);
    }
    dfs(aa, bb, cc, dd, 0);
    printf("%lld\n", ans);
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
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}