#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int mp[110][110];
int vis[110][110];
int b[][2]={{0,0},{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pair<int,int> q[11000];
//⏩⏪⏫⏬
int tail,head,flag;
mt19937 rnd(233);
int n;
pair<int,int> s(1,1),e(20,20);
mt19937 rnd(514114);
template<class T> class fhq_treap
{
	struct node
	{
		int l, r;
		T val;
		int key;
		int size;
	} fhq[10];
	int cnt, root;
	inline int newnode(int val)
	{
		fhq[++cnt].val = val;
		fhq[cnt].key = rnd();
		fhq[cnt].size = 1;
		fhq[cnt].l = fhq[cnt].r = 0;
		return cnt;
	}
	inline void pushup(int now)
	{
	fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
	}
	void split(int now, int val, int &x, int &y)
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
	inline void insert(int val)
	{
		int x, y;
		split(root, val, x, y);
		root = merge(merge(x, newnode(val)), y);
	}
	inline void del(int val)
	{
		int x, y, z;
		split(root, val - 1, x, y);
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
	inline int pre(int val)
	{
		int x, y, ans;
		split(root, val - 1, x, y);
		int t = x;
		while (fhq[t].r)
			t = fhq[t].r;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
	inline int aft(int val)
	{
		int x, y, ans;
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
					cout<<"⬛";
				else cout<<vis[i][j];
				// else if(vis[i][j]==1)
				// 	cout<<"⏩";
				// else if(vis[i][j]==2)
				// 	cout<<"⏫";
				// else if(vis[i][j]==3)
				// 	cout<<"⏪";
				// else if(vis[i][j]==4)
				// 	cout<<"⏬";
				// else cout<<"❌";
			}
			else cout<<"⬜";
		}
		cout<<endl;
	}
}
bool test(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
	tail=head=0;
	q[tail]=s;
	tail++;
	while(tail^head){
		pair<int,int> t=q[head];
		head++;
		if(t.first==n&&t.second==n)
			return true;
		for(int i=1;i<=4;i++){
			if(ck(t.first+b[i][0],t.second+b[i][1])){
				vis[t.first+b[i][0]][t.second+b[i][1]]=1;
				q[tail]=make_pair(t.first+b[i][0],t.second+b[i][1]);
				tail++;
			}
		}
	}
	return false;
}
void gen(){
	system("cls");
	cout<<"Please input the size of maze"<<endl;
	cin>>n;
	do{
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			mp[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(rnd()%10<5)
				mp[i][j]=0;
			else mp[i][j]=1;
		mp[1][1]=0;
		mp[n][n]=0;
	}while(!test());
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
	system("cls");
	cout<<"Generated successfully!"<<endl;
	flsh();
	system("pause");
}
void getfile(){
	system("cls");
	cout<<"Please your file name:";
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
		flsh();
		flag=1;
		system("pause");
		return;
	}
	cout<<"processing"<<endl;
	cout<<"now="<<x<<' '<<y<<endl;
	flsh();
	Sleep(100);
	set<int> s;
	while(s.size()<4){
		int i=rnd()%4+1;
		if(s.count(i))
			continue;
		s.insert(i);
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
void work()
{
	system("chcp 65001");
	MAIN:
	system("cls");
	cout<<"Main Menu"<<endl;
	cout<<"1.Generate maze"<<endl;
	cout<<"2.Import maze file"<<endl;
	cout<<"3.Show real-time path"<<endl;
	cout<<"4.Get all road"<<endl;
	cout<<"5.Get shortest path"<<endl;
	cout<<"6.EXIT"<<endl;
	cout<<"Please input your choice here:";
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

	}else if(opt==5){
		
	}else if(opt==6){
		return;
	}
	system("cls");
	cout<<"Wrong input!"<<endl;
	Sleep(1000);
	goto MAIN;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while (t--)
	{
		work();
	}
	return 0;
}