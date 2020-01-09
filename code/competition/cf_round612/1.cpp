#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    string s;
    cin>>n>>s;  
    int flag=0;
    int ans=0;
    while(true){
        flag=0;
       // cout<<"yes"<<endl;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='A'&&s[i+1]=='P'){
                s[i+1]='A';
                flag=1;
            }
        }
        if(flag==0)
        break;
        ans++;
    }
    cout<<ans<<endl;
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