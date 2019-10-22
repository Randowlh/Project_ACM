#include<cstdio>
#include<cstring>
char a[100];
void loop(int b,int c){
  if(c==0){
  int tmp=0;
  for(int i=b-1;i>=0;i--){
    if(tmp==1){
      printf("%c",a[i]);
    }
    else
    if(a[i]!='0'){
      tmp=1;
      printf("%c",a[i]);
    }
  }
  if(tmp==0)
  printf("0" );
  printf("%c",a[b]);
   tmp=0;
  for(int i=strlen(a)-1;i>b;i--){
    if(tmp==1){
      printf("%c",a[i]);
    }
    else
    if(a[i]!='0'){
      tmp=1;
      printf("%c",a[i] );
    }
  }
  if(tmp==0)
  printf("0" );
}

///////////////////////////////////////////////
if(c==1){
  int tmp=0;
  for(int i=b-1;i>=0;i--){
    if(tmp==1){
      printf("%c",a[i]);
    }
    else
    if(a[i]!='0'){
      tmp=1;
      printf("%c",a[i] );
    }
  }
  if(tmp==0)
  printf("0" );
  printf("%c",a[b]);
  char t[100];
 tmp=0;
 int tail=0;
  for(int i=b+1;i<strlen(a);i++){
    if(tmp==1){
      t[tail]=a[i];
      tail++;
    }
    else
    if(a[i]!='0'){
      tmp=1;
      t[tail]=a[i];
      tail++;
    }
  }
  if (tmp==1)
  for (int i=tail-1;i>=0 ;i--) {
    printf("%c",t[i] );
  }
  if(tmp==0)
  printf("0" );
}
return;
}
///////////////////////////////////////
 int main(){

 scanf("%s",a);
 int flag=0;
 for(int i=0;i<strlen(a);i++){
   if(a[i]=='.'){
     loop(i,1);
     flag=1;
   }
   if(a[i]=='/'){
     loop(i,0);
     flag=1;
   }
 }
 if(flag==0&&a[strlen(a)-1]=='%'){
   int tmp=0;
   for(int i=strlen(a)-2;i>=0;i--){
     if(tmp==1){
       printf("%c",a[i]);
     }
     else
     if(a[i]!='0'){
       tmp=1;
       printf("%c",a[i] );
     }
   }
   if(tmp==0)
   printf("0" );
   printf("%%");
 }
 else if(flag==0){
   int tmp=0;
   for(int i=strlen(a)-1;i>=0;i--){
     if(tmp==1){
       printf("%c",a[i]);
     }
     else
     if(a[i]!='0'){
       tmp=1;
       printf("%c",a[i] );
     }
   }
   if(tmp==0)
   printf("0" );
 }
 return 0;
}
