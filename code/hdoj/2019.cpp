#include<bits/stdc++.h>
using namespace std;
int  n,m,tmp;
int main(){
    while(true){
        cin>>n>>m;
        if(n==0&&m==0){
            break;
        }
        int flag=1;
        for(int i=0;i<n-1;i++){
            cin>>tmp;
            if(tmp>=m&&flag==1){
                flag=0;
            printf("%d %d ",m,tmp);}
            else 
            printf("%d ",tmp);
        }
        cin>>tmp;
            if(tmp>m&&flag==1){
                flag=0;
            printf("%d %d",m,tmp);}
            else 
            printf("%d",tmp);
        if(flag){
            printf("%d",m);
        }
        printf("\n");
    }
    return 0;
}