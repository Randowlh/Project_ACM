#include<cstdio>
#include<cstring>
int main(){
  int a[2555];
  char ar[1000];
  for(int i=0;i<4;i++){
    memset(ar,0,sizeof(ar));
    gets(ar);
    for(int j=0;j<strlen(ar);j++){
      a[ar[j]]++;
    }
  }
  int max=0;
  for(int i='A';i<='Z';i++){
    if(a[i]>max){
      max=a[i];
    }
  }
  for(int i=max;i>0;i--){
    for(int j='A';j<='Z';j++){
    if(a[j]>=i)
      printf("* " );
      else
      printf("  ");
  }
    printf("\n");
  }
  printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" );
  return 0;
}
