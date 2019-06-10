#include<cstdio>
int main(){
  double a;
  scanf("%lf",&a);
  double tol=0;
  double now=2;
  int i=0;
  while(true){
    tol+=now;
    i++;
    now=now*0.98;
    if(tol>=a){
      printf("%d\n",i );
      return 0;
    }
  }
  return 0;
}
