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

int a[500010];
int last[500010];
int book[500010];
map<int,int>q;
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;
    	bool ff=false;
    	rep(i,1,n)
    	{
    		cin>>a[i];
    		if(a[i]>k)
    		{
    			ff=true;
			}
		}
		if(ff)
		{
			cout<<"NO"<<endl;
			continue;
		}
    	if(k>=n)
    	{
    		q.clear();
    		bool f=true;
    		rep(i,1,n)
    		{
    			if(q[a[i]]==2)
    			{
    				f=false;
    				break;
				}
				else q[a[i]]++;
			}
			if(f)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			continue;
		}
		int minn=inf,w1,w2;
		rep(i,1,k)
		{
			last[i]=inf;
			book[i]=0;
		}
		rep(i,1,n)
		{
			if(last[a[i]]>i)
			{
				last[a[i]]=i;
			}
			else
			{
				if(i-last[a[i]]<minn)
				{
					minn=i-last[a[i]];
					w1=last[a[i]];
					w2=i;
				}
				last[a[i]]=i;
			}
		}
		bool gg=false;
		rep(i,w1+1,w2)
		{
			int l=i;
			while(l<=n)
			{
				rep(j,1,k)book[j]=0;
				bool f=true;
				rep(j,l,min(l+k-1,n))
				{
					book[a[j]]++;
					if(book[a[j]]>1)
					{
						f=false;
						break;
					}
				}
				if(!f)break;
				l+=k;
			}
			if(l<=n)continue;
			int r=i-1;
			while(r>=1)
			{
				rep(j,1,k)book[j]=0;
				bool f=true;
				per(j,max(1,r-k+1),r)
				{
					book[a[j]]++;
					if(book[a[j]]>1)
					{
						f=false;
						break;
					}
				}
				if(!f)break;
				r-=k;
			}
			if(r<1)
			{
				gg=true;
				break;
			}
		}
		if(gg)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
    return 0;
}
