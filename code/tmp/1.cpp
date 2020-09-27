#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
#define int long long
#define pb push_back
#define rep(i,a,n) for(register int i=a;i<=n;++i)
#define per(i,a,n) for(register int i=n;i>=a;--i)
#define mst(x) memset(x,0,sizeof(x));
#define yx_queue priority_queue
#define PI acos(-1)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
typedef long long ll;
const ll mod=( 1 ?998244353:1000000007);
const int N=2;
const int inf=1<<30;
const ll llf=9e18;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//int f[1000100];
//int find(int x){ return x==f[x] ? x : f[x] = find(f[x]); }
struct node{
    int x,y,time;
    ll no,w,h;
    int pre,nxt;
    friend bool operator<(const node &a,const node&b)
    {
        return a.w>b.w;//sort时<小的在前 优先队列时>小的在前 
    }
};
bool cmp(int x,int y)
{
    return x>y;
}
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//mt19937 myrand(seed);
//uniform_int_distribution<ll>dist(0,1);//设定随机范围;
// dist(myrand); 这就是个在范围内的随机数; 
int min(int a,int b){if(a>b)return b;else return a;}
int max(int a,int b){if(a<b)return b;else return a;}
void upmax(int& a,int b){if(a<b)a=b;};
void upmin(int& a,int b){if(a>b)a=b;};
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,-1,1,1,-1};
//树状数组 
//int n,ts[100010];
//inline int lowbit(int x){return x&(-x);}
oid add(int x,int k){while(x<=n) {ts[x]+=k; x+=lowbit(x);}}
//int query(int x){int sum=0; while (x) {sum+=ts[x]; x-=lowbit(x);} return sum;}
//组合数
//const ll maxn=201000;
/ fac[maxn];
/oid cinit(){fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;}
/ C(ll x, ll y){return fac[x]*powmod(fac[y]*fac[x-y]%mod,mod-2)%mod;}//x>y
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
//while(rp++)
 
int a[100100];
int d[100100];
int sum[100100]; 
int pre[100100];
int mx[100100];
signed main()
{
    ios::sync_with_stdio(false);
    //freopen("a.in","r",stdin);
    int _=1;
    //cin>>_;
    while(_--)
    {
		int n,k;
		cin>>n>>k;
		rep(i,1,n)cin>>a[i];
		sum[n+1];
		per(i,1,n)
		{
			sum[i]=sum[i+1]+a[i];
		}
		rep(i,1,n)cin>>d[i];
		int ans=0;
		if(k==0)
		{
			rep(i,1,n)
			{
				upmax(ans,sum[i]-d[i]);
			}
		}
		else
		{
			if(k!=1)
			{
				rep(i,1,n)
				{
					upmax(ans,sum[i]-d[i]);
				}
			} 
			else
			{
				rep(i,1,n-2)
				{
					upmax(ans,sum[i]-a[i+1]-d[i]);	
				 } 
			}
			mx[n+1]=0;
			per(i,1,n)
			{
				mx[i]=max(mx[i+1],sum[i]-d[i]);
			 } 
			rep(i,1,n)pre[i]=pre[i-1]+a[i]; 
			rep(i,2,n-1)
			{
				upmax(ans,pre[i]-d[i]+mx[i+1]);
			 } 
		}
		cout<<ans;
  	} 
	return 0;
}
