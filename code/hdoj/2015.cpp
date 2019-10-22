#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    int flag=0;
    while(cin>>n>>m){
        if(flag==0){
            flag=1;
        }else cout<<endl;
        int ans=0;
    for(int i=1;i<n;i++){
        ans+=i*2;
        if(i%m==0){
            cout<<ans/m<<" ";
            ans=0;
        }
    }
    ans+=n*2;
    if(n%m==0){
        cout<<ans/m;
    }else
        cout<<ans/(n%m);
    }
    
}