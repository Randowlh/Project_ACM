#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    int tmp;
    vector<int> v;
    for(int i= 0; i < n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),greater<int>());
    int mix=0;
    int fl=0;
    for(int i=0;i<n;i++){
        if(fl){
            if(tmp!=v[i]){
                mix=i-1;
                break;
            }else{
                fl=0;
            }
        }else{
            tmp=v[i];
            fl=1;
        }
    }
    cout<<v[mix]<<' ';
    for(int i=0;i<n;i++){
        if(i!=mix){
            cout<<v[i]<<' ';
        }
    }
    cout<<endl;
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