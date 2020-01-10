#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
bool prime[1000001];
vector<int> pr;
ll gcd(ll a,ll b){
    if(a%b==0){
        return b;
    }else return gcd(b,a%b);
}
void mkp(){
    int n=1000000;
    prime[1]=1;
    prime[2]=1;
    pr.push_back(2);
    for(int i=3;i<n;i++){
        if(prime[i]==0){
            pr.push_back(i);
        }
        for(int j=0;j<pr.size()&&i*pr[j]<n;i++){
            prime[i*pr[j]]=1;
            if(i%pr[j]==0)
            break;
        }
    }
}
void work(){
    ll a,b;
    cin>>a>>b;
   // cout<<"YES"<<endl;
    a/=b;
    for(int i=0;i<pr.size();i++){
        if(gcd(a,pr[i])==1){
            cout<<pr[i]*b<<endl;
            return ;
        }
    }
    return ;
}
int main(){
    mkp();
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}