#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int a,b;
    cin>>a>>b;
    int j[3];
    cin>>j[0]>>j[1]>>j[2];
    int tol=0;
    for(int i=0;i<3;i++){
        tol+=j[i];
    }
    if(tol==0){
        cout<<"The winner is a: "<<a<<" + "<<3<<endl;
        return;
    }
    if(tol==3){
        cout<<"The winner is b: "<<b<<" + "<<3<<endl;
        return;
    }
    if(a<b){
        cout<<"The winner is b: "<<b<<" + "<<tol<<endl;
        return;
    }
    if(a>b){
        cout<<"The winner is a: "<<a<<" + "<<3-tol<<endl;
        return;
    }
    
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}

//The winner is a: 327 + 1
