#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a,b;
    for(int q=0;q<t;q++){
    cin>>a>>b;
    int tmp=abs(a-b);
    int ans=0;
    ans+=tmp/5;
    tmp%=5;
    ans+=tmp/2;
    tmp%=2;
    ans+=tmp;
    cout<<ans<<endl;
    }
    return 0;
}