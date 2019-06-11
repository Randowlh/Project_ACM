#include<cstdio>
int main(){
  int a[1000];
  int tail=0;
  int tmp;
  while (true) {
    scanf("%d",&tmp);
    if(tmp==0)
    break;
    a[tail]=tmp;
    tail++;
  }
  for(int i=tail-1;i>=0;i--){
    printf("%d ",a[i] );
  }
  return 0;
}
