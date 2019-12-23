#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
ll da[2010];
//int disa[2010];
//int disb[2010];
ll db[2010];
int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&da[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&db[i]);
    }
    sort(da,da+n);
    sort(db,db+n);
    for(int i=0;i<n;i++){
        int flag=0;
        int tmp=(da[0]-db[i]+m)%m;
        for(int j=0;j<n;j++){
            if(flag==0){
                if((da[j]-db[(i+j)%n]+m)%m!=tmp){
                    flag=1;
                   // cout<<(da[j]-db[(i+j)%n]+m)%m<<' '<<tmp<<' '<<da[j]<<' '<<db[(i+j)%n]<<' '<<i<<' '<<j<<endl;
                  break;
                }
            }
        }
        if(flag==1){
            continue;
        }else{
            cout<<(m-(tmp+m)%m)%m<<endl;
            return 0;
        }
        
    }
    return 0;
}