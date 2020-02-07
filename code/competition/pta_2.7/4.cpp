#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    set<string>s;
    string tmp;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>tmp;
            s.insert(tmp);
        }
    }
    int m;
    cin>>m;
    int fl=1;
    vector<string> a;
    set<string> ans;
    for(int i=0;i<m;i++){
        cin>>tmp;
        if(s.count(tmp)==0&&ans.count(tmp)==0){
            ans.insert(tmp);
            a.push_back(tmp);
            fl=0;
        }
    }
    if(fl==0)
    for(int i=0;i<a.size()-1;i++){
        cout<<a[i]<<" ";
    }
    if(fl==0)
    cout<<a[a.size()-1]<<endl;
    if(fl)
    cout<<"No one is handsome"<<endl;
    return;
}
int main(){
  // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}