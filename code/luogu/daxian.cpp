#include<stdio.h>
#include<stdlib.h>
int a[4][4];
int amin[3]={99999,99999,99999};
int max(int a,int b){
    if(a>b){
        return a;
    }else return b;
}
int min(int a,int b){
    if(a<b){
        return a;
    }else return b;
}
int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            {
                if(a[i][j]<amin[i]){
                    amin[i]=a[i][j];
                }
            }
            int flag=0;
            int ans=0;
            for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]<=0){
            printf("The monster is too weak...");
            return 0;
            }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++)
                if(a[0][i]+a[1][j]+a[2][k]>=60&&a[0][i]+a[1][j]+a[2][k]<100){
                    flag=1;
                    ans=max(ans,100-a[0][i]-a[1][j]-a[2][k]);
                }
        }
    }
    if(flag){
        printf("The brave still has %dHP left to face the BOSS",ans);
    }else{
        if(amin[0]+amin[1]+amin[2]<60){
            printf("why don't give the brave a chance to level up...");
        }else{
            printf("The brave died on the way to leveling...");
        }
    }
    return 0;
            }