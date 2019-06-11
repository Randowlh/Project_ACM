#include<cstdio>
int a[101],b[101];
int main(){
  int n;
  int tmp;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    tmp=0;
    for(int j=i-1;j>0;j--){
      if(a[i]>a[j])
      tmp++;

    }
    b[i]=tmp;
  }
  for(int i=1;i<=n;i++){
    printf("%d ",b[i] );
  }
  return 0;
}
