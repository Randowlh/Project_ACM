#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll _,n,m,ans;
ll s1[50005][2],s2[50005][2];
struct record{
	ll x,y;
	bool vis;
	bool operator<(const record a) const{
		return x!=a.x?x>a.x:y>a.y;
	}
}a[50005];
int main(){
	ll i,j,k;
	// freopen("in.txt","r",stdin);
	// //freopen("i.out","w",stdout);
	for (scanf("%lld",&_);_;_--){
		scanf("%lld",&n);
		for (i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
		sort(a+1,a+n+1);
		m=0;
		for (i=1;i<=n;i=j){
			a[++m]=a[i];
			for (j=i+1;j<=n;j++)
			if (a[j].x!=a[i].x) break;
			a[m].vis=bool(a[i+1].x!=a[i].x||a[i+1].y!=a[i].y);
		}
		n=0;
		for (i=1;i<=m;i=j){
			a[++n]=a[i];
			for (j=i+1;j<=m;j++)
			if (a[j].y>a[i].y) break;
		}
		for (i=1;i<n;i=j){
			for (j=i+1;j<n;j++)
			if ((a[j].x-a[j+1].x)*(a[j].y-a[i].y)>(a[i].x-a[j].x)*(a[j+1].y-a[j].y)) break;
			for (k=i+1;k<=j;k++) s1[k][0]=a[i].x-(a[k].x,s1[k][1]=a[k].y-a[i].y);
		}
		for (i=n;i>1;i=j){
			for (j=i-1;j>1;j--)
			if ((a[j-1].x-a[j].x)*(a[i].y-a[j].y)<(a[j].x-a[i].x)*(a[j].y-a[j-1].y)) break;
			for (k=i-1;k>=j;k--) s2[k][0]=a[k].x-(a[i].x,s2[k][1]=a[i].y-a[k].y);
		}
		ans=0;
		s1[1][0]=0; s1[1][1]=1;
		s2[n][0]=3e9; s2[n][1]=1;
		for (i=1;i<=n;i++)
		if (a[i].vis&&s1[i][0]*s2[i][1]<s2[i][0]*s1[i][1]) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
