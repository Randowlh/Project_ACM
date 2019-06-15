#include<cstdio>
#include<cstring>
int que[1000];
int head,tail;
int m,n;
int ans;
int flag;
int ar[1000];
int main(){
  memset(que,-999,sizeof(que));
  scanf("%d%d",&m,&n);
  for(int i=0;i<n;i++){
    scanf("%d",&ar[i] );
  }
  for(int i=0;i<n;i++){
    flag=0;
    for(int j=head;j<tail;j++){
        if(que[j]==ar[i]){
        flag=1;
        break;
      }
    }
      if(flag==1)
      continue;
      else{
        ans++;
        if(tail-head<=m-1){
          que[tail]=ar[i];
          tail++;
        }
        else{
          que[tail]=ar[i];
          tail++;
          head++;
        }
      }
    }
  
  printf("%d\n",ans );
  return 0;
}
