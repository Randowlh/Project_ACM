#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int tmp;
	vector<int> v;
	for(int i=0;i<n;i++){
	cin>>tmp; 
	v.push_back(tmp);
	}
	set<int> q,h;
	int tt=0;
	for(int i=0;i<m;i++){
		q.insert(v[i]);
		tt+=v[i];
	} 
	for(int i=0;i<m-k;i++){
		h.insert(*q.rbegin());
		tt-=*q.rbegin();
		q.erase(*q.rbegin());
	}
	long long ans=0;
	ans+=tt;
	for(int i=m;i<n;i++){
		if(v[i-m]<*h.begin()){
			q.erase(v[i-m]);
			tt-=v[i-m];
		}else{
			h.erase(v[i-m]);
			h.insert(*q.rbegin());
			tt-=*q.rbegin(); 
			q.erase(*q.rbegin());
		}
		if(v[i]<*h.begin()){
			q.insert(v[i]);
			tt+=v[i];
		}else{
			h.insert(v[i]);
			tt+=*h.begin();
			q.insert(*h.begin());
			h.erase(*h.begin());
		}
		ans+=tt;
	}
	cout<<ans<<endl;
	
}
