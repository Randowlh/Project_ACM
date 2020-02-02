#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[1000];
void work(){
    int n;
    cin>>n;
    int tmp;
    memset(mp,-1,sizeof(mp));
    for(int i=0;i<n;i++){
        cin>>tmp;
        int now=1;
        while(true){
            if(mp[now]==-1){
                mp[now]=tmp;
                break;
            }
            if(mp[now]>tmp){
                now=now*2+1;
                continue;
            }else{
                now*=2;
                continue;
            }
        }
    }
    int cnt=0;
    int fl=1;
    vector<int> ans;
    for(int i=1;i<=1000;i++){
        if(cnt==n)
        break;
        if(mp[i]!=-1){
            ans.push_back(mp[i]);
            cnt++;
        }else{
            fl=0;
            continue;
        }
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<' ';
    }
    cout<<ans[ans.size()-1]<<endl;
    if(fl)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}   
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}