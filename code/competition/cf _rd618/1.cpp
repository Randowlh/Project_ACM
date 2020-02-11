#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    ll tol=0;
    int cnt=0;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==0)
        cnt++;
        else 
        tol+=tmp;
    }
    int ans=0;
    if(cnt!=0){
        ans=cnt;
        tol+=cnt;
    }
    if(tol==0){
        ans++;
        tol++;
    }
    cout<<ans<<endl;
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}