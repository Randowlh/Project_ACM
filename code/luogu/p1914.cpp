#include<cstdio>
#include<cstring>
int main(){
  char ar[1000];
  memset(ar,0,sizeof(ar));
  int n=0;
  scanf("%d",&n );
  scanf("%s\n",ar );
  for(int i=0;i<strlen(ar);i++){
    ar[i]=(ar[i]+n-'a')%26+'a';
  }
  printf("%s",ar );
  return 0;
}
