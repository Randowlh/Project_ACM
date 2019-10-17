#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    unsigned int n;
    while(cin>>n){
    unsigned int ans=0;
    unsigned int now=1;
    ans=n%(int)pow(2,16)*pow(2,16);
    ans+=n/pow(2,16);
    cout<<ans<<endl;
    }
    return 0;
    
}