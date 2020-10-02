#include <cstdio>

const int N=1e3+5,M=2e3+5;
int n,B,sz,cnt,tot,lnk[N],ter[M],nxt[M],st[N],rt[N],bel[N];

void add(int u,int v) {
	ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot;
}
void dfs(int u,int p) {
	int cnr=sz;
	for(int i=lnk[u];i;i=nxt[i]) {
		int v=ter[i];
		if(v==p) continue;
		dfs(v,u);
		if(sz-cnr>=B) {
			rt[++cnt]=u;
			while(sz>cnr) bel[st[sz--]]=cnt;
		}
	}
	st[++sz]=u;
}
int main() {
	scanf("%d%d",&n,&B);
	for(int i=1;i<n;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	if(!cnt) rt[++cnt]=1;
	while(sz) bel[st[sz--]]=cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i) printf("%d%c",bel[i]," \n"[i==n]);
	for(int i=1;i<=cnt;++i) printf("%d%c",rt[i]," \n"[i==cnt]);
	return 0;
}