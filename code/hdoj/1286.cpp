#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
bool prime[400000];
vector<int> pr;
void mkp(){
    //for(int i=0;i<n;i++)
    int n=390000;
    prime[1]=0;
    prime[2]=0;
    pr.push_back(2);
    for(int i=3;i<n;i++){
        if(prime[i]==0){
            pr.push_back(i);
        }
        for(int j=0;j<pr.size()&&i*pr[j]<=n;j++){
            prime[i*pr[j]]=1;
            if(i%pr[j]==0)
            break;
        }
    }
}
void work(){
    int n;
    cin>>n;
    if(prime[n]==0){
        cout<<n-1<<endl;
        return;
    }
    int flag[40000];
    for(int i=2;i<n;i++){
        flag[i]=0;
    }
    flag[1]=0;
    flag[n]=1;
    int tmp=n;
    for(int i=0;i<pr.size()&&tmp!=1;i++){
        if(tmp%pr[i]==0){
           // cout<<pr[i]<<endl;
            while(tmp%pr[i]==0){
                tmp/=pr[i];
            }
            for(int j=1;j*pr[i]<n;j++){
                flag[j*pr[i]]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return ;
}
int main(){
    mkp();
    //cout<<pr[i]<<endl;
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}