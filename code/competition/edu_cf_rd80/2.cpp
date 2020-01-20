#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll a,b;
    cin>>a>>b;
    int cnt=0;
    int fl=0;
    while(b!=0){
        if(b%10!=9){
            fl=1;
        }
        cnt++;
        b/=10;
    }
    if(fl==0)
    cout<<cnt*a<<endl;
    else 
    cout<<(cnt-1)*a<<endl;
    return;
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