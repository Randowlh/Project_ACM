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
pair<int,int> date[110000];
bool flag[110000];
map<int,set<int>> M;
void work()
{
    M.clear();
    int n;
    rd(n);
    int ans=0;
    for(int i=1;i<=n;i++)
        rd(date[i].first),rd(date[i].second);
    sort(date+1,date+n+1,greater<pair<int,int>>());
    for(int i=1;i<=n;i++){
        M[date[i].first-date[i].second].insert(i);
        M[date[i].second+date[i].first].insert(i);
        flag[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(flag[i])
        continue;
        if(M[date[i].first+date[i].second].size()>=M[date[i].first-date[i].second].size()){
            set<int> &t=M[date[i].first+date[i].second];
            for(auto j=t.begin();j!=t.end();j++){
                flag[*j]=1;
                M[date[*j].first-date[*j].second].erase(*j);
            }
        }else{
            set<int> &t=M[date[i].first-date[i].second];
            for(auto j=t.begin(); j != t.end();j++){
                flag[*j]=1;
                M[date[*j].first+date[*j].second].erase(*j);
            }
        }
        ans++;
    }
    printf("%lld\n",ans);
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
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}