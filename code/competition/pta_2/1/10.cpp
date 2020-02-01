#include<bits/stdc++.h>
using namespace std;
int i,j,m,n;
vector<int> ans[1000];
void dfs(vector<int> a,vector<int> b ,int step){
    ans[step].push_back(a[a.size()-1]);
    int k=a[a.size()-1];
    int u=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==k){
            u=i;
            break;
        }
    }
    vector<int> a1,a2;
    for(int i=0;i<u;i++){
        a1.push_back(a[i]);
        a2.push_back(b[i]);
    }
    if(!a1.empty())
    dfs(a1,a2,step+1);
    a1.clear();
    a2.clear();   
    for(int i=u;i<a.size()-1;i++){
        a1.push_back(a[i]);
        a2.push_back(b[i+1]);
    }
    if(!a1.empty())
    dfs(a1,a2,step+1);
   // dfs(M.substr(u+1,len-u-1),L.substr(u,len-1-u));  
}
int main(){
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    vector<int> a,b;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        b.push_back(tmp);
    }
	dfs(a,b,0);
    int fl=0;
    for(int i=0;i<1000;i++){
        if(ans[i].empty())
        break;
        for(int j=0;j<ans[i].size();j++){
            if(fl)
            cout<<' ';
            cout<<ans[i][j];
            fl=1;
        }
    }
	return 0;
}