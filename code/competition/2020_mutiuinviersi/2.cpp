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
inline int gcd(int a,int b){ return b ? gcd(b, a % b) : a; }
inline int lcm(int a,int b){ return a / gcd(a, b)*b;}
struct node{
    int zi,mu;
    node(int a=0,int b=1):zi(a),mu(b){}
    inline node huajian(node ans){
        int t=gcd(abs(ans.zi),abs(ans.mu));
        ans.zi/=t;
        ans.mu/=t;
        if(ans.mu<0){
        ans.mu=-ans.mu,ans.zi=-ans.zi;
        }
        return ans;
    }
    node operator+(node a){
        node ans;
        ans.mu=lcm(mu,a.mu);
        int tt=gcd(mu,a.mu);
        ans.zi=zi*(mu/tt);
        ans.zi+=a.zi*(a.mu/tt);
        return huajian(ans);
    }
    node operator-(node a){
        node ans;
        ans.mu=lcm(mu,a.mu);
        int tt=gcd(mu,a.mu);
        ans.zi=zi*(mu/tt);
        ans.zi-=a.zi*(a.mu/tt);
        return huajian(ans);
    }
    node operator/(node a){
        node ans;
        ans=*this;
        ans.zi*=a.mu;
        ans.mu*=a.zi;
        return huajian(ans);
    }
    node operator*(node a){
        node ans;
        ans=*this;
        ans.zi*=a.zi;
        ans.mu*=a.mu;
        return huajian(ans);
    }
};
int biao[][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool ck(int x,int y){
    if(gcd(x,y)>1)
    return true;
    else return false;
}
int tail=0;
vector<int> mp[1100000];
pair<int,int> pnt[1100000];
map<pair<int,int>,int> M; 
void work()
{
    M.clear();
    tail=0;
    int x,y;
    rd(x), rd(y);
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    int f=0;
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        M[t]=++tail;
        pnt[tail]=t;
        if(t.first==t.second){
            f=1;
            break;
        }
        for(int i=0;i<8;i++){
            if(ck(t.first+biao[i][0],t.second+biao[i][1])){
                pair<int,int> to=make_pair(t.first+biao[i][0],t.second+biao[i][1]);
                if(!M.count(to)){         
                    q.push(to);
            
        }
        }
        }
    }
    for(int i=1;i<=tail;i++)
        mp[i].clear();
    if(f){
        printf("0/1\n");
        return;
    }
    for(int i=1;i<=tail+1;i++){
        date[1][i]=node(1,1);
    }
    for(int i=1;i<=tail;i++){
        for(int j=0;j<8;j++){
            pair<int,int> ta=make_pair(pnt[i].first+biao[j][0],pnt[i].second+biao[j][1]);=
            if(M.count(ta)){
                mp[i].push_back(M[ta]);
            }
        }
        mp[i].push_back(i);
    }
    node ans;
    ans.mu=0;
    ans.zi=mp[1].size();
    for(int i=1;i<=tail;i++){
        ans.mu+=mp[i].size();
    }
    int tt=gcd(ans.zi,ans.mu);
    //int tt=1;
    printf("%lld/%lld\n",ans.zi/tt,ans.mu/tt);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int T = 1;
    rd(T);
    //cin>>t;
    while (T--)
    {
        work();
    }
    return 0;
}