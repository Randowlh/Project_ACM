#include<stdio.h>
#include<string.h>
int map1[10][10];
int map2[10][10];
int m,n;
int biao[8][2]={{1,1},{0,1},{1,0},{1,-1},{-1,-1},{0,-1},{-1,0},{-1,1}};
int main(){
    scanf("%d%d",&m,&n);
    map1[4][4]=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++)
        for(int k=0;k<9;k++){
            if(map1[j][k]>0){
                map2[j][k]+=2*map1[j][k];
                for(int q=0;q<8;q++){
                    if(j+biao[q][0]>=0&&j+biao[q][0]<9&&k+biao[q][1]>=0&&k+biao[q][1]<9)
                    map2[j+biao[q][0]][k+biao[q][1]]+=map1[j][k];
                }
                

            }
        }
        for(int j=0;j<9;j++)
        for(int k=0;k<9;k++){
            map1[j][k]=map2[j][k];
        }
        memset(map2,0,sizeof(map2));

    }
    for(int j=0;j<9;j++){
        for(int k=0;k<9;k++){
         printf("%d",map1[j][k])   ;
        }
        printf("\n");
        }
        return 0;
}