#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    vector<int> v;
    int tmp;
    for(int i=0;i<n*2;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    cout<<abs(v[n]-v[n-1])<<endl;
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