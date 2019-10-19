#include<cstdio>
int main(){
    int n;
    int a,b,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        while(true){
            if(b>0&&c>=2){
            ans+=3;
            b--;
            c-=2;
            }else{
                break;
            }
        }
        while(true){
            if(a>0&&b>=2){
            ans+=3;
            a--;
            b-=2;
            }else{
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}