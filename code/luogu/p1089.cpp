#include<cstdio>
int main(){
  int a[12];
  for(int i=0;i<12;i++){
    scanf("%d",&a[i]);
  }
  int mom=0;
  int hand=0;
  for(int i=0;i<12;i++){
    hand+=300;
    if(hand<a[i]){
      printf("-%d",i+1);
      return 0;
    }
    mom+=(hand-a[i])/100*100;
    hand=hand-((hand-a[i])/100*100)-a[i];
  }
  printf("%d\n",mom/5*6+hand);
  return 0;
}
