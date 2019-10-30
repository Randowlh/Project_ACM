#include <cstdio>
int sove(int n){
    int ans=3;
    for(int i=0;i<n;i++){
        ans=(ans-1)*2;
    }
    return ans;
}
int main()
{
    int n;
    int now = 0;
    while(scanf("%d",&n)!=EOF){
        int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            printf("%d\n",sove(tmp));
        }
    }
}