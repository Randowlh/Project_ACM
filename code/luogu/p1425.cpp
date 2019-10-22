#include<cstdio>
int main (){
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  int tol1,tol2;
  tol1 =a*60+b;
  tol2 =c*60+d;
  int ans1,ans2;
   ans1=(tol2-tol1)/60;
  ans2=(tol2-tol1)%60;
  printf("%d %d",ans1,ans2);
  return 0;
}
