#include<bits/stdc++.h>
int _,n,m,l[100005],r[100005],a[100005],b[100005];
int main(){
	int i;
	for (scanf("%d",&_);_;_--){
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		a[n]=l[n]; b[n]=r[n];
		for (i=n-1;i;i--){
			a[i]=a[i+1]-m;
			b[i]=b[i+1]+m;
			if (a[i]<l[i]) a[i]=l[i];
			if (b[i]>r[i]) b[i]=r[i];
			if (a[i]>b[i]) break;
		}
		if (!i){
			printf("YES\n");
			for (i=1;i<=n;i++) printf("%d ",a[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}
