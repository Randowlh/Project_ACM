#include<cstdio>
#include<cstring>
int main(){
  int n;
  int ar[100];
  memset(ar,0,sizeof(ar));
  scanf("%d",&n);
  for(int i=0;i<n+1;i++){
    scanf("%d",&ar[i] );
  }
  int flag=0;
  for(int i=0;i<n-1;i++){
    if(ar[i]==0)
    ;
    else
    if(flag==0){
      if(ar[i]==1){
        printf("x^%d",n-i);
      }
      else
      if(ar[i]==-1){
        printf("-x^%d",n-i);
      }
      else
      printf("%dx^%d",ar[i],n-i);

      flag=1;
}
  else
  if(flag==1){
    if(ar[i]==1){
      printf("+x^%d",n-i);
    }
    else
    if(ar[i]==-1){
      printf("-x^%d",n-i);
    }
    else
    if(ar[i]>0){
      printf("+%dx^%d",ar[i],n-i);
    }
    else
    printf("%dx^%d",ar[i],n-i);
  }
}
if(ar[n-1]!=0){
if(flag==0){
  if(ar[n-1]==1){
    printf("x");
  }
  else
  if(ar[n-1]==-1){
    printf("-x");
  }
  else
  printf("%dx",ar[n-1]);

flag=1;
}
else
if(flag==1){
  if(ar[n-1]==1){
    printf("+x");
  }
  else
  if(ar[n-1]==-1){
    printf("-x");
  }
  else
if(ar[n-1]>0){
  printf("+%dx",ar[n-1]);
}
else
printf("%dx",ar[n-1]);
}
}
if(ar[n]!=0){
if(flag==0){
  printf("%d",ar[n]);

flag=1;
}
else
if(flag==1){
if(ar[n]>0){
  printf("+%d",ar[n]);
}
else
printf("%d",ar[n]);
}
}
return 0;
}
