#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    long long tmp;
    long long max;
    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        max=-99999999;
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(tmp>max){
                max=tmp;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}