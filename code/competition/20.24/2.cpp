#include<stdio.h>
#include<string.h>
#define it register int
#define il inline
using namespace std;
const int N=55;
int T,n,a[N],o1,o2,f[N][N*N];
char s[N][N];
il int Max(it p,it q){
    return p>q?p:q;
}
il void ckMax(int &p,it q){
    p=(p>q?p:q);
}
int main(){
    scanf("%d\n",&T);
    while(T--){
        scanf("%d\n",&n),o1=0;
        for(it i=1;i<=n;++i)
            scanf("%s",s[i]+1),a[i]=strlen(s[i]+1);
        for(it i=1;i<=n;++i)
            for(it j=1;j<=a[i];++j) o1+=(s[i][j]=='1'),o2+=(s[i][j]=='0');
        memset(f,-1,sizeof(f));f[0][0]=0;
        for(it i=1;i<=n;++i)
            for(it j=0;j<=o1;++j)
                for(it k=0;k<=a[i]&&k+j<=o1;++k)
                    if(~f[i-1][j]) ckMax(f[i][j+k],f[i-1][j]+((k&1)&&(a[i]&1))+(!(k&1)));
        printf("%d\n",f[n][o1]);
    }
    return 0;
}