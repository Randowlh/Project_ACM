#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define Inf 501
using namespace std;
const int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
int n,m;
int h[501][501],l[501],r[501];
int que[250010][2];
bool vis[501][501],ok[501];
struct node{
	int l,r;
	void cl(){
		l=Inf;
	}
}q[501];
inline void re(int &n){
	n=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') n=n*10+ch-'0',ch=getchar();
}
inline bool cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	if(a.l==b.l) return a.r<b.r; 
}
inline void bfs(int x,int y){//简单的Bfs过程 
	int head=0,tail=1,x1,y1;
	memset(vis,0,sizeof(vis));
	que[1][0]=x;que[1][1]=y;vis[x][y]=1;
	while(head<tail){
		head++;
		for(int i=0;i<4;i++){
			x1=que[head][0]+dx[i];
			y1=que[head][1]+dy[i];
			if(x1<1||y1<1||x1>n||y1>m||h[que[head][0]][que[head][1]]>=h[x1][y1]||vis[x1][y1]) continue;
			vis[x1][y1]=1;//这里注意是反着搜的，意思是我们要找比它大的 
			tail++;
			que[tail][0]=x1;
			que[tail][1]=y1;
			if(x1==1){
				q[y].l=min(y1,q[y].l);
				q[y].r=max(y1,q[y].r);
			}
		}
	}
}
int main()
{
    freopen("in.txt", "r", stdin);
	re(n);re(m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    re(h[i][j]);
	int tot=0;
	for(int i=1;i<=m;i++){
		q[i].cl();//初始化 
		bfs(n,i);//搜索 
		if(q[i].l==Inf) tot++;//没有被更新，记录下来 
	}
	if(tot){//如果有的点不能被灌溉到 
		if(n!=1) printf("0\n%d",tot);//如同我们上面说的，如果不是1行，就是有的点灌溉不到 
		else printf("1\n%d",tot); //如果是1行，则该点比左右都高，在该点建设就行，输出1，即能满足 
		return 0;
	}
	sort(q+1,q+m+1,cmp);//区间排序 
	int las=0;//las记录上一个水站的位置 
	for(int i=1;i<=m;i++){
        cout<<q[i].l<<' '<<q[i].r<<endl;
		if(las>=q[i].l&&las<=q[i].r){
			continue;//如果上一个水站在这个区间里，不用管 
		}
		tot++;//贪心的思想，把每一个水站都尽量往后放，这样能满足的就更多 
		las=q[i].r;
	}
	printf("1\n%d\n",tot);
	return 0;
}
