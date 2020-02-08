#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll tmp;
    cin>>tmp;
    ll ans=0;
    while(tmp/10>0){
        ans+=tmp/10*10;
        tmp=tmp-tmp/10*10+tmp/10;
    }
    if(tmp!=0){
        ans+=tmp;
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