#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll calc(ll x){
    if(x<0)return 0;
    else return x;
}
int main()
{
    ll t;
    cin>>t;
    for(int q=0;q<t;q++){
        ll a,b,c,r;
        
        cin>>a>>b>>c>>r;
        if(a>b)swap(a,b);
        if(c-r>=b){
            cout<<b-a<<endl;
            continue;
        }
        if(c+r<a){
            cout<<b-a<<endl;
            continue;
        }
        cout<<calc(c-r-a)+calc(b-c-r)<<endl;
    }
}