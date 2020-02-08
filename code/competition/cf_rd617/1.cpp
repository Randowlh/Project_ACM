#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    int tmp;
    int ji=0,ou=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp%2==0){
            ou++;
        }else ji++;
    }
    if(ji==0){
        cout<<"NO"<<endl;
        return;
    }else
    if(ou==0&&n%2==0){
        cout<<"NO"<<endl;
        return;
    }else{
        cout<<"YES"<<endl;
        return;
    }
}
int main(){
  //  freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}