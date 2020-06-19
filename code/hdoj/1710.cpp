#include <bits/stdc++.h>
using namespace std;
vector<int> pre,in,ans;
void dfs(int pl,int pr,int il,int ir){
	int now=pre[pl];
	int mix=0;
	for(int i=il;i<=ir;i++){
		if(in[i]==now){
			mix=i;
			break;
		}
	}
	mix-=il;
	if(mix>0){
		dfs(pl+1,pl+mix,il,il+mix-1);
	}
	if(mix+il<ir){
		dfs(pl+mix+1,pr,il+mix+1,ir);
	}
	ans.push_back(now);
	return;
}
int main()
{
	int n;
	while(cin>>n){
		pre.clear();
		in.clear();
		ans.clear();
		int tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			pre.push_back(tmp);
		}
		for(int i=0;i<n;i++){
			cin>>tmp;
			in.push_back(tmp);
		}
		dfs(0,n-1,0,n-1);
		for(int i=0;i<n-1;i++){
			cout<<ans[i]<<' ';
		}
		cout<<ans[n-1]<<endl;
	}
}
