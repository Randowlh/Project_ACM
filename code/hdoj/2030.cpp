#include<cstdio>
#include<cstring>
int main(){
    char tmp[10000];
    int  n;
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(int q=0;q<n;q++){
            gets(tmp);
            int ans=0;
            for(int i=0;i<strlen(tmp);i++){
                if(tmp[i]&128&&tmp[i]!=EOF){
                    ans++;
                }
            }
            printf("%d\n",ans/2);
        }
    }
    return 0;
}