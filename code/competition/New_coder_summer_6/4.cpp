#include<bits/stdc++.h>
using namespace std;
int _,n,m,a[205][205],sum[205][205];
long double ans=0;
int main(){
	int i,j,k;
	for (scanf("%d",&_);_;_--){
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) scanf("%d",&a[i][j]),sum[i][j]=sum[i-1][j]+a[i][j];
		for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) ans=max(ans,(long double)sum[i][j]/a[i][j]);
		printf("%.10Lf\n",ans);
	}
	return 0;
}
