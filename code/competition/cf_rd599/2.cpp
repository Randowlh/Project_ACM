#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    int tmp;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    ll ans=0;
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(v[i]>=i+1){
            ans++;
        }else 
        break;
    }
    cout<<ans<<endl;
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