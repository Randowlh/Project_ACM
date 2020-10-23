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
vector<int> mp[310000],mp2[310000];
int  dd[310000];
int  date[310000];
int flag[310000];
int too[310000];
set<int> s;
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>date[i];
        int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t==-1)
            continue;
        mp2[t].push_back(i);
        mp[i].push_back(t);
        dd[t]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!dd[i])
            q.push(i);
    }
    vector<int> ans;
    int tt=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(date[t]<0){
            if(!mp[t].empty()){
                dd[mp[t][0]]--;
                if(!dd[mp[t][0]])
                    q.push(mp[t][0]);
            }
            continue;
        }
        tt+=date[t];
        ans.push_back(t);
        flag[t]=1;
        for(int i=0;i<mp[t].size();i++){
            dd[mp[t][i]]--;
            date[mp[t][i]]+=date[t];
            if(!dd[mp[t][i]])
                q.push(mp[t][i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(date[i]<0&&(mp[i].empty()||flag[mp[i][0]]))
            q.push(i);
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        flag[t]=1;
        tt+=date[t];
        ans.push_back(t);
        for(int i=0;i<mp2[t].size();i++){
            if(!flag[mp2[t][i]])
            q.push(mp2[t][i]);
        }
    }
    cout<<tt<<endl;
    for(int i=0;i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    
    cout<<endl;

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