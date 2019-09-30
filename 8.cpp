#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int s;
    cin>>s;
    if(s+2>7){
        s=s-7;
    }
    cout<<(s+2)%8<<endl;
    }