#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int j,h,w;
    cin>>j>>h>>w;
    if(j==0){
        if(h<129){
            cout<<"duo chi yu! ";
        }else if(h==129){
            cout<<"wan mei! ";
        }else{
            cout<<"ni li hai! ";
        }
        if(w<25){
            cout<<"duo chi rou!"<<endl;
        }else if(w==25){
            cout<<"wan mei!"<<endl;
        }else{
            cout<<"shao chi rou!"<<endl;
        }
        return;
    }else{
        if(h<130){
            cout<<"duo chi yu! ";
        }else if(h==130){
            cout<<"wan mei! ";
        }else{
            cout<<"ni li hai! ";
        }
        if(w<27){
            cout<<"duo chi rou!"<<endl;
        }else if(w==27){
            cout<<"wan mei!"<<endl;
        }else{
            cout<<"shao chi rou!"<<endl;
        }
        return;
    }
}
int main(){
  //  freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}

/*
ni li hai! duo chi rou!
duo chi yu! wan mei!
wan mei! shao chi rou!
duo chi yu! shao chi rou!
*/
