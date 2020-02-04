#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    double w,h;
    cin>>w>>h;
    h*=h;
    w/=h;
    printf("%.1f\n",w);
    if(w<=25){
        cout<<"Hai Xing"<<endl;
    }else cout<<"PANG"<<endl;
    return;
}
int main(){
  //  freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}