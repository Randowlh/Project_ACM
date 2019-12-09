#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int a[4];
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    int flag=0;
    int flagt=0;
    for(int i=3;i>0;i--){
        a[i-1]=a[i]+1;
        if(a[i-1]<0){
        flagt=1;
        break;
        }
    }
    if(flagt==0&&a[0]==0){
        cout<<"YES"<<endl;
    }
}