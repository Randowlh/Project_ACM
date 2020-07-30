#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
using namespace std;
const int maxn=200005;
const int INF=2e9;
int _,n,m1,m2,ans;
int b[200005],que[400005];
struct record{
	int x,y,d;
}a[200005],fa[200005];
struct edge{
	int w,to,rev;
};
unordered_map<int,int> p1,p2,dep;
vector<edge> e[200005];
inline bool cmp1(record a,record b){
	return a.x<b.x;
}
inline bool cmp2(record a,record b){
	return a.y<b.y;
}
inline bool cmp3(record a,record b){
	return a.d<b.d;
}
inline bool bfs(){
	register int i,x,y,sz,head=0,tail=1;
	dep.clear();
	dep[0]=1; que[1]=0; fa[0].x=-1;
	while (head^tail){
		head=(head+1)%maxn;
		x=que[head];
		for (i=0,sz=e[x].size();i<sz;i++)
		if (e[x][i].w&&!dep[e[x][i].to]){
			dep[e[x][i].to]=dep[x]+1;
			fa[e[x][i].to].x=x; fa[e[x][i].to].d=i;
			tail=(tail+1)%maxn; que[tail]=e[x][i].to;
			if (e[x][i].to==m1+m2+1) break;
		}
	}
	if (!dep[m1+m2+1]) return 0;
	ans++;
	x=fa[m1+m2+1].x; y=fa[m1+m2+1].d;
	while (x>=0){
		e[x][y].w--;
		e[e[x][y].to][e[x][y].rev].w++;
		y=fa[x].d; x=fa[x].x;
	}
	return 1;
}
inline void dinic(){
	ans=0;
	while (bfs());
}
int main(){
    register int i,x,y,z;
	for (scanf("%d",&_);_;_--){
		rd(n);
		for (i=1;i<=n;i++){
			rd(x),rd(y);
			a[i].x=y-x; a[i].y=y+x;
			a[i].d=i;
		}
		stable_sort(a+1,a+n+1,cmp1);
		for (i=1;i<=n;i++) b[i]=a[i].x;
		m1=a[1].x=1;
		for (i=2;i<=n;i++) a[i].x=(b[i]==b[i-1]?m1:++m1);
		stable_sort(a+1,a+n+1,cmp2);
		for (i=1;i<=n;i++) b[i]=a[i].y;
		m2=a[1].y=1;
		for (i=2;i<=n;i++) a[i].y=(b[i]==b[i-1]?m2:++m2);
		for (i=0;i<=m1+m2+1;i++) e[i].clear();
		for (i=1;i<=m1;i++){
			e[0].push_back((edge){1,i,e[i].size()});
			e[i].push_back((edge){0,0,e[0].size()-1});
		}
		for (i=1;i<=m2;i++){
			e[m1+i].push_back((edge){1,m1+m2+1,e[m1+m2+1].size()});
			e[m1+m2+1].push_back((edge){0,m1+i,e[m1+i].size()-1});
		}
		for (i=1;i<=n;i++){
			x=a[i].x; y=m1+a[i].y;
			//printf("%d  %d\n",x,y-m1);
			e[x].push_back((edge){1,y,e[y].size()});
			e[y].push_back((edge){0,x,e[x].size()-1});
		}
		dinic();
		printf("%d\n",ans);
	}
	return 0;
}
