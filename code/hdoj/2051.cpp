#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string ans;
int main(){
    int r;
    while(cin>>r){
        ans.clear();
        while(r!=0){
            if(r%2==0){
                ans.push_back('0');
                r/=2;
            }else{
                ans.push_back('1');
                r/=2;
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }cout<<endl;
    }
    return 0;
}