#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int flag=1;
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=0;j<n;j++){
            if(i%2!=0){
                printf("B");
            }else{
                if(flag==0){
                    flag=1;
                    printf("W");
                }else{
                    printf("B");
                    flag=0;
                }
            }
        }
        printf("\n");
    }
    return 0;
}