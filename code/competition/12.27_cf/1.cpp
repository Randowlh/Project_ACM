#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[1]+a[0]+1>a[2]){
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;
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