#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int mp[110][110];
int vis[110][110];
int tvis[110][110];
int b[][2]={{0,0},{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int br[][2]={{0,0},{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
pair<int,int> q[11000];
int fa[11000];
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a^b)
	fa[a]=b;
}
struct node{
	int key;
	int x,y;
	int fr,to;
	inline bool operator<(node a){
		return key < a.key;
	}
}eg[41000];
mt19937 rnd(233);
int tail,head,flag; 
int n;
pair<int,int> s(1,1),e(20,20);
template<class T> class fhq_treap
{
	public:
	struct node
	{
		int l, r;
		T val;
		int key;
		int size;
	};
	node fhq[11000];
	int cnt, root;
	inline int newnode(T val)
	{
		fhq[++cnt].val = val;
		fhq[cnt].key = rand();
		fhq[cnt].size = 1;
		fhq[cnt].l = fhq[cnt].r = 0;
		return cnt;
	}
	inline void pushup(int now)
	{
	fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
	}
	void split(int now, T val, int &x, int &y)
	{
		if (!now)
		{
			x = y = 0;
			return;
		}
		else if (fhq[now].val <= val)
		{
		x = now;
		split(fhq[now].r, val, fhq[now].r, y);
		}
		else
		{
		y = now;
		split(fhq[now].l, val, x, fhq[now].l);
		}
	pushup(now);
	}
	int merge(int x, int y)
	{
		if (!x || !y)
			return x + y;
		if (fhq[x].key > fhq[y].key)
		{
			fhq[x].r = merge(fhq[x].r, y);
			pushup(x);
			return x;
		}
		else
		{
			fhq[y].l = merge(x, fhq[y].l);
			pushup(y);
			return y;
		}
	}
	inline void insert(T val)
	{
		int x, y;
		split(root, val, x, y);
		root = merge(merge(x, newnode(val)), y);
	}
	inline void del(T val)
	{
		int x, y, z;
		val.second.second-=1;
		split(root, val, x, y);
		val.second.second+=1;
		split(y, val, y, z);
		y = merge(fhq[y].l, fhq[y].r);
		root = merge(merge(x, y), z);
	}
	inline int getrk(int num)
	{
		int x, y;
		split(root, num - 1, x, y);
		int ans = fhq[x].size + 1;
		root = merge(x, y);
		return ans;
	}
	inline int getnum(int rank)
	{
		int now=root;
		while(now)
		{
			if(fhq[fhq[now].l].size+1==rank)
			   break;
			else if(fhq[fhq[now].l].size>=rank)
				now=fhq[now].l;
			else
			 {
				rank-=fhq[fhq[now].l].size+1;
				now=fhq[now].r;
			}
		}
		return fhq[now].val;
	}
	inline T pre(T val)
	{
		int x, y;
		T ans;
		val.second.second-=1;
		split(root, val, x, y);
		int t = x;
		while (fhq[t].r)
			t = fhq[t].r;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
	inline T aft(T val)
	{
		int x, y;
		T ans;
		split(root, val, x, y);
		int t = y;
		while (fhq[t].l)
			t = fhq[t].l;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
};
inline bool ck(int x,int y){
	if(!x||x>n)
		return false;
	if(!y||y>n)
		return false;
	return !mp[x][y]&&!vis[x][y];
}
void flsh(){
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			if(!mp[i][j]){
				if(!vis[i][j])
					cout<<"□";
				else if(vis[i][j]==1)
					cout<<"↓";
				else if(vis[i][j]==2)
					cout<<"→";
				else if(vis[i][j]==3)
					cout<<"↑";
				else if(vis[i][j]==4)
					cout<<"←";
				else if(vis[i][j]==6)
                cout<<"﹡";
                else 
                cout<<"﹟";
			}
			else cout<<"■";
		}
		cout<<endl;
	}
}
void gen(){
	system("cls");
	cout<<"Please input the size of maze"<<endl;
	cin>>n;
	n*=2;
	n++;
	for(int i=0;i<=(n+1)*(n+1);i++)
		fa[i]=i;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			mp[i][j]=1,vis[i][j]=0;
	for(int i=1;i<=n;i+=2)
		for(int j=1;j<=n;j+=2)
			mp[i][j]=0;
	int tt=0;
	for(int x=1;x<=n;x+=2)
		for(int y=1;y<=n;y+=2)
			for(int i=1;i<=4;i++)
				if(x+b[i][0]*2>0&&x+b[i][0]*2<=n&&y+b[i][1]*2>0&&y+b[i][1]*2<=n){
					eg[++tt].key=rand();eg[tt].x=x+b[i][0];eg[tt].y=y+b[i][1];
					eg[tt].fr=(x-1)*n+(y-1);
					eg[tt].to=(x+b[i][0]*2-1)*n+y+b[i][1]*2-1;
				}
	sort(eg+1,eg+tt+1);
	for(int i=1;i<=tt;i++){
		if(find(eg[i].fr)==find(eg[i].to)){
			int t=rnd();
			if(t%20==1)
				mp[eg[i].x][eg[i].y]=0;
		}else{
			merge(eg[i].fr,eg[i].to);
			mp[eg[i].x][eg[i].y]=0;
		}
	}
	mp[1][0]=0;
	mp[n][n+1]=0;
	system("cls");
	cout<<"Generated successfully!"<<endl;
	flsh();
	system("pause");
}
void getfile(){
	system("cls");
	cout<<"Please your file name:"<<flush;
	string f;
	cin>>f;
	ifstream in(f);
	in>>n;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			in>>mp[i][j];
	system("cls");
	cout<<"Your maze is:"<<endl;
	flsh();
	system("pause");
}
void dfs(int x,int y){
	system("cls");
	if(x==n&&y==n){
		cout<<"path find!"<<endl;
        vis[n][n]=6;
		flsh();
		flag=1;
		system("pause");
		return;
	}
	cout<<"processing"<<endl;
	flsh();
	Sleep(300);
	int t[5];
	memset(t,0,sizeof(t));
	int cnt=0;
	while(!flag&&cnt<4){
		int i=rand()%4+1;
		if(t[i])
			continue;
		t[i]=1;
		cnt++;
		if(ck(x+b[i][0],y+b[i][1])){
			vis[x][y]=i;
			dfs(x+b[i][0],y+b[i][1]);
		}
	}
	if(!flag)
		vis[x][y]=5;
	return;
}
void show(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
	flag=0;
	dfs(1,1);
}
void srt(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
	fhq_treap<pair<int,pair<int,int>>> q;
	q.insert(make_pair(0,make_pair(1,1)));
	vis[1][1]=-1;
	pair<int,pair<int,int>> mi=make_pair(-999999,make_pair(1,1));
	q.insert(mi);
	q.insert(make_pair(999999,make_pair(1,1)));
	while(q.fhq[q.root].size>2){
		pair<int,pair<int,int>>t=q.aft(mi);
		q.del(t);
		for(int i=1;i<=4;i++){
			if(ck(t.second.first+b[i][0],t.second.second+b[i][1])){
				vis[t.second.first+b[i][0]][t.second.second+b[i][1]]=i;
				q.insert(make_pair(t.first+1,make_pair(t.second.first+b[i][0],t.second.second+b[i][1])));
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			tvis[i][j]=0;
	int x=n,y=n,t,tx,ty;
	while(vis[x][y]!=-1){
		tx=x+br[vis[x][y]][0];
		ty=y+br[vis[x][y]][1];
		tvis[tx][ty]=vis[x][y];
		x=tx,y=ty;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=tvis[i][j];
	vis[n][n]=6;
	system("cls");
	cout<<"The shortest path is:"<<endl;
	flsh();
	system("pause");
}
void sdfs(int x,int y){
	if(x==n&&y==n){
		for(int i=0;i<tail-1;i++){
			cout<<'{'<<q[i].first<<','<<q[i].second<<"},";
		}
		cout<<'{'<<n<<','<<n<<'}'<<endl;
		return;
	}
	for(int i=1;i<=4;i++){
		if(ck(x+b[i][0],y+b[i][1])){
			q[tail++]=make_pair(x+b[i][0],y+b[i][1]);
			vis[x+b[i][0]][y+b[i][1]]=1;
			sdfs(x+b[i][0],y+b[i][1]);
			vis[x+b[i][0]][y+b[i][1]]=0;
			tail--;
		}
	}
	return;
}
void allpath(){
	system("cls");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[i][j]=0;
		}
	}
	tail=0;
	q[tail]=make_pair(1,1);
	vis[1][1]=1;
	tail++;
	sdfs(1,1);
	system("pause");
	return;
}
void work()
{
	system("chcp 65001");
	//system("chcp 437");
	MAIN:
	system("cls");
	cout<<"Main Menu"<<endl;
	cout<<"1.Generate maze"<<endl;
	cout<<"2.Import maze file"<<endl;
	cout<<"3.Show real-time path"<<endl;
	cout<<"4.Get shortest path"<<endl;
	cout<<"5.Get all path"<<endl;
	cout<<"6.EXIT"<<endl;
	cout<<"Please input your choice here:"<<flush;
	int opt;
	cin>>opt;
	if(opt==1){
		gen();
		goto MAIN;
	}else if(opt==2){
		getfile();
		goto MAIN;
	}else if(opt==3){
		show();
		goto MAIN;
	}else if(opt==4){
        srt();
        goto MAIN;
	}else if(opt==5){
        allpath();
		goto MAIN;
	}else if(opt==6){
		return;
	}
	system("cls");
	cout<<"Wrong input!"<<endl;
	Sleep(1000);
	goto MAIN;
}
signed main()
{   srand(time(0));
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while (t--)
	{
		work();
	}
	return 0;
}//学号 19041822 罗汉东