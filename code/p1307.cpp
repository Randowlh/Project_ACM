#include<cstdio>
#include<cstring>
char ar[1000];
int main(){

  scanf("%s",ar);
  if(ar[0]=='-'){
    printf("-");
    int tmp=0;
    for(int i=strlen(ar)-1;i>0;i--){
      if(tmp==1){
        printf("%c",ar[i]);
      }
      else
      if(ar[i]!='0'){
        tmp=1;
        printf("%c",ar[i] );
      }
    }
    if(tmp==0)
    printf("0");
  }
  else{
    int tmp=0;
    for(int i=strlen(ar)-1;i>=0;i--){
      if(tmp==1){
        printf("%c",ar[i]);
      }
      else
      if(ar[i]!='0'){
        tmp=1;
        printf("%c",ar[i] );
      }
    }
    if(tmp==0)
    printf("0" );
  }

}
