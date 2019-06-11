#include<cstdio>
#include<cmath>
int main(){
  int a,b;
  int tmp=0;
  int ans=0;
  scanf("%d%d",&a,&b);
  for(int i=1;i<=a;i++){
    tmp=i;
    while(tmp!=0){
      if(tmp%10==b){
        ans++;
      }
      tmp=tmp/10;
    }
  }
  printf("%d\n",ans );
  return 0;
}
