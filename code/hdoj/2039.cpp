#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double a[10];
int main(){
    int n;
    while(cin>>n){
        for(int k=0;k<n;k++){
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        sort(a,a+3);
        if(a[0]+a[1]<=a[2]){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    }
    return 0;
    
}