#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    int r,b,k;
    for(int q=0;q<t;q++){
        cin>>r>>b>>k;
        if(r>b)swap(r,b);
        int tmp=-1;        
        int jie=r-b%r;
       // cout<<jie<<endl;
        int ed=b%r;
        int bg=r-1;
        //cout<<jie<<endl;
        //int cnt=0;
        while(bg>0&&jie>=0){
            if(ed>=r){
                tmp=b/r+1;
                break;
            }  
           // cout<<ed<<endl<<bg<<endl;
            ed+=jie;
            bg-=jie;
        }
       // cout<<tmp<<endl;
        if(tmp==-1){
            tmp=b/r;
        }
       // cout<<tmp<<endl;
        if(tmp<k){
            cout<<"OBEY"<<endl;
        }else cout<<"REBEL"<<endl;
    }
    return 0;
}