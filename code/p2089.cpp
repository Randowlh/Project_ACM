#include<cstdio>
int book[100];
int ans;
int n;
void dfst(int step,int cost){
  if(step==10&&cost==n){
    ans++;
    return;
  }
  else if(step==10){
    return;
  }
  for(int i=1;i<=3;i++){
    if(cost+i<=n)
    dfst(step+1,cost+i);
    else
    break;
  }
  return;
}
void dfss(int step,int cost){
  if(step==10&&cost==n){
    for(int i=0;i<=9;i++)
    printf("%d ",book[i] );
    printf("\n");
    return;
  }
  else if(step==10){
    return;
  }
  for(int i=1;i<=3;i++){
    if(cost+i<=n){
    book[step]=i;
    dfss(step+1,cost+i);
  }
    else
    break;
  }
  return;
}
int main(){
  scanf("%d",&n);
  dfst(0,0);
  printf("%d\n",ans );
  dfss(0,0);
  return 0;
}
