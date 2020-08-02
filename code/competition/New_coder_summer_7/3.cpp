#include<bits/stdc++.h>
int _,n,m,r,ans,a[155],b[155],c[10];
void work(){
	int i,j,res=0;
	for (i=1;i<n;i++)
	for (j=i+1;j<=n;j++) res+=(a[c[i]]-a[c[j]])*(a[c[i]]-a[c[j]])+(b[c[i]]-b[c[j]])*(b[c[i]]-b[c[j]]);
	if (res>ans) ans=res;
}
void dfs(int x){
	int i;
	if (x>n){
		work();
		return;
	}
	for (i=c[x-1];i<=m;i++){
		c[x]=i;
		dfs(x+1);
	}
}
int main(){
	int i;
	freopen("a.out","w",stdout);
	for (n=8;n<=8;n++){
		for (r=30;r>=15;r--){
			m=0;
			for (i=-r;i<=r;i++){
				a[++m]=i; b[m]=int(sqrt(r*r-i*i)+1e-8);
				a[++m]=i; b[m]=-b[m-1];
			}
			c[0]=1;
			ans=0;
			dfs(1);
			printf("%d,",ans);
		}
		printf("\n");
	}
	return 0;
}
