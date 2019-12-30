#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int date[300010];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    for(int i=0;i<n-1;i++){
        if(abs(date[i]-date[i+1])>=2){
            cout<<"YES"<<endl;
            cout<<i+1<<' '<<i+2<<endl;
            return ;
        }
        
    }
    cout<<"NO"<<endl;
    return ;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}