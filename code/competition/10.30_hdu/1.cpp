#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mod=19260817;
int main(){
    int n;
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {   cin>>n;
        long long  tmp=0;
        long long  ans=1;
        for(int i=0;i<n;i++){
            cin>>tmp;
            ans=ans*tmp%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}