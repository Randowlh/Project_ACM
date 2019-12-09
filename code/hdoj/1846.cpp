#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    int m,n;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        if(n%(m+1)==0){
            cout<<"second"<<endl;
        }else cout<<"first"<<endl;
    }
    return 0;
}