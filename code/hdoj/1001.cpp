#include<cstdio>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n%2==0){
            printf("%d\n",n/2*(n+1));
        }else{
            printf("%d\n",(n+1)/2*n);
        }
    }
    return 0;
}