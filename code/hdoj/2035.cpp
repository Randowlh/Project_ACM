#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int fp(int a,int b,int mod){
    int ans=1;
    int k=1;
    int tmp=a;
    if(b==0){
        return 1%mod;
    }else{
        while(b>=k){
            ans=tmp*ans%mod;
            tmp=tmp*tmp%mod;
            b-=k;
            k+=k;
        }
        if(b!=0){
            ans*=fp(a,b,mod)%mod;
        }   
        return ans%mod;
    }
}
int main(){
    int a,b;
    while(true){
        cin>>a>>b;
        if(a==0&&b==0){
            break;
        }
        cout<<fp(a,b,1000)<<endl;
    }
    return 0;
}