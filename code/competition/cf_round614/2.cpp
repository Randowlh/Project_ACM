
#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    double a,b;
    int n;
    cin>>n;
    double ans=0;
    for(int i=1;i<=n;i++){
        ans+=1/(double)i;
    }
    printf("%.20f\n",ans);
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