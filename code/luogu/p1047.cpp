#include<cstdio>
#include<cstring>
int main(){
  int ar[100010];
  memset(ar,0,sizeof(ar));
  int n,m;
  scanf("%d%d",&n,&m);
  int a,b;
  for(int i=0;i<m;i++){
    scanf("%d%d",&a,&b);
    for(int j=a;j<=b;j++){
      ar[j]=1;
    }
  }
  int ans=0;
  for(int i=0;i<=n;i++){
    if(ar[i]==0){
      ans++;
    }
  }
  printf("%d\n",ans );
  return 0;
}
