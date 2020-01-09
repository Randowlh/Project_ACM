#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&tmp);
            if(tmp==1){sum++;}
        }
    }
    cout<<sum<<endl;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}