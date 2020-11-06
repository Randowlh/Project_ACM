#include<bits/stdc++.h>
#define ll long long
int n;
struct node{
	int x,y;
}a[10],b[10];
ll cost(int x,int y){
	return 1ll*(a[x].x-a[y].x)*(a[x].x-a[y].x)+1ll*(a[x].y-a[y].y)*(a[x].y-a[y].y);
}
int main(){
	int i,j,k; char str[5];
	scanf("%d",&n);
	if (n==1){
		printf("! 1 1");
		return 0;
	}
	a[1].x=a[1].y=1;
	a[4]=a[1];
	a[2].x=a[5].y=1; a[2].y=a[5].x=n;
	a[3].x=a[3].y=n;
	a[6]=a[3];
	while (1){
		printf("? 3");
		for (i=1;i<=3;i++) printf(" %d %d",a[i].x,a[i].y);
		printf("\n");
		fflush(stdout);
		scanf("%s",str);
		if (str[0]=='N') for (i=1;i<=3;i++) a[i]=a[i+3];
		j=1;
		for (i=2;i<=3;i++)
		if (cost(i,i%3+1)>cost(j,j%3+1)) j=i;
		if (cost(j,j%3+1)<=4) break;
		a[4]=a[(j+1)%3+1];
		a[5]=a[j];
		a[6].x=(a[j].x+a[j%3+1].x)/2;
		a[6].y=(a[j].y+a[j%3+1].y)/2;
		a[j]=a[6];
	}
	for (i=1;i<=3;i++) b[i]=a[i];
	k=(j+1)%3;
	for (i=1;i<=3;i++)
	if (i^j&&cost(i,i%3+1)>cost(k,k%3+1)) k=i;
	if (b[k].x==b[k%3+1].x){
		b[4].x=b[5].x=b[k].x;
		b[4].y=(b[k].y+b[k%3+1].y)/2;
		b[5].y=(b[k].y+b[k%3+1].y)/2+1;
	}
	else{
		b[4].y=b[5].y=b[k].y;
		b[4].x=(b[k].x+b[k%3+1].x)/2;
		b[5].x=(b[k].x+b[k%3+1].x)/2+1;
	}
	for (i=1;i<=5;i++){
		printf("? 1 %d %d\n",b[i].x,b[i].y);
		fflush(stdout);
		scanf("%s",str);
		if (str[0]=='Y') break;
	}
	printf("! %d %d\n",b[i].x,b[i].y);
	fflush(stdout);
	return 0;
}