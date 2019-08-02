#include<cstdio>
double calc(int a){
  double ans=0;
  ans=(double)(a-100)*0.9;
  return ans*2;
}
int main(){
  int n;
  scanf("%d",&n);
  int tmph,tmpw;
  for(int i=0;i<n;i++){
    scanf("%d%d",&tmph,&tmpw);
    if(tmpw>calc(tmph)*0.9&&tmpw<calc(tmph)*1.1){
      printf("You are wan mei!\n");
    }else
    if(tmpw<calc(tmph)){
      printf("You are tai shou le!\n");
    }else
    if((double)tmpw>calc(tmph)){
      printf("You are tai pang le!\n");
    }
  }
  return 0;
}
