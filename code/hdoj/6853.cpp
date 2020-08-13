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
inline int gcd(int a,int b){return b ? gcd(b, a % b) : a;}
inline int lcm(int a,int b){return a/gcd(a,b)*b;}
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
int biao[8][2]={{1,0},{0,1},{-1,0}, {0, -1},{-1,-1},{1,1},{-1,1},{1,-1}};
set<pair<int,int>> s;
void work()
{
    s.clear();
    int x,y;
    rd(x),rd(y);
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    s.insert(make_pair(x,y));
    int f=0;
    int mu=1;
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        if(t.first==t.second){
            f=1;
            break;
        }
        for(int i=0;i<8;i++){
            if(gcd(t.first+biao[i][0],t.second+biao[i][1])>1){
                mu++;
                if(s.count(make_pair(t.first+biao[i][0],t.second+biao[i][1]))==0){
                q.push(make_pair(t.first+biao[i][0],t.second+biao[i][1]));
                s.insert(make_pair(t.first+biao[i][0],t.second+biao[i][1]));
                mu++;
                }
            }
        }
    }
    if(f){
        cout<<"0/1"<<endl;
        return;
    }
    int zi=1;
    for(int i=0;i<8;i++)
        if(gcd(x+biao[i][0], y + biao[i][1])!=1)
            zi++;
    int tt=gcd(zi,mu);
    cout<<zi/tt<<'/'<<mu/tt<<endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}