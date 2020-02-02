#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    double h;
    cin>>h;
    h-=100;
    h*=0.9;
    h*=2;
    printf("%.1f\n",h);
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