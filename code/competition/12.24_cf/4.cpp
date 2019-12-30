#include<bits/stdc++.h>
using namespace std;
string ans;
vector<int> res;
//int res[1000000];
int main(){
    ans="a";
    cout<<ans<<endl;
    int n;
    //cout.flush();
    cin>>n;
    if(n==0){
        return 0;
    }
    if(n==300){
        for(int i=0;i<n;i++){
            cout<<'b';
        }
        cout<<endl;
        return 0;
    }
    res.push_back(n);
    for(int i=0;i<n;i++){
        ans.push_back('a');
    }
    cout<<ans<<endl;
    cin>>n;
    if(n>res[0]){
        for(int i=0;i<res[0];i++){
            cout<<'b';
        }
        cout<<endl;
        return 0;
    }else{
        int leth=res[0]+1;
        int last=n;
        int now=0;
        for(int i=0;i<leth;i++){
            ans[i]='b';
            cout<<ans<<endl;
            cin>>n;
            if(n==0){
                return 0;
            }
            if(n<last){
                last=n;
                continue;
            }else{
                ans[i]='a';
                continue;
            }
        }
    }
    return 0;
}