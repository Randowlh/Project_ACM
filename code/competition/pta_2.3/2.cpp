#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string t,a[3];
    cin>>t;
    int fl=0;
    for(int i=0;i<t.size();i++){
        if(t[i]!='-'){
            a[fl].push_back(t[i]);
        }else{
            fl++;
        }
    }
    cout<<a[2]<<'-'<<a[0]<<'-'<<a[1]<<endl;
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}