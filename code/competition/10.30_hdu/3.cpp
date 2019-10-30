#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[5];
int main(){
    int t,n,m;
    int tmp;
    scanf("%d",&t);
    for(int q=0;q<t;q++){
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d",&tmp);
            a[tmp]++;
        }
        int ans=0;
        ans+=a[4];
        ans+=min(a[1],a[3]);
        ans+=a[2]/2;
       // printf("%dlol\n",ans);
        a[2]=a[2]%2;
        int c=min(a[1],a[3]);
        a[1]-=c;
        a[3]-=c;
        //printf("a[3]=%d\n",a[3]);
        if(a[1]>0){
            int tmp1=a[1]+a[2]*2;
            ans+=(tmp1)/4;
            if(tmp1%4!=0)
            ans++;
        }else{
            //printf("%dlol\n",a[2]+a[3]);
            ans+=a[2]+a[3];
        }
        printf("%d\n",ans);
    }
}