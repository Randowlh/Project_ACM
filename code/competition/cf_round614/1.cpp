#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n,k,s;
    cin>>n>>s>>k;
    vector<int> d;
    int tmp;
    for(int i=0;i<k;i++){
        scanf("%d",&tmp);
        d.push_back(tmp);
    }
    sort(d.begin(),d.end());
    int e;
    for(int i=0;i<k;i++){
        if(d[i]==s){
            e=i;
            break;
        }
        if(d[i]>s){
            cout<<'0'<<endl;
            return;
        }
    }
    int cnt=0;
    int ans=inf;
    for(int i=e+1;i<d.size();i++){
        if(d[i]!=d[i-1]+1){
            ans=i-e;
            break;
        }
    }
    for(int i=e-1;i>=0;i--){
        if(d[i]!=d[i+1]-1){
            ans=min(ans,e-i);
            break;
        }
    }
    if(d[0]>1){
        ans=min(ans,s-d[0]+1);
    }
    if(d[k-1]<n){
        ans=min(ans,d[k-1]+1-s);
    }
    cout<<ans<<endl;
    return;

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