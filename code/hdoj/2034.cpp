#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int m;
int a1[110];
int flag[110];
int a2[110];
int main(){
    while(true){
        cin>>n>>m;
        
        if(n==m&&m==0){
            break;
        }
        memset(flag,0,sizeof(flag));   
        for(int i=0;i<n;i++){
            cin>>a1[i];
        }
        for(int  i=0;i<m;i++){
            cin>>a2[i];
        }
        sort(a1,a1+n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(a1[i]==a2[j]){
                     flag[i]=1;
                 }
            }
        }
        int flag1=0;
        for(int i=0;i<n;i++){
            if(flag[i]==0){
                flag1=1;
                cout<<a1[i]<<' ';
            }
        }
        if(flag1==0){
            cout<<"NULL"<<endl;
        }else{
            cout<<endl;
        }
    }
    return 0;
}