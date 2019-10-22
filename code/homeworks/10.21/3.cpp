#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=n/5+1;i>0;i--){
        for(int j=n/2+1;j>0;j--){
            if(i*5+j*2<=n-1){
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,n-i*5-j*2,i+j+n-i*5-j*2);
                cnt++;
            }
        }
    }
    printf("count = %d",cnt);
    return 0;
}