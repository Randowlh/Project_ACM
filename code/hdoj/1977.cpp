#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long pow(long long i){
    return i*i*i;
}
int main(){
    int t;
    cin>>t;
    int n;
    for(int q=0;q<t;q++){
        cin>>n;
        cout<<pow(n)<<' '<<pow(n+1)<<endl;
    }
    return 0;
}