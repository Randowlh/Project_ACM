#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string tmp;
    cin>>tmp;
    for(int i=0;i<tmp.size();i++){
        tmp[i]-='0';
    }
    int k1=tmp[0]+tmp[1]+tmp[2];
    int k2=tmp[3]+tmp[4]+tmp[5];
    if(k1==k2){
        cout<<"You are lucky!"<<endl;
    }else 
    cout<<"Wish you good luck."<<endl;
    return;
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

//You are lucky!
//Wish you good luck.

