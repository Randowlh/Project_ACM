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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int ht[110000];
int book[110000];
vector<int> mp[110000];
pair<int, int> pnt[110000];
int ans = 0;
int now = 0;
void bfs(int x){
    now++;
    int ma = 0;
    queue<int> q;
    q.push(x);
    book[x] = now;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for (int i = 0;i<mp[t].size();i++){
            if(book[mp[t][i]]!=now){
                if(book[mp[t][i]]){
                    ma = max(ht[mp[t][i]], ma);
                }else if(ht[t]>=ht[mp[t][i]]){
                    book[mp[t][i]]=now;
                    q.push(mp[t][i]);
                }
            }
        }
    }
    ans += ht[x] - ma;
}
void work()
{
    int n,m;
    rd(n), rd(m);
    mp[0].clear();
    for (int i = 1; i <= n;i++){
        rd(ht[i]);
        pnt[i].first = ht[i];
        pnt[i].second = i;
        book[i] = 0;
        mp[i].clear();
    }
    ans = 0;
    now = 0;
    sort(pnt + 1, pnt + n + 1,greater<pair<int,int>>());
    int u, v;
    for (int i = 0; i < m;i++){
        rd(u), rd(v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for (int i = 1; i <= n;i++)
        if(!book[pnt[i].second])
            bfs(pnt[i].second);
    printf("%lld\n", ans);
}
signed main()
{
//    freopen("in.txt", "r", stdin);
#ifndef ONLINE_JUDGE
   freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
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