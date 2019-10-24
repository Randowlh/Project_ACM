#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char tmp[10000];
    while(gets(tmp)){
        int flag=1;
        for(int i=0;i<strlen(tmp);i++){
            if(tmp[i]==' '){
                flag=1;
                printf(" ");
            }else{
                if(flag==1){
                   printf("%c",tmp[i]+'A'-'a');
                   flag=0;
                }else{
                    printf("%c",tmp[i]);
                }
            }
        }
        printf("\n");
    }
}