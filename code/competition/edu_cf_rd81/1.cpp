#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll n;
    cin>>n;
    if(n%2==0){
        for(int i=0;i<n/2;i++){
            cout<<1;
        }
        cout<<endl;
    }else {
        cout<<7;
        n-=3;
        for(int i=0;i<n/2;i++){
            cout<<1;
        }
        cout<<endl;
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