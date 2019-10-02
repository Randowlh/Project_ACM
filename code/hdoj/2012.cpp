#include<bits/stdc++.h>
using namespace std;
int f[110];
bool check(int n){
    n=n*n+n+41;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    memset(f,-1,sizeof(f));
    int x,y;
    for(int i=-39;i<=50;i++){
        if(check(i)){
            f[i+50]=1;
        }else{
            f[i+50]=0;
        }
    }
    while(true){
        int flag=0;
        cin>>x>>y;
        if(x==0&&y==0){
            break;
        }
        for(int i=x;i<=y;i++){
            if(f[i+50]==1){
                printf("OK\n");
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("Sorry\n");
        }
    }   
}