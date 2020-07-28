#include<bits/stdc++.h>
using namespace std;
//#define int long long
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
//int f[100000];
//int find(int x){ return x==f[x] ? x : f[x] = findx(f[x]); }
struct node{
    int x,y;
    ll no,w,h;
    friend bool operator<(const node &a,const node&b)
    {
        return a.h>b.h;//小的在前
    }
};
bool cmp(node x,node  y)
{
    return x.h>y.h;
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
//while(rp++)
const int inv2=powmod(2,mod-2);
int f[20000010];
int d[20000010];
int g[20000010];
int h[20000010];
int ans[20000010];
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    f[1]=1;
    d[1]=inv2;
    g[1]=inv2;
    h[1]=500000004;
    ans[1]=500000004;
   	int tmp=4;
    rep(i,2,20000010)
	{
		f[i]=1ll*f[i-1]*(tmp-1)%mod;
		tmp=tmp*2%mod;
		d[i]=1ll*d[i-1]*inv2%mod;
		g[i]=1ll*g[i-1]*d[i]%mod;
		h[i]=1ll*f[i]*g[i]%mod;
		ans[i]=h[i]^ans[i-1];
	}
    while(t--)
    {
    	int n;
    	cin>>n;
    	cout<<ans[n]<<endl;
    }
    return 0;
}
