#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string tmp;
    cin>>tmp;
    int ans=0;
    int pr=-1;
    int flag=0;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]=='1'&&flag==0){
            if(pr!=-1){
                ans+=i-pr-1;
                pr=i;
            }else{
                pr=i;
            }
        }
    }
    cout<<ans<<endl;
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