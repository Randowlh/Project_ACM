#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[1010];
void work(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        int tmp;
        for(int j=0;j<k;j++){
            scanf("%d",&tmp);
            mp[tmp]++;
        }
    }
    int mx=-1;
    int mix=0;
    for(int i=1000;i>=0;i--){
        if(mp[i]>mx){
            mx=mp[i];
            mix=i;
        }
    }
    cout<<mix<<' '<<mx<<endl;
}
int main(){
 //   freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}