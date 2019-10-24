#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char biao[]="aeiou";
int main(){
    int n;
    cin>>n;
    int ans[10];
    char tmp[1000];
    getchar();
    for(int q=1;q<n;q++){
        gets(tmp);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<strlen(tmp);i++){
            for(int j=0;j<5;j++){
                if(tmp[i]==biao[j]){
                    ans[j]++;
                }
            }
        }
        for(int i=0;i<5;i++){
            printf("%c:%d\n",biao[i],ans[i]);
        }
        printf("\n");
    }
    gets(tmp);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<strlen(tmp);i++){
            for(int j=0;j<5;j++){
                if(tmp[i]==biao[j]){
                    ans[j]++;
                }
            }
        }
        for(int i=0;i<5;i++){
            printf("%c:%d\n",biao[i],ans[i]);
        }
        return 0;
}