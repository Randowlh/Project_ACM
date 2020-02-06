#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int tail=0;
    vector<string> v;
    string tmp;
    while(getline(cin,tmp)){
        //cin>>tmp;
        if(tmp==".")
        break;
        v.push_back(tmp);
    }
    if(v.size()<2){
        cout<<"Momo... No one is for you ..."<<endl;
    }else
    if(v.size()<14){
        cout<<v[0]<<' '<<"is the only one for you..."<<endl;
    }else {
        cout<<v[1]<<" and "<<v[13]<<" are inviting you to dinner..."<<endl;
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