#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int h,w;
    cin>>h>>w; 
    h-=100;
    h*=1000;
    h*=9;
    h/=10;
    w*=1000;
    w/=2;
    if(w<= h*9/10){
        cout<<"You are tai shou le!"<<endl;
    } else if(w>=h*11/10){
        cout<<"You are tai pang le!"<<endl;
    }else 
    cout<<"You are wan mei!"<<endl;
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
/*
You are wan mei!
You are tai shou le!
You are tai pang le!

*/