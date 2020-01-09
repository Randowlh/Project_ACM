#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll n;
    cin>>n;
    ll a,b,c;
    for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    if(a>b-c){
        cout<<"do not advertise"<<endl;
    }else if(a==b-c){
        cout<<"does not matter"<<endl;
    }else cout<<"advertise"<<endl;
    }
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}