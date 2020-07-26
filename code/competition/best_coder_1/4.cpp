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
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    pair<int,int> a;
    int n;
    rd(n);
    int ans1=-inf,ans2=-inf;
    //set<int> s1,s2;
    for(int i=0;i<n;i++){
        rd(a.second),rd(a.first);
        if(a.second==2){
            ans2=max(ans2,a.first);
        }else ans1=max(ans1,a.first);
    }
    if(ans2>=ans1){
        printf("%lld\n",ans2+2);
    }else
    if(ans2+1==ans1){
        printf("%lld\n",ans2+3);
    }else printf("%lld\n",ans1+1);

}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
   // cin.tie(NULL);
    int t = 1;
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}