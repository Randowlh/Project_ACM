#include<cstdio>
int ans;
int cost[10]={6,2,5,5,4,5,6,3,7,6};
int calc(int a){
  int b=0;
  if(a==0)
  return 6;
  else
  while(a!=0){
    b+=cost[a%10];
    a=a/10;
  }
  return b;
}
void dfs(int left,int f,int s){
  if(f==-1){
    for(int i=0;i<=1000;i++){
      if(calc(i)<left)
      dfs(left-calc(i)-2,i,-1);
    }
  }
  else
  if(s==-1){
    for (int i = 0; i <=1000; i++) {
      if(calc(i)<left)
      dfs(left-calc(i)-2,f,i);
    }
  }
  else
  if(calc(f+s)==left){
    ans++;
    return;
  }
  else
  return;
}
int main(){
  int n;
  scanf("%d",&n);
  dfs(n,-1,-1);
  printf("%d\n",ans );
  return 0;
}
