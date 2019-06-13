#include<cstdio>
int ar[1000];
int dfs(int a){
  if(ar[a]!=0)
  return ar[a];
  int ans=1;
  for(int i=1;i<=a/2;i++)
  ans+= dfs(i);
  ar[a]=ans;
  return ans;
}
int main(){
  int n=0;
  scanf("%d",&n );
  printf("%d\n",  dfs(n));
  return 0;
}
