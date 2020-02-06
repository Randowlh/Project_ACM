#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string ans;
    int n;
    int l;
    cin>>l>>n;
    for(int i=0;i<l;i++){
        ans.push_back('z');
    }
    n--;
   // cout<<pow(26,1)<<endl;
    for(int i=l-1;i>=0;i--){
        for(int j=25;j>=0;j--){
            if(n>=(int)pow(26,i)*j){
                n=n-pow(26,i)*j;
                ans[i]-=j;
                break;
            }
        }
    }
    for(int i=l-1;i>=0;i--)
    cout<<ans[i];
    cout<<endl;
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
   // cin>>t;
    while(t--){
        work();
    }
    return 0;
}