#include<cstdio>
int main(){
    int  x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int flag=0;
    for(int i=1;i<=100/x+1;i++){
        for(int j=1;j<=100/y+1;j++){
            if((100-i-j)/z==(100-x*i-y*j)&&(100-i-j)%z==0){
                printf("%d %d %d\n",i,j,100-i-j);
                flag=1;
            }
        }
    }
    if(flag==0){
        printf("no solution!");
    }
    return 0;
}