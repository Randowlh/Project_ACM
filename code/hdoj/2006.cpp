#include<cstdio>
bool check(int x){
    if(x%2!=0){
        return true;
    }else{
        return false;
    }
}
int main(){
    int ans=1;
    int n;
    int tmp;
    while(scanf("%d",&n)!=EOF){
        ans=1;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            if(check(tmp)){
                ans*=tmp;
            }else{
                continue;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}