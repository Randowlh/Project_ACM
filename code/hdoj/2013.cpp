#include<cstdio>
int main(){
    int n=0;
    int now=1;
    while(scanf("%d",&n)!=EOF){
        now=1;
    for(int i=1;i<n;i++){
        now=(now+1)*2;
    }
    printf("%d\n",now);
    }
    return 0;
}