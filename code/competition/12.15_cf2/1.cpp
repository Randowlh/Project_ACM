#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
int a[4],E,F;
int main(){
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    cin>>E>>F;
    int t=0;
    long long ans=0;
    if(E>F){
        t=min(a[0],a[3]);
        ans=min(a[0],a[3])*E;
        a[0]-=t;
        a[3]-=t;
        ans+=min(a[1],min(a[2],a[3]))*F;
    }else{
        t=min(a[1],min(a[2],a[3]));
        ans=min(a[1],min(a[2],a[3]))*F;
        a[3]-=t;
        ans+=min(a[0],a[3])*E;
    }
    cout<<ans<<endl;
    return 0;
}