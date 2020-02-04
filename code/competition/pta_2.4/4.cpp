#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int x,y;
    cin>>x>>y;
    int ans=5000;
    ans-=(100-x)*y;
    ans-=x*y/2;
    ans-=(100-x)*(100-y)/2;
    cout<<ans<<endl;
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