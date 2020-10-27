#include "iostream"
#include<algorithm>
using namespace std;
#define int long long
int powmod(int a,int b,int mod){ 
    int ans=1;
    int tmp=a;
    while(b>0){
        if(b%2==1){
            ans=(ans*tmp)%mod;
        }
        b/=2;
        tmp=tmp*tmp%mod;
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int  a,b,c;
        cin>>a>>b>>c;
        cout<<powmod(a,b,c)<<endl;
    }
}