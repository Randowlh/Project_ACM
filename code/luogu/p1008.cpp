#include<cstdio>
#include<cstring>
#include<cmath>
bool check(int a){
  if((a*3)>=1000)
  return false;
  int f[10];
  int tmp;
  memset(f,0,sizeof(f));
  for(int i=1;i<=3;i++){
    tmp=a*i;
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
  for(int i=100;i<1000;i++){
    if(check(i)){
      printf("%d %d %d\n",i,i*2,i*3 );
    }
  }
  return 0;
}
