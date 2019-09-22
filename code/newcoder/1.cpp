#include<cstdio>
#include<algorithm>
using namespace std;
int tail;
int head;
int ans=0;
int map[10000000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&head,&tail);
        for(int j=head-1;j<=tail-1;j++)
        map[j]=1;
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        if(map[i]==0){
            tmp++;
        }else{
            ans=max(ans,tmp);
            tmp=0;
        }
    }
    ans=max(ans,tmp);
    printf("%d",ans);
    return 0;
}