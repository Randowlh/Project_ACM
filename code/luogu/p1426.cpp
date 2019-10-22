#include<cstdio>
int main(){
  int s=0,x=0;
  int flag1=-1,flag=0;
  double speed=7;
  double now=0;
  int cnt=0;
  scanf("%d%d",&s,&x );
  while(cnt<1000000){
    if(flag==1){
      if(now<=s+x){
        printf("y");
        return 0;
      }
      else{
        printf("n");
        return 0;
      }
    }
    if(now>=s-x){
      flag=1;
    }
    now+=speed;
    speed=speed*0.98;
    cnt++;
  }
  return 0;
}
