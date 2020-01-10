#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
ll gcd(ll a, ll b){
    if(a%b==0){
        return b;
    }else return gcd(b,a%b);
}
void work(){
    ll a,b;
    while(cin>>a>>b)
    cout<<a/gcd(a,b)*b<<endl;
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}