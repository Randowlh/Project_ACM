#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
bool check(long long  x){
    if(x%2==0)
    return true;
    else
    return false;
}
int main(){
    int a,b;
    long long ans1=0,ans2=0;
    while(cin>>a>>b){
        if(a>b){
            swap(a,b);
        }
        ans1=0;
        ans2=0;
    for(int i=a;i<=b;i++){
     if(check(i)){
         ans1+=i*i;
     }   else{
         ans2+=i*i*i;
     }
    }
    cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}