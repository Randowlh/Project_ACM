#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll _,n[2],w[2005][2],sum[2005][2],Min;
ll ans,p[2005][2],f[1010005][2];
template<class T>inline void read(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
int main(){
	register ll i,j,k;
	// freopen("c.in","r",stdinuibniubnt 
	// freopen("c.out","w",stdout);
	for (read(_);_;_--){
		read(n[0]),read(n[1]);
		for (k=0;k<2;k++)
		for (i=1;i<=n[k];i++){
			read(w[i][k]),read(p[i][k]);
			sum[i][k]=sum[i-1][k]+w[i][k];
		}
		Min=min(sum[n[0]][0],sum[n[1]][1]);
		memset(f,192,4*(Min+5)*sizeof(int));
		f[0][0]=f[0][1]=0;
		for (k=0;k<2;k++)
		for (i=1;i<=n[k];i++)
		for (j=min(Min,sum[i][k]);j>=w[i][k];j--)
		if (f[j-w[i][k]][k]+p[i][k]>f[j][k]) f[j][k]=f[j-w[i][k]][k]+p[i][k];
		ans=0;
		for (i=Min;i;i--)
		if (f[i][0]+f[i][1]>ans) ans=f[i][0]+f[i][1];
		printf("%lld\n",ans);
	}
	return 0;
}
