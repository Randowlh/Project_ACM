#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char j;
        double h;
        cin>>j>>h;
        if(j=='M'){
            printf("%.2f\n",h/1.09);
        }else{
            printf("%.2f\n",h*1.09);
        }
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