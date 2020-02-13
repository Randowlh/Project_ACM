#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
vector<char> ans;
int fl=1;
string tmp;
set<char> s;
void dfs(int now,int pos){
    if(fl==0){
        return;
    }
    if(pos==tmp.size()){
        return;
    }
    if(s.count(tmp[pos])==0){
        if(now==ans.size()-1){
            ans.push_back(tmp[pos]);
            s.insert(tmp[pos]);
            dfs(now+1,pos+1);
        }else if(now==0){
            ans.insert(ans.begin(),tmp[pos]);
            s.insert(tmp[pos]);
            dfs(0,pos+1);
        }else{
            fl=0;
            return;
        }
    }else if(now+1<ans.size()&&ans[now+1]==tmp[pos]){
        dfs(now+1,pos+1);
    }else if(ans[now]==tmp[pos]){
        dfs(now,pos+1);
    }else if(now-1>=0&&ans[now-1]==tmp[pos]){
        dfs(now-1,pos+1);
    }else{
        fl=0;
        return;
    }
}
void work(){
    fl=1;
 //   string tmp;
    set<char> tp;
    for(char i='a';i<='z';i++){
        tp.insert(i);
    }
    cin>>tmp;
    s.clear();
    ans.clear();
    ans.push_back(tmp[0]);
    s.insert(tmp[0]);
    dfs(0,1);
    if(fl){
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size(); i++){
            cout<<ans[i];
        }
        while(!s.empty()){
            tp.erase(*s.begin());
            s.erase(*s.begin());
        }
        while(!tp.empty()){
            cout<<*tp.begin();
            tp.erase(tp.begin());
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main(){
  //  freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}