#include<bits/stdc++.h>
#define ll long long
using namespace std;
int _,n,m,tot,w[100005],d[100005],fa[100005];
ll ans;
vector<int> e[100005];
set<int> v;
bool cmp(int x,int y){
	return w[x]>w[y];
}
int get(int x){
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	int fx=get(x),fy=get(y);
	fa[fx]=fy;
}
int main(){
	int i,j,x,y,sz;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d",&_);_;_--){
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++){
			scanf("%d",&w[i]);
			d[i]=i;
			e[i].clear();
		}
		sort(d+1,d+n+1,cmp);
		while (m--){
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		memset(fa,0,sizeof(fa));
		for (i=1;i<=n;i++){
			x=d[i];
			fa[x]=x;
			v.clear();
			for (j=0,sz=e[x].size();j<sz;j++)
			if (fa[e[x][j]]) v.insert(get(e[x][j]));
			ans+=(1ll-v.size())*w[x];
			for (auto it=v.begin();it!=v.end();it++) merge(x,*it);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
