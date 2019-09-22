#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int map[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
int rounds;
int now;
int ans;
int cnt[30];
int flag;
int n;
int tmp;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    scanf("%d",&rounds);
    for(int q=0;q<rounds;q++){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
           cin>>tmp;
           for(int i=0;i<30;i++){
               if(map[i]==tmp){
               cnt[i]++;
               break;
               }
           }
           
        }
        for(int i=0;i<11;i++){
               if(cnt[i]>=2){
                   cnt[i+1]+=cnt[i]/2;
               }
           }
           if(cnt[11]!=0){
               printf("YES\n");
           }else{
               printf("NO\n");
           }
    }
    return 0;
}