#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int date[100000];
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&date[i]);
  }
  int ans=0;
  int tmp=0;
  for(int i=0;i<n;i++){
   if(tmp+date[i]>m){
     tmp=date[i];
     ans++;
   }else
   tmp+=date[i];
  }
  if(tmp!=0){
    ans++;
  }
  printf("%d\n",ans);
  return 0;
}
