#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string tmp;
    double t=0;
    double tol=0;
    cin>>tmp;
    int fl=0;
    double c=1;
    if(tmp[0]=='-'){
        c=1.5;
        fl=1;
    }
    if((tmp[tmp.size()-1]-'0')%2==0){
        c*=2;
    }
    for(int i=fl;i<tmp.size();i++){
        if(tmp[i]-'0'==2){
            t++;
        }
        tol++;
    }
    printf("%.2f%%\n",(t/tol)*c*100);
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