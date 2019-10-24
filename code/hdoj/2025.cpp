#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char max=0;
    char tmp[100000];
    while(cin>>tmp){
        max=0;
    for(int i=0;i<strlen(tmp);i++){
        if(tmp[i]>max){
            max=tmp[i];
        }
    }
    for(int i=0;i<strlen(tmp);i++){
        if(tmp[i]==max){
            printf("%c(max)",max);
        }else{
            printf("%c",tmp[i]);
        }
    }
    printf("\n");
    }
    return 0;
}