#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int a,b;
    cin>>a>>b;
    int nowa=0;
    int nowb=0;
    int n;
    cin>>n;
    int a1,a2,b1,b2;
    for(int i=0;i<n;i++){
        cin>>a1>>a2>>b1>>b2;
        if(a2==b2)
        continue;
        if(a1+b1==a2){
            nowa++;
        }
        if(a1+b1==b2){
            nowb++;
        }
        if(nowa>a){
            cout<<"A"<<endl;
            cout<<nowb<<endl;
            return;
        }
        if(nowb>b){
            cout<<"B"<<endl;
            cout<<nowa<<endl;
            return;
        }
    }
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