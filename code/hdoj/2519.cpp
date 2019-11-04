#include<cstdio>
#include<iostream>
using namespace std;
/*
unsigned long long  cheng(int b,int e){
    unsigned long long ans=1;
    for(int i=b+1;i<=e;i++){
        ans*=i;
    }
    return ans;
}*/
unsigned long long calc(int a,int b){
    if(a<b)
    return 0;
    if(a==b)
    return 1;
    if(b==0)
    return 1;
    else  {
        long long ans=1;
        for(int i=0;i<b;i++){
            ans=ans*(a-i)/(1+i);
    }
    return ans;
    }
}
int main(){
    int t;
    int n,m;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>m;
        cout<<calc(n,m)<<endl;
    }   
    return 0;
}