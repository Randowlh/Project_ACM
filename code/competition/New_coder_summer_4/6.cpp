#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int _,n,m,p[180000],ans[1000005][2];
struct record{
	int d,x[10];
	bool operator<(const record z) const{
		int i;
		if (x[0]^z.x[0]) return x[0]<z.x[0];
		for (i=x[0];i;i--)
		if (x[i]^z.x[i]) return x[i]>z.x[i];
		return 1;
	}
}a[2000005],b[2000005],c[1000005];
bool vis[2000005];
void sieve(){
	int i,j;
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
int main(){
	int i,j,x;
	sieve();
	for (i=1;i<=maxn;i++){
		x=i;
		a[i].d=i;
		a[i].x[0]=0;
		for (j=1;p[j]*p[j]<=i;j++)
		if (x%p[j]==0){
			while (x%p[j]==0) x/=p[j];
			a[i].x[++a[i].x[0]]=p[j];
		}
		if (x^1) a[i].x[++a[i].x[0]]=x;
	}
	for (scanf("%d",&_);_;_--){
		scanf("%d",&n);
		for (i=2;i<=n;i++) b[i]=a[i],vis[i]=1;
		ans[0][0]=0;
		for (i=lower_bound(p+1,p+p[0]+1,n/2+1)-p-1;i;i--){
			m=0;
			for (j=1;j*p[i]<=n;j++)
			if (vis[j*p[i]]) c[++m]=b[j*p[i]];
			//printf("%d   %d   %d\n",p[i],m,ans[0][0]);
			sort(c+1,c+m+1);
			for (j=2;j<=m;j+=2){
				vis[c[j-1].d]=0;
				vis[c[j].d]=0;
				ans[++ans[0][0]][0]=c[j-1].d;
				ans[ans[0][0]][1]=c[j].d;
			}
			if (m&1) b[c[m].d].x[0]--;
		}
		printf("%d\n",ans[0][0]);
		for (i=1;i<=ans[0][0];i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
