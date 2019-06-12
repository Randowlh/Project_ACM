#include<cstdio>
int main(){
  char ar[10];
  int a,b,c;
  char d;
  scanf("%d-%d-%d-%c",&a,&b,&c,&d);
  sprintf(ar,"%d%d%d",a,b,c);
  int ans=0;
  for(int i=0;i<9;i++){
    ans+=(ar[i]-'0')*(i+1);
  }
  ans=ans%11;
  if(ans==10){
  if('X'==d)
  printf("Right\n" );
  else
  printf("%d-%d-%d-X\n",a,b,c );
}
  else
  {
    if(ans==d-'0')
    printf("Right\n" );
    else
    printf("%d-%d-%d-%d\n",a,b,c,ans );
  }
}
