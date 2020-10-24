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
int n;
double date[1100][1100];
bool guass(int n){
    for(int i=1;i<=n;i++){
        int mix=-1;
        for(int j=i;j<=n;j++)
            if(date[j][i]!=0){
                mix=j;break;
            }
        if(mix==-1)
            return false;
        if(mix!=i)
            for(int j=1;j<=n+1;j++)
                swap(date[mix][j],date[i][j]);
        double t=date[i][i];
        for(int j=i;j<=n+1;j++){
            date[i][j]=date[i][j]/t;
        }
        for(int j=1;j<=n;j++){
            if(date[j][i]==0||j==i)
                continue;
            double g=date[j][i]/date[i][i];
            for(int k=1;k<=n+1;k++)
                date[j][k]-=date[i][k]*g;
        }
    }                                                                         
    return true;
}
void work()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
        cin>>date[i][j];
    if(guass(n)){
        for(int i=1;i<=n;i++){
            printf("%.2f ",date[i][n+1]/date[i][i]);
        }
        printf("\n"); 
    }
    else printf("Multiple Solution\n");
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