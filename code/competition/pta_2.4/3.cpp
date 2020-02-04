#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string tmp;
    getline(cin,tmp);
    //return;
    if(tmp.size()<3){
         cout<<"Skipped"<<endl;
         return;
    }
    if(tmp.substr(tmp.size()-4,3)!="ong"){
        cout<<"Skipped"<<endl;
        return;
    }
    if(tmp.find(',')<3||tmp.find(',')==4294967295){
        cout<<"Skipped"<<endl;
         return;
    }
    if(tmp.substr(tmp.find(',')-3,3)!="ong"){
        cout<<"Skipped"<<endl;
        return;
    }
    int m=0;
    int cnt=0;
    for(int i=tmp.size()-1;i>=0;i--){
        if(tmp[i]==' '){
            cnt++;
        }
        if(cnt==3){
            m=i;
            break;
        }
    }
    for(int i=0;i<=m;i++){
        cout<<tmp[i];
    }
    cout<<"qiao ben zhong."<<endl;
    return ;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    getchar();
    while(t--){
        work();
    }
    return 0;
}
/*
xun zhang zhai ju lao diao chong, xiao yue dang lian qiao ben zhong.
Skipped
xue zhui rou zhi leng wei rong, an xiao chen jing qiao ben zhong.
Skipped
Skipped
*/