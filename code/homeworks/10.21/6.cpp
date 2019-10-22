#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[1000];
string tmp;
int main(){
    memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       for(int j=0;j<4;j++){
           cin>>tmp;
           if(tmp[2]=='T')
           a[i]=tmp[0]-'A'+1;
       }     
    }
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    return 0;
}