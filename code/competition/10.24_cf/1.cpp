#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int ft[100010];
int af[100010];
int n;
int t;
int main(){
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ft[i]>>af[i];
        }
        sort(ft,ft+n);
        sort(af,af+n);
        if(ft[n-1]<=af[0]){
            cout<<0<<endl;
        }else{
            cout<<ft[n-1]-af[0]<<endl;
        }
    }
    return 0;
}