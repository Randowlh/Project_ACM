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
int f[4000];
int find(int x){ return x==f[x] ? x : f[x] = find(f[x]); }
struct node{
    int x,y,dir;
    ll no,w,h;
    friend bool operator<(const node &a,const node&b)
    {
        return a.w<b.w;//sort时<小的在前 优先队列时>小的在前 
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
//while(rp++)
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
int n[2],v[2][11000],w[2][11000];
VI g[2];
int book[2][1000100];
signed main()
{
    //ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    int t=1;
    rd(t);
    while(t--)
    {
    	rd(n[0]);
    	rd(n[1]);
    	int sum[2]={0};
    	rep(k,0,1)
        rep(i,1,n[k])
		{
			rd(w[k][i]);
			rd(v[k][i]);
			sum[k]+=w[k][i];
		}
		int upp=min(sum[0],sum[1]);
		rep(k,0,1)
            rep(i,0,upp)
                book[k][i]=-llf;
		g[0].clear();
		g[1].clear();
    	rep(k,0,1)
    	{
    		g[k].pb(0);
    		book[k][0]=0;
    		rep(i,1,n[k])
			{
				VI tmp;
                tmp.clear();
				for(int j:g[k])
				{
					if(j+w[k][i]>upp)continue;
					if(book[k][j+w[k][i]]==-llf)tmp.pb(j+w[k][i]);
						book[k][j+w[k][i]]=max(book[k][j+w[k][i]],book[k][j]+v[k][i]);
				}
				for(int j:tmp)g[k].pb(j);
			}
		}
		int ans=0;
		rep(i,0,upp)
        if(book[0][i]!=-llf&&book[1][i]!=-llf)
        ans=max(ans,book[0][i]+book[1][i]);
		cout<<ans<<endl;
    }
    return 0;
}
