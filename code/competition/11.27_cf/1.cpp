#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long ans=0;
int main(){
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        ans=0;
        cin>>a>>b;
        if(b<=a){
            cout<<b<<endl;
            continue;
        }
        if(b%a==0){
            cout<<(b/a)*(b/a)*a<<endl;
            continue;
        }
            ans+=(b/a+1)*(b/a+1)*(b%a);
            ans+=(b/a)*(b/a)*(a-b%a);
            cout<<ans<<endl;
    }
    return 0;
}