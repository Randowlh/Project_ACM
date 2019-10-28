#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int check(int n){
    int a[10000];
    int tail=0;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            a[tail]=i;
            tail++;
            a[tail]=n/i;
            tail++;
        }
    }
    int ans=0;
    for(int i=0;i<tail;i++){
        ans+=a[i];
    }
    return ans+1;
}
int main(){
    int n;
    int tmp1;
    int tmp2;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>tmp1>>tmp2;
            if(check(tmp1)==tmp2&&check(tmp2)==tmp1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}