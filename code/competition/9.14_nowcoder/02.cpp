#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int book[1010];
int a[1010];
int b[1010];
int time;
int ans;
int now;
int n;
void change(int x){
    if(book[x]==1){
        book[x]=0;
    }else{
        book[x]=1;
    }
    return ;
}
int main(){
    char t=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       cin>>t;
        if(t=='0'){
            book[i]=0;
        }
        else{
            book[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    while(time<1000){
        ans=max(now,ans);
        now=0;
        for(int i=0;i<n;i++){
           
            if(book[i]==1){
                now++;
            }
            if(time<b[i])
            continue;
            if((time-b[i])%a[i]==0){
                change(i);
            }
            
            
        }
        printf("\n");
        time++;
    }
    printf("%d",ans);
    return 0;
}