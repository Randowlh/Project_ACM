#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
bool prime[10000000];
vector<int> pr;
bool check(ll x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)
        return true;
    }
    return false;
}
void mkp(){
    int n=10000000;
    prime[1]=1;
    prime[2]=1;
    pr.push_back(2);
    for(int i=3;i<n;i++){
        if(prime[i]==0){
            pr.push_back(i);
        }
        for(int j=0;j<pr.size()&&i*pr[j]<n;j++){
            prime[i*pr[j]]=1;
            if(i%pr[j]==0)
            break;
        }
    }
    return ;
}
void work(){
    int n;
    while(cin>>n){
        int tmp;
        ll cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            if(tmp>10000000){
                if(!check(tmp)){
                    cnt++;
                }
            }else
            if(prime[tmp]==0){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    mkp();
   //cin>>t;
    while(t--){
        work();
    }
    return 0;
}