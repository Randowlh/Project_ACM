#include<cstdio>
#include<cstring>
int book[11];
int n;
bool check(int year){
  int ans=0;
  memset(book,0,sizeof(book));
  if(year<1000){
    ans++;
  }
  book[0]=1;
  while(year!=0){
    if(book[year%10]==1){

    }else{
      book[year%10]=1;
      ans++;
    }
    year=year/10;
  }
  if(ans==n){
    return true;
  }else{
    return false;
  }
}
int main(){
  int first;
  int cnt=0;
  scanf("%d%d",&first,&n);
  for(int i=first;;i++){
    if(check(i)){
      if(i>=1000){
      printf("%d %d\n",i,cnt);
      break;
    }
    else{
      if(i>=100){
        printf("0%d %d\n",i,cnt);
        break;
      }
      else{
        if(i>=10){
          printf("00%d %d\n",i,cnt);
          break;
        }
      }

    }
    }
    cnt++;
  }
  return 0;
}
