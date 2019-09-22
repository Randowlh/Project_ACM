#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n=0;
    scanf("%d",&n);
    long long tmp=0;
    int m=0;
    long long  ans;
    for(int round=0;round<n;round++){
         ans=0;
        scanf("%d",&m);
        for( tmp=1;tmp<=m;tmp++){
            ans=(ans+tmp*tmp%998244353)%998244353;       
             }
        cout<<ans<<" ";
        ans=1;
        for( tmp=1;tmp<=m;tmp++){
            ans=(ans*((tmp*tmp)%998244353))%998244353;       
             }
        cout<<ans<<endl;
    }
    return 0;
}