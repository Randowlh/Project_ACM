#include<cstdio>
int main(){
  int a[2][7];
  for(int i=0;i<7;i++)
  for(int j=0;j<2;j++){
    scanf("%d",&a[j][i]);
  }
  int flag=0;
  int max=0;
  for(int i=0;i<7;i++){
    if(a[0][i]+a[1][i]<=8)
    ;
    else
      if(max>=(a[0][i]+a[1][i]))
      ;
      else {
        flag=i+1;
        max=a[0][i]+a[1][i];
      }
  }
  printf("%d\n",flag );
}
