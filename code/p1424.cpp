#include<cstdio>
int main(){
  int today;
  long tol;
  scanf("%d",&today);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    if(today%7==0||today%7==6){
      today++;
      continue;
    }
    today++;
    tol+=250;
  }
  printf("%ld\n",tol );
  return 0;
}
