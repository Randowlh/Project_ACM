#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int q;
    cin>>q;
    for(int k=0;k<q;k++){
    int a,b,n,s;
    cin>>b>>a>>n>>s;
    if(s/n<=b){
        s%=n;
    }else{
        s-=n*b;
    }
    if(s>a){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    }
    return 0;
}