#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
const double g=9.8;
void work(){
    double m,p;
    cin>>m>>p;
    m/=100;
    p/=100;
    p=1-p;
    double e=1000;
    double eps=1;
    for(int i=0;i<9;i++){
        eps/=10;
    }
    double ans=0;
     while(fabs(e)>eps)
    {
        ans+=sqrt(2.0*e/(g*m*g))*sqrt(2.0*e/m);
        e*=p;
    }
    printf("%.3f\n",ans);
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