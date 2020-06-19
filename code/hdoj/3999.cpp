#include<bits/stdc++.h>
using namespace std;
const int ut = -522432511;
struct node{
	int  v,l,r;
	void init(){
		v=ut,l=ut,r=ut;
	}
};
vector<node> date;
vector<int> ans;
void dfs(int now){
	ans.push_back(date[now].v);
	if(date[now].l!=ut)
	dfs(date[now].l);
	if(date[now].r!=ut)
	dfs(date[now].r);	
}
int main(){
	int n;
	while(cin>>n){
		date.clear();
		ans.clear();
		int tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			int now=0;
			if(date.empty()){
				node a;
				a.init();
				a.v=tmp;
				date.push_back(a); 
				continue;
			}
			while(true){
				if(tmp<date[now].v){
					if(date[now].l==ut){
						node a;
						a.init();
						a.v=tmp;
						date.push_back(a);
						date[now].l=date.size()-1;
						break;
					}
					now=date[now].l;
					continue;
				}else{
					if(date[now].r==ut){
						node a;
						a.init();
						a.v=tmp;
						date.push_back(a);
						date[now].r=date.size()-1;
						break;
					}
					now=date[now].r;
					continue;
				}
			}			
		}
		dfs(0);
		for(int i=0;i<n-1;i++){
			cout<<ans[i]<<' ';
		}
		cout<<ans[n-1]<<endl;
	}
}
