#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    char c;
    string k;
    cin>>n>>c;
    getchar();
    getline(cin,k);
    if(k.size()<n){
        for(int i=0;i<n-k.size();i++)
        cout<<c;
        cout<<k<<endl;
        return;
    }else {
        cout<<k.substr(k.size()-n,99999999);
    }
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