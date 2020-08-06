#include<bits/stdc++.h>
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
const ll mod=( 0 ?998244353:1000000007);
const int N=2;
const int inf=1<<30;
const ll llf=9e18;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int f[200100];
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
}
//while(rp++)

int s[200010];
int ss[200010];
bool vis[200010];
int p[200010];
void sieve(){
	int i,j;
	int maxn=200000;
	memset(vis,1,sizeof(vis));
	p[0]=vis[0]=vis[1]=0;
	for (i=1;i<=maxn;i++){
		if (vis[i]) p[++p[0]]=i;
		for (j=1;j<=p[0]&&p[j]*i<=maxn;j++){
			vis[i*p[j]]=0;
			if (!(i%p[j])) break;
		}
	}
}
int pp[200010];
int cnt=0;
signed main()
{
    ios::sync_with_stdio(false);
    //freopen("c.in","r",stdin);
    int _=1;
    cin>>_;
    int k,x;
    cin>>k>>x;
    sieve();
    int up=200000;
    rep(i,1,p[0])
    {
    	if(p[i]*p[i]<=up)
		{
			f[p[i]*p[i]]=(-p[i]+mod)%mod;
			f[p[i]*p[i]]=f[p[i]*p[i]]*powmod(p[i]*p[i],k*x%(mod-1))%mod;
		}
    	if(p[i]<=up)
		{
			f[p[i]]=(p[i]-1)%mod;
			f[p[i]]=f[p[i]]*powmod(p[i],k*x%(mod-1))%mod;
		}
	}
	rep(i,1,up)
	{
		ss[i]=(ss[i-1]+powmod(i,k))%mod;
	}
    rep(i,1,up)
    {
    	s[i]=powmod(ss[i],x)%mod;
	}
	f[1]=1;
	rep(i,1,up)
	{
		if(f[i])
		{
			pp[++cnt]=i;
		}
	}
    while(_--)
    {
    	int n;
    	cin>>n;
    	int ans=0;
    	rep(i,1,cnt)
    	{
    		if(pp[i]>n)break;
    		ans=(ans+s[n/pp[i]]*f[pp[i]]%mod)%mod;
		}
		cout<<ans<<endl;
	}
    return 0;
}