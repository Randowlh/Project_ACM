#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int s;
char arr[2000010];
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
       scanf("%c",&arr[i]);
    }
    if(n==0){
        printf("0\n");
        return 0;
    }else{
        for(int i=1;i<n;i++){
            if(s>0&&arr[i]!='0'){
                arr[i]='0';
                s--;
            }
        }
        printf("%s\n",arr);
    }
    return 0;
}