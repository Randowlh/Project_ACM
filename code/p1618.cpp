#include<cstdio>
#include<cstring>
#include<cmath>
int ar[10];
bool check(int a){
  if((a*3)>=1000)
  return false;
  int f[10];
  int tmp;
  memset(f,0,sizeof(f));
  for(int i=0;i<=2;i++){
    tmp=a*ar[i];
    for(int j=1;j<=3;j++ ){
      if(f[tmp%10]==1)
      return false;
      else
      f[tmp%10]=1;
      tmp=tmp/10;
    }
  }
  if(f[0]==1){
    return false;
  }
  return true;
}
int main(){
  scanf("%d%d%d",&ar[0],&ar[1],&ar[2] );
  int flag=0;
  for(int i=0;i<1000;i++){
    if(check(i)){
      flag=1;
      printf("%d %d %d\n",i*ar[0],i*ar[1],i*ar[2] );
    }
  }
  if(flag==0)
  printf("No!!!");
  return 0;
}
