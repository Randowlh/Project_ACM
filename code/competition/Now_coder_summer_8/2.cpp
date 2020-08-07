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
const double delta=0.993;
#define MAX_TIME 940 
//mt19937 myrand(time(0));
//uniform_int_distribution<int> randint {-down, up};
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int b[][2]={{1, -2}, {-1, 2}, {2, 1}, {-2, -1}};
int biao[][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char mp[1000][100];
int cnt=0;
int n,m;
bool ck(int x, int y){
    if(x<0||x>=n)
        return  false;
    if(y<0||y>=n)
        return false;
    return mp[x][y]!='*';
}
void work()
{
    int flag=0;
    cnt++;
    rd(n), rd(m);
    if(n>m)
    swap(n,m),flag=1;
    if(n==1&&m==1){
        printf("Case #%lld: %lld\n",cnt,1);
        printf("*\n");
        return;
    }
    int f=0;
    memset(mp,'.',sizeof(mp));
    int ans2=1;
    queue<pair<int,int>> q; 
    mp[1][2]='*';
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ck(t.first+ b[i][0],t.second+ b[i][1])){
                ans2++;
                mp[t.first+b[i][0]][t.second+b[i][1]]='*';
                q.push(make_pair(t.first+b[i][0],t.second+b[i][1]));
            }
        }
    }
    printf("Case #%lld: %lld\n",cnt,ans2);
    for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++)
    printf("%c",mp[i][j]);
    puts("");
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
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}