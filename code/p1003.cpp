#include<cstdio>
struct note{
  int x;
  int y;
  int lenx;
  int leny;
} ar[10000];
int main(){
  int n=0;
  scanf("%d",&n);
  int x,y;
  for(int i=0;i<n;i++){
    scanf("%d",&ar[i].x);
    scanf("%d",&ar[i].y);
    scanf("%d",&ar[i].lenx);
    scanf("%d",&ar[i].leny);
  }
  scanf("%d%d",&x,&y);
  int ans=-1;
  for(int i=0;i<n;i++){
    if(x>=ar[i].x&&x<=ar[i].x+ar[i].lenx&&y>=ar[i].y&&y<=ar[i].y+ar[i].leny){
      ans=i+1;
    }
  }
  printf("%d\n",ans );
  return 0;

}
