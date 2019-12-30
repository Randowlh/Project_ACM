#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n,k1,k2;
    cin>>n>>k1>>k2;
    int tmp;
    int max=0;
    int maxt=0;
    cin>>tmp;
    max=tmp;
    maxt=0;
    for(int i=0;i<k1-1;i++){
        cin>>tmp;
        if(tmp>max){
            max=tmp;
        }
    }
   // cout<<max<<endl;
    for(int i=0;i<k2;i++){
        cin>>tmp;
        if(tmp>max){
            max=tmp;
            maxt=1;
        }
    }
    if(maxt==0){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;

}
int main(){
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}