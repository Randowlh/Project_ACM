#include<cstdio>
int main(){
  int a[10];
  int height;
  int ans=0;
  for(int i=0;i<10;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&height);
  height+=30;
  for(int i=0;i<10;i++){
    if(height>=a[i]){
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
