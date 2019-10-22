#include<cstdio>
#include<iomanip>
#include<iostream>
using namespace std;
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int main(){
    long long step,mod;
    int flag=0;
    while(cin>>step>>mod){
        int tmp1=step;
        int tmp2=mod;
        if(gcd(tmp1,tmp2)==1)
             cout<<setw(10)<<step<<setw(10)<<mod<<"    Good Choice"<<endl<<endl;
        else
            cout<<setw(10)<<step<<setw(10)<<mod<<"    Bad Choice"<<endl<<endl;
    }   
    return 0;
}
