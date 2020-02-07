#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    int tmp;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp%2==0){
            s++;
        }
    }
    cout<<n-s<<' '<<s<<endl;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}