#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define int long long 
using namespace std;
int _,n,tot,fa[1000005],que[1000005],st[1000005];
ll a[1000005],v[1000005],cost[1000005],s[1000005];
struct edge{
	ll w;
	int to,nxt;
}e[2000005];
struct node{
	ll x,y;
};
vector<node> b[1000005];
inline bool cmp(node a,node b){
	if (a.y>0) return (b.y>0?a.x<b.x:1);
	if (a.y==0) return b.y<0;
	return a.x>b.x;
}
void add(int x,int y,ll z){
	e[++tot].to=y; e[tot].w=z; e[tot].nxt=st[x]; st[x]=tot;
}
void bfs(){
	int i,x,head=0,tail=1;
	for (i=1;i<=n;i++) fa[i]=0;
	fa[1]=que[1]=1;
	while (head^tail){
		x=que[++head];
		for (i=st[x];i;i=e[i].nxt)
		if (!fa[e[i].to]){
			fa[e[i].to]=x;
			v[e[i].to]=e[i].w;
			que[++tail]=e[i].to;
		}
	}
}
signed main(){
	int i,j,x,y,sz; ll z;
	for (scanf("%lld",&_);_;_--){
		scanf("%lld",&n);
		for (i=1;i<=n;i++) scanf("%lld",&a[i]),st[i]=0;
		tot=0;
		for (i=1;i<n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z); add(y,x,z);
		}
		bfs();
		fa[1]=0;
		for (i=0;i<=n;i++) b[i].clear();
		for (i=n;i;i--){
			x=que[i];
			s[x]=a[x]-v[x]*2;
			cost[x]=max(-s[x],0ll);
			if (b[x].empty()){
				sort(b[x].begin(),b[x].end(),cmp);
				for (j=0,sz=b[x].size();j<sz;j++){
					if (cost[x]+s[x]<b[x][j].x) cost[x]=b[x][j].x-s[x];
					s[x]+=b[x][j].y;
					if (cost[x]+s[x]<0) cost[x]=-s[x];
				}
			}
			b[fa[x]].push_back((node){cost[x],s[x]});
		}
		printf("%lld\n",cost[1]);
	}
	return 0;
}
