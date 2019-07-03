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
  printf("和为:%d+%d\n",tmp,tmpi);
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
  printf("差为:%d+%d\n",tmp,tmpi);
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
  printf("积为:%d+%d\n",tmp,tmpi);
  return;
}
void shang(){
  int tmp=(double)(a[0]*a[2]+a[1]*a[3])/(double)(a[2]*a[2]+a[3]*a[3]);
  int tmpi=(double)(a[1]*a[2]-a[0]*a[3])/(double)(a[2]*a[2]+a[3]*a[3]);
  if(tmp==0&&tmpi==0){
    printf("积为0\n");
    return;
  }
  else if(tmp==0){
    printf("积为:%lfi\n",tmpi);
    return;
  }
  else if(tmpi==0){
    printf("积为:%lf\n",tmp );
  }
  else
  printf("积为:%lf+%lf\n",tmp,tmpi);
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
