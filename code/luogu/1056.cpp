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
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this

#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
pair<int,int> h[1100],s[1100];
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first; 
}
void work()
{
    int m,n,k,l,d;
    rd(m),rd(n),rd(k),rd(l),rd(d);
    int x1,y1,x2, y2;
    for(int i=0;i<=max(m,n);i++)
        s[i].second=i;
    for(int j=0;j<=max(n,m);j++)
        h[j].second=j;
    for(int i=0;i<d;i++){
        rd(x1),rd(y1),rd(x2),rd(y2);
        if(abs(x1-x2)){
            s[min(x1,x2)].first++;
            //cout<<"h[i]"<<min(x1,x2)<<endl;
        }else{
            h[min(y1,y2)].first++;
         //   cout<<"s[i]"<<min(y1,y2)<<endl;
        }
        //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    }
    sort(h+1,h+m+1,cmp);
    // for(int i=1;i<=m;i++)
    //     cout<<h[i].first<<' '<<h[i].second<<endl;
    sort(s+1,s+n+1,cmp);
    vector<int> ans;
    for(int i=1;i<=min(k,n-1);i++){
        ans.push_back(s[i].second);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    putchar('\n');
    ans.clear();
    for(int i=1;i<=min(l,m-1);i++){
        ans.push_back(h[i].second);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    putchar('\n');
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