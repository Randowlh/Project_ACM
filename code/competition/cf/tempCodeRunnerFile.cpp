#include<cstdio>
#include<iostream>
using namespace std;
long long a,b;
long long mod=100000007;
int f[100];
long long PowerMod(long long a,long long n) {
    long long ans=1;
    long long cheng=a;
    while(n>0){
        if(n&1)
        ans=ans*cheng%mod;
        cheng=cheng*cheng%mod;
        n>>=1;
    }
    return ans;
}
int main(){
    cin>>a>>b>>mod;
    cout<<a<<'^'<<b<<' '<<"mod "<<mod<<"="<< PowerMod(a,b)<<endl;
}