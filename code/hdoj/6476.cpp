#include<bits/stdc++.h>
using namespace std;
bool mp[100][100];
int book[100][100];
int biao[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,q;
inline bool ck(int x,int y){
	if(x<0||x>=n)
	return false;
	if(y<0||y>=m)
	return false;
	if(mp[x][y]||book[x][y]!=-1)
	return false;
	return true;
}
void bfs(){
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	book[i][j]=-1;
	book[0][0]=0;
	queue<pair<int,int> > q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		pair<int,int> t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(ck(t.first+biao[i][0],t.second+biao[i][1])){
				book[t.first+biao[i][0]][t.second+biao[i][1]]=book[t.first][t.second]+1;
				q.push(make_pair(t.first+biao[i][0],t.second+biao[i][1]));
			}
		}
	}	
}
void work(){
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mp[i][j]=0;
		}
	}
	bfs();	
	char tmp;
	int x,y;
	for(int i=0;i<q;i++){
		cin>>tmp>>x>>y;
		if(tmp=='?')
		cout<<book[x-1][y-1]<<endl;
		else {
			mp[x-1][y-1]=1;
			bfs();
		}
	}
	return;
}
int main(){
//	freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		work();
	}
} 
