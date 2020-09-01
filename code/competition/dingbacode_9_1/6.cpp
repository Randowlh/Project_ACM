#include<bits/stdc++.h>
#define sz(s) s.size()
#define pb push_back
#define ll long long 
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define frep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N = 1E6+10;
const int INF = 1E9+7;

int n,m,L,R,a[N],pre[N],dp[N];
int xb[N<<1];
vector<int>vt[N<<1];  

struct Seg{
	int mx[N<<3];
	void build(int l,int r,int rt){
		mx[rt]=-INF;
		if(l==r) return;
		int m=(l+r)>>1;
		build(l,m,rt<<1);
		build(m+1,r,rt<<1|1);
	} 
	void modify(int l,int r,int rt,int pos,int x){
		if(l==r){
			mx[rt]=x;
			return;
		}
		int m=(l+r)>>1;
		if(pos<=m) modify(l,m,rt<<1,pos,x);
		else modify(m+1,r,rt<<1|1,pos,x);
		mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	}
	int query(int l,int r,int rt,int L,int R){
		if(L<=l&&r<=R) return mx[rt];
		int m=(l+r)>>1;
		int res=-INF;
		if(L<=m) res=query(l,m,rt<<1,L,R);
		if(R>m) res=max(res,query(m+1,r,rt<<1|1,L,R));
		return res;
	} 
	Seg(){}
}T;

void ins(int i){
	int x=pre[i]+n+1;
	while(sz(vt[x])>xb[x]&&dp[vt[x].back()]<=dp[i])
	  vt[x].pop_back();
	vt[x].pb(i);
	T.modify(1,m,1,x,dp[vt[x][xb[x]]]);
}

void del(int i){
	int x=pre[i]+n+1;
    if(sz(vt[x])>xb[x]&&vt[x][xb[x]]==i) ++xb[x];
    T.modify(1,m,1,x,(sz(vt[x])>xb[x]?dp[vt[x][xb[x]]]:-INF));
}

void work()
{
	cin>>n>>L>>R;
	rep(i,1,n) cin>>a[i],pre[i]=pre[i-1]+a[i];
	
	m=n<<1|1;  // [-n,n] -> [1,2*n+1]
	
	rep(i,1,m) vt[i].clear(),xb[i]=0;
	T.build(1,m,1);
	rep(i,1,L-1) dp[i]=-INF;
	rep(i,L,n){
		if(i>R) del(i-R-1); 
		if(i>=L) ins(i-L);
		int k=pre[i]+n+1;
		dp[i]=-INF;
		if(k>1) dp[i]=max(dp[i],T.query(1,m,1,1,k-1)+1);
		if(k<m) dp[i]=max(dp[i],T.query(1,m,1,k+1,m)-1);
		dp[i]=max(dp[i],T.query(1,m,1,k,k));
	}
	cout<<dp[n]<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int t;cin>>t;
	while(t--) work();
} 