#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf =0x7FFFFFFF;
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        long long  n;
        cin>>n;
        if(n<21-6){
            cout<<"NO"<<endl;
            continue;
        }
        n%=14;
        if(n>=1&&n<=6){
            cout<<"YES"<<endl;
        }else 
        cout<<"NO"<<endl;
    }
}