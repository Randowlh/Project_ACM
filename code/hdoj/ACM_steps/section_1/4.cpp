#include<cstdio>
int main(){
    int n;
    int ans;
    int tmp;
    while(true){
        scanf("%d",&n);
        if(n==0){
            return 0;
        }else{
            ans=0;
            for(int i=0;i<n;i++){
                scanf("%d",&tmp);
                ans+=tmp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}