#include<cstdio>
#include<cstring>
int main(){
  char date[10000];
  double ans=0,cnt=0;
  scanf("%s",date);
  if(date[0]=='-'){
    for(int i=1;i<strlen(date);i++){
      if(date[i]=='2'){
        ans++;
      }
      cnt++;
    }
  }else{
    for(int i=0;i<strlen(date);i++){
      if(date[i]=='2'){
        ans++;
      }
      cnt++;
    }
  }
  if(date[0]=='-'){
    ans=ans*1.5;
  }
  if((date[strlen(date)-1]-'0')%2==0){
    ans=ans*2;
  }
  printf("%.2f%%\n",ans*100/cnt);
  return 0;
}
