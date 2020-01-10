#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int date1[1000];
int date2[1000];
int flags[1000];
void work(){
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&date1[i]);
            flags[i]=0;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&date2[i]);
        }
        ll ans=0;
        sort(date1,date1+n);
        sort(date2,date2+n);
        for(int i=1;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(date1[i]>=date2[j]&&flags[j]==0){
                    if(date1[i]>date2[j])
                    ans+=200;
                    flags[j]=1;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(flags[i]==0){
                ans-=200;
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}