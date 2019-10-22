#include<cstdio>
const int prize =19;
int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  int tmp=a*10+b;
  printf("%d",tmp/prize);
  return 0;
}
