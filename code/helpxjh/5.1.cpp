#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[4];
void he(){
  int tmp=a[0]+a[2];
  int tmpi=a[1]+a[3];
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
  int tmp=a[0]-a[2];
  int tmpi=a[1]-a[3];
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
  int tmp=a[0]*a[2]-a[1]*a[3];
  int tmpi=a[1]*a[2]+a[0]*a[3];
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
  double tmp=((double)(a[0]*a[2]+a[1]*a[3]))/(double)(a[2]*a[2]+a[3]*a[3]);
  double tmpi=((double)(a[1]*a[2]-a[0]*a[3]))/(double)(a[2]*a[2]+a[3]*a[3]);
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
  for(int i=0;i<4;i++){
    scanf("%d",&a[i]);
  }
  he();
  cha();
  ji();
  shang();
  return 0;
}
