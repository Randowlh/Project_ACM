#include<cstdio>
#include<cstring>
char a[100];
char b[100];
int flag,flag1;
int main(){
  int ans=0,ans2=0;
  int cnt=0,cnt2=0;
  scanf("%s",b);
  while(scanf("%s",a )!=EOF){
    if(strlen(a)!=strlen(b)){
      cnt2=cnt2+1+strlen(a);
      continue;}
      else {
      flag=0;
      for(int i=0;i<strlen(a);i++){
        if(a[i]<'a')
        a[i]=a[i]-'A'+'a';
        if(b[i]<'a')
        b[i]=b[i]-'A'+'a';
        if(a[i]!=b[i]){
          flag=1;
          break;
        }a
      }
      if(flag==0)
      ans++;
      if(flag1==0&&flag==0){
        ans2=cnt;
        flag1=1;
      }
      cnt2=cnt2+1+strlen(a);
    }


  }
  if(ans!=0)
  printf("%d %d\n",ans,ans2 );
  else
  printf("-1\n" );
  return 0;
}
