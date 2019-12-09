#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        
        if(min(a,b)*2<max(a,b)){
            cout<<"NO"<<endl;
            continue;
        }
        if((a+b)%3!=0){
            cout<<"NO"<<endl;
        }else
        cout<<"YES"<<endl;
        
        
    }
    return 0;
}