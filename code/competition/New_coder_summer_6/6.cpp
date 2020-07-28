#include <bits/stdc++.h>
int _,n,m;
int main(){
	int i,j,k;
	for (scanf("%d",&_);_;_--){
		scanf("%d%d",&n,&m);
		if (2*n*(n+1)%m||m==1){
			printf("-1\n");
			continue;
		}
		k=1;
		/*if (m==2*n*(n+1))
		for (i=1;i<=2*n+2;i++){
			for (j=0;j<n;j++) printf("%d ",++k);
			printf("\n");
		}
		else*/ for (i=1;i<=2*n+2;i++){
			for (j=0;j<n;j++) printf("%d ",(k+j-1)%m+1);
			printf("\n");
			k=(k+(n)/(2*n*(n+1)/m)-1)%m+1;
		}
    }
    return 0;
}
