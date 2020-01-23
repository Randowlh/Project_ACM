#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int a[3],n;
    cin>>a[0]>>a[1]>>a[2]>>n;
    ll sum=0;
    for(int i=0;i<3;i++){
        sum+=a[i];
    }
    sum+=n;
    if(sum%3!=0){
        cout<<"NO"<<endl;
        return;
    }
    sum/=3;
    for(int i=0;i<3;i++){
        if(sum<a[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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