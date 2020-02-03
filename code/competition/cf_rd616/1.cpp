#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    string t;
    cin>>t;
    ll tol=0;
    string ans;
    for(int i=0;i<t.size();i++){
        if((t[i]-'0')%2!=0)
            ans.push_back(t[i]);
    }
    if(ans.empty()){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<ans.size();i++){
        tol+=ans[i]-'0';
    }
    if(tol%2==0){
        cout<<ans<<endl;
        return;
    }else {
        ans.pop_back();
        if(ans.empty()){
            cout<<-1<<endl;
            return ;
        }
        cout<<ans<<endl;
    }
    return ;
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