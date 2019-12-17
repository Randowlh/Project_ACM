#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
long k,n;
int main(){
    cin>>n>>k;
    long long tmp=2;
    int tol=2;
    int dpth=1;
    while(tol<n){
        tmp*=2;
        tol+=tmp;
        dpth++;
    }
    
}