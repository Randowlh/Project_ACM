#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[1010][1010];
int h,w;
int tmp;
int ans=1;
int tol;
int main(){
    memset(map,-1,sizeof(map));
    cin>>h>>w;
     for(int i=0;i<h;i++){
        scanf("%d",&tmp);
        if(tmp==0){
            if(w>1){
                if(map[i][0]==1){
                    printf("0\n");
                    return 0;
                }
                if(map[i][1]==0){
                    printf("0\n");
                    return 0;
                }
                map[i][0]=0;
                map[i][1]=1;
                }else{if(map[i][0]==1){
                    printf("0\n");
                    return 0;
                }
                map[i][0]=0; 
              }
            }else{
       for(int j=0;j<tmp;j++){
           if(map[i][j]==0){
                    printf("0\n");
                    return 0;}
           map[i][j]=1;
        }
            if(tmp<h){
                if(map[i][tmp]==1){
                    printf("0\n");
                    return 0;}
            }else{
                map[i][tmp]=0;
            }
        }
   }   
    for(int i=0;i<w;i++){
        scanf("%d",&tmp);
         if(tmp==0){
            if(h>1){
                if(map[0][i]==1){
                    printf("0\n");
                    return 0;
                }
                if(map[1][i]==0){
                    printf("0\n");
                    return 0;
                }
                map[0][i]=0;
                map[1][i]=1;
                }else{if(map[0][i]==1){
                    printf("0\n");
                    return 0;
                }
                map[0][i]=0; 
              }
            }else{
        for(int j=0;j<tmp;j++){
            if(map[j][i]==0){
                    printf("0\n");
                    return 0;
                    }
            map[j][i]=1;
        }
        if(tmp<w){
                if(map[tmp][i]==1){
                    printf("0\n");
                    return 0;}
            }else{
               map[tmp][i]=0;
            }
            }
    }
   
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j]==-1){
                tol++;
            }
        }
    }
    for(int i=0;i<tol;i++){
        ans=ans*2%1000000007;
    }
    printf("%d\n",ans);
    return 0;
}