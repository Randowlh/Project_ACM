#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define pb push_back
#define rep(i,a,n) for(register signed i=a;i<=n;++i)
#define per(i,a,n) for(register signed i=n;i>=a;--i)
#define mst(x) memset(x,0,sizeof(x));
#define yx_queue priority_queue
#define PI acos(-1)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
typedef long long ll;
const ll mod=( 0 ?998244353:1000000007);
const int N=2;
const int inf=1<<30;
const ll llf=9e18;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int f[4000];
int find(int x){ return x==f[x] ? x : f[x] = find(f[x]); }
struct node{
    int x,y,dir;
    ll no,w,h;
    friend bool operator<(const node &a,const node&b)
    {
        return a.w>b.w;//sort时<小的在前 优先队列时>小的在前
    }
};
bool cmp(node x,node  y)
{
    return x.h>y.h;
}
int min(int a,int b){if(a>b)return b;else return a;}
int max(int a,int b){if(a<b)return b;else return a;}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}template<class T>inline void wt(T &x){
    vector<signed> v;
    int f=0;
    if(x<0)
    f=1,x=-x;
    while(x){
        v.push_back(x%10);
        x/=10;
    }
    reverse(v.begin(),v.end());
    if(f)
    cout<<'-';
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}
//while(rp++)
 
int a[1000010];
int sum[1000010];
int b[1000010];
int mx[1000010];
signed main()
{
   
   printf("%d\n",(int)-0.5);
    return 0;
}