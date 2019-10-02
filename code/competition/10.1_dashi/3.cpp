#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std ;
int map[10000000];
int st1[100000];
int tail1,tail2;
int st2[100000];
int n,m,s;
int main(){
    cin>>n>>m>>s;
    int tmp1,tmp2;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&tmp1,&tmp2);
        map[tmp1]=tmp2;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&tmp1,&tmp2);
        int now=tmp1;
        st1[tail1]=tmp1;
        tail1++;
        while(now!=s){
            now=map[now];
            st1[tail1]=now;
            tail1++;
        }
         now=tmp2;
        st2[tail1]=tmp2;
        tail2++;
        while(now!=s){
            now=map[now];
            st2[tail2]=now;
            tail1++;
        }
        int ans=0;
        for(int i=0;i<=max(tail1,tail2)-1;i++){
            if(tail1-i<0){
                if(st1[0]!=st2[tail2-i]){
                ans=st1[tail1-i+1];
                break;
            }
            }else if(tail2-i<0){
            if(st1[tail1-i]!=st2[0]) {
                ans=st1[tail1-i+1];
                break;
            } }else
            if(st1[tail1-i]!=st2[tail2-i]){
                ans=st1[tail1-i+1];
                break;
            }
        }
        printf("%d\n",ans);
        tail1=0;
        tail2=0;
    }
    return 0;
}