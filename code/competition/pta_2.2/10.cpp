#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    set<int> s;
    s.insert(inf);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp<*s.rbegin()){
            s.erase(s.upper_bound(tmp));
        }
        s.insert(tmp);
    }
    cout<<s.size()<<endl;
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