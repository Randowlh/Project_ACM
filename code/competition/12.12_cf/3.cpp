#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
//int flag[200010];
long long calc(long long  n){
    return (n*(n+1))/2;
}
int main(){
    int n,m;
    cin>>n>>m;
    string tmp;
    cin>>tmp;
    char ck[100];
    for(int i=0;i<m;i++){
        cin>>ck[i];
    }
    int cnt=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        int fl=0;
        for(int j=0;j<m;j++){
            if(ck[j]==tmp[i]){
                fl=1;
                break;
            }
        }
        if(fl==0){
            if(cnt!=0)
            ans+=calc(cnt);
            cnt=0;
        }else
        {
            cnt++;
        }
    }
    if(cnt!=0)
    ans+=calc(cnt);
    cout<<ans<<endl;
    return 0;
}