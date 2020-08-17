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
#define int unsigned long long
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
int date[30][30];
void work()
{
    int  n,q;
    cin>>n;
    int one =1;
    int ans=0;
    date[1][1]=1e16;
    for(int i=2;i<=n;i++){
        date[1][i]=date[1][i-1]/3;
    }
    for(int j=2;j<=n;j++){
        for(int i=1;i<=n;i++)
        date[j][i]=date[j-1][i]/(1.5);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<date[i][j]<<" ";
        cout<<endl;
    }
    cout<<date[1][1]+date[2][1]+date[2][2]+date[2][3]+date[3][3]+date[3][4]+date[4][4]<<endl;
    cout.flush();
    cin>>q;
    double aa=0;   
    while(q--){
        cin>>aa;
        int x=1,y=1;
        double now=1e16;
        int cnt=0;
        aa-=now;
        while(cnt<=n*2-1){
           // cout<<aa<<endl;
           cout<<now/2<<endl;
           cout<<aa<<endl;
            cnt++;
            cout<<x<<' '<<y<<endl;
            if(aa>now/1.57){
                y++;
                aa-=now/1.5;
                now/=1.5;
            }else{
                cout<<"???"<<endl;
                x++;
                aa-=now/3;
                now/=3;
            }
        }
        cout.flush();
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}