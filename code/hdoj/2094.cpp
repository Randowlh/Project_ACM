#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
string winner[1010];
int tail1,tail2;
map <string ,int > name;
string loser[1010];
int flag[1010];
int n;
int main(){
    int flag1=0;
    string tmp1;
    string tmp2;
    while(scanf("%d",&n)){
        if(n==0){
            break;
        }
         flag1=0;
        for(int i=0;i<n;i++){
            cin>>tmp1;
            cin>>tmp2;
        }
        sort(winner,winner+n);
        sort(loser,loser+n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            if(winner[i]==loser[j]){
                flag[i]=1;
                break;
            }
        } 
        for(int i=0;i<n;i++){
            if(i==0&&flag[i]==0){
                flag1++;
            }else
            if(flag[i]==0&&winner[i]!=winner[i-1]){
                flag1++;
            }
        }
        if(flag1==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        } 
    }
    return 0;
}   
