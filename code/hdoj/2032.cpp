#include<cstdio>
#include<iostream>
using namespace std;
int m=0;
int post[31][100];
int main(){
    post[1][1]=1;
    for(int i=2;i<=30;i++){
        for(int j=1;j<=i;j++){
            post[i][j]=post[i-1][j-1]+post[i-1][j];
        }
    }
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                cout<<post[i][j]<<' ';
            }
            cout<<post[i][i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}