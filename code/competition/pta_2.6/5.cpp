#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int a,b;
    cin>>a>>b;
    cout<<a<<'/';
    if(b<0){
        cout<<'('<<b<<')'<<"=";
    }else{
        cout<<b<<"=";
    }
    if(b==0){
        cout<<"Error"<<endl;
    }else{
    double ans=(double)a/(double)b;
    printf("%.2f\n",ans);
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