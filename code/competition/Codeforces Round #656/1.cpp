#include<bits/stdc++.h>
using namespace std;
void work(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[1]!=a[2]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<a[2]<<' '<<a[0]<<' '<<1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}