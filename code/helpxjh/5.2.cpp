#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct note{
  int s;
  int i;
} a,b;
void he(){
  int tmp=a.s+b.s;
  int tmpi=a.i+b.i;
  if(tmp==0&&tmpi==0){
    printf("和为0\n");
    return;
  }
  else if(tmp==0){
    printf("和为:%di\n",tmpi);
    return;
  }
  else if(tmpi==0){
    printf("和为:%d\n",tmp );
  }
  else
  if(tmpi>=0)
  printf("和为:%d+%di\n",tmp,tmpi);
  else
  printf("和为:%d%di\n",tmp,tmpi);
  return;
}
void cha(){
  int tmp=a.s-b.s;
  int tmpi=a.i-b.i;
  if(tmp==0&&tmpi==0){
    printf("差为0\n");
    return;
  }
  else if(tmp==0){
    printf("差为:%di\n",tmpi);
    return;
  }
  else if(tmpi==0){
    printf("差为:%d\n",tmp );
  }
  else
  if(tmpi>=0)
  printf("差为:%d+%di\n",tmp,tmpi);
  else
  printf("差为:%d%di\n",tmp,tmpi);
  return;
}
void ji(){
  int tmp=a.s*b.s-a.i*b.i;
  int tmpi=a.i*b.s+a.s*b.i;
  if(tmp==0&&tmpi==0){
    printf("积为0\n");
    return;
  }
  else if(tmp==0){
    printf("积为:%di\n",tmpi);
    return;
  }
  else if(tmpi==0){
    printf("积为:%d\n",tmp );
  }
  else
  if(tmpi>=0)
  printf("积为:%d+%di\n",tmp,tmpi);
  else
  printf("积为:%d%di\n",tmp,tmpi);
  return;
}
void shang(){
  double tmp=((double)(a.s*b.s+a.i*b.i))/(double)(b.s*b.s+b.i*b.i);
  double tmpi=((double)(a.i*b.s-a.s*b.i))/(double)(b.s*b.s+b.i*b.i);
  if(tmp==0&&tmpi==0){
    printf("商为0\n");
    return;
  }
  else if(tmp==0){
    printf("商为:%lfi\n",tmpi);
    return;
  }
  else if(tmpi==0){
    printf("商为:%lf\n",tmp );
  }
  else
  if(tmpi>=0)
  printf("商为:%lf+%lfi\n",tmp,tmpi);
  else
  printf("商为:%lf%lfi\n",tmp,tmpi);
  return;
}
int main(){
  scanf("%d%d%d%d",&a.s,&a.i,&b.s,&b.i);
  he();
  cha();
  ji();
  shang();
  return 0;
}
