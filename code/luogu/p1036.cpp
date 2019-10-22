#include<cstdio>
#include<cmath>
int ar[200],n,k,primer[5000000],book[200],ans;
void dfs(int val,int step){
  if(step==k){
    int flag=0;
    if(primer[val]==-1){
      ans++;
      return;
    }
    if(primer[val]==1){
      return;
    }
    for(int i=2;i<=(int)(sqrt(val));i++){
      if(val%i==0){
        flag=1;
        break;
      }
    }
    if(flag==0){
      ans++;
      primer[val]=-1;
      return;
    }else
      {
      primer[val]=1;
      return;
    }
  }
  for(int i=0;i<n;i++){
    if(book[i]==0){
    book[i]=1;
    dfs(val+ar[i],step+1);
    book[i]=0;
  }
  }
  return;
}
int main(){
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%d", &ar[i]);
  }
  dfs(0,0);
  int md=1;
  for(int i=1;i<=k;i++){
    md=md*(i);
  }
  printf("%d\n", ans/md);
  return 0;
}
