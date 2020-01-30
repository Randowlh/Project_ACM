#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[60][60];
int n;
int mx=0;
vector<int> tmp;
bool check(int now){
    bool fl=true;
    for(int i=0;i<tmp.size();i++){
        if(mp[tmp[i]][now]!=1||mp[now][tmp[i]]!=1){
            fl=false ;
            break;
        }
    }
    return fl;
}
void dfs(int step){
    if(step==n+1){
        if(tmp.size()>mx){
            mx=tmp.size();
        }
        return;
    }
    if(tmp.size()+n-step+1<=mx){
        return;
    }
    if(check(step)){
        tmp.push_back(step);
        dfs(step+1);
        tmp.pop_back();
    }
        dfs(step+1);

}
void work(){
//    int n;
    while(cin>>n){
        if(n==0)
        break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mp[i][j];
            }
        }
        tmp.clear();
        mx=0;
        dfs(1);
        cout<<mx<<endl;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}