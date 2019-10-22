#include<cstdio>
char date[1000000];
int tail=0;
int abs(int x){
  if(x<0)
  return -x;
  else
  return x;
}
int main(){
  char tmp;
  while(true){
    scanf("%c",&tmp);
    if(tmp=='E'){
      break;
    }else{
      date[tail]=tmp;
      tail++;
    }
  }
  if(tail==0){
    printf("0:0\n\n0:0");
  }
  else{
  int tmpw=0,tmpy=0;
  for(int i=0;i<=tail;i++){
    if((tmpw>=11||tmpy>=11)&&abs(tmpw-tmpy)>=2){
      printf("%d:%d\n",tmpw,tmpy);
      tmpw=0;
      tmpy=0;
    }
    if(date[i]=='W'){
      tmpw++;
    }
    if(date[i]=='L'){
      tmpy++;
    }
  }
    printf("%d:%d\n",tmpw,tmpy);
  tmpw=0;
  tmpy=0;
  printf("\n");
  for(int i=0;i<tail;i++){
    if((tmpw>=21||tmpy>=21)&&abs(tmpw-tmpy)>=2){
      printf("%d:%d\n",tmpw,tmpy);
      tmpw=0;
      tmpy=0;
    }
    if(date[i]=='W'){
      tmpw++;；l
    }
    if(date[i]=='L'){
      tmpy++;
    }
  }
    printf("%d:%d\n",tmpw,tmpy);
}

  return 0;
}36
