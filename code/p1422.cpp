#include<cstdio>
const double f=0.4463;
const double s=0.4663;
const double t=0.5663;
int main(){
  int a;
  double ans;
  scanf("%d",&a);
  if(a<=150){
    ans = a*f;
  }else if(a<=400){
    ans = (a-150)*s+150*f;
  }else {
    ans = (a-400)*t+250*s+150*f;
  }
  printf("%.1lf",ans);
  return 0;
}
