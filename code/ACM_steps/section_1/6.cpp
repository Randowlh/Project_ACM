#include<cstdio>
int main(){
    int tmp;
    int ans;
    int n;
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            ans+=tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}