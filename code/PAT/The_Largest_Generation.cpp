#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int date[101][101];//接邻表
int gen[101];
int book[101];
int bookin[101];
int n,m;
void dfs(int step,int father){
  for(int i=0;i<101;i++){
    if(date[father][i]==0){
      break;
    }else if(bookin[date[father][i]]==0){
      bookin[date[father][i]]=1;
      gen[step+1]++;
      dfs(step+1,date[father][i]);
    }else
    continue;
  }
  return;
}
int main(){
  scanf("%d%d",&n,&m);
  int tmp1,tmp2,tmp;
  for(int i=1;i<=m;i++){
    scanf("%d%d",&tmp1,&tmp2);
    for(int j=0;j<tmp2;j++){
      scanf("%d",&tmp);
      date[tmp1][j]=tmp;
      book[tmp]=1;
    }
  }
  for(int i=1;i<n;i++){
    if(book[i]==0){
      gen[1]++;
      bookin[i]=1;
      dfs(1,i);
    }
  }
  int max=0,ans=0;
  for(int i=0;i<n;i++){
    if(gen[i]>max){
      max=gen[i];
      ans=i;
    }
  }
  printf("%d %d\n",max,ans);
  return 0;
}
