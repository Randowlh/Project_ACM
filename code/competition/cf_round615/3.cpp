#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll n;
    vector<ll> ans;
    ans.clear();
    cin>>n;
    ll tmp=n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            while(n%i==0){
                ans.push_back(i);
                n/=i;
            }
        }
    }
    if(n!=1){
        ans.push_back(n);
    }
    /*
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }*/
    
    n=tmp;
    if(ans.size()<3){
        cout<<"NO"<<endl;
        return;
    }
    if(ans.size()>=6){
        cout<<"YES"<<endl;
        cout<<ans[0]<<' '<<ans[1]*ans[2]<<' '<<n/(ans[0]*ans[1]*ans[2])<<endl;
        return;
    }
    sort(ans.begin(),ans.end());
    int cnt=0;
    int tp=-1;
    vector<ll> md;
    for(int i=0;i<ans.size();i++){
        if(tp!=ans[i]){
            tp=ans[i];
            cnt++;
            md.push_back(ans[i]);
        }
    }
    if(cnt>=3){
        cout<<"YES"<<endl;
        cout<<md[0]<<' '<<md[1]<<' '<<n/(md[1]*md[0])<<endl;
        return ;
    }else
    if(cnt==2){
        if(ans.size()<4){
        cout<<"NO"<<endl;
        return;
        }else{
            cout<<"YES"<<endl;
        cout<<md[0]<<' '<<md[1]<<' '<<n/(md[0]*md[1])<<endl;
            return;
            }
    }else
    if(cnt==1){
        cout<<"NO"<<endl;
        return;
    }
    return ;
    
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}