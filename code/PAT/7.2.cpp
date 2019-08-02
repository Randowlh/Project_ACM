#include<cstdio>
struct node{
  char name[100];
  int huxi;
  int maibo;
} date[10000];
int main(){
  int n=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%s",date[i].name);
    scanf("%d",&date[i].huxi);
    scanf("%d",&date[i].maibo);
  }
  for(int i=0;i<n;i++){
    if(date[i].huxi>20||date[i].huxi<15||date[i].maibo<50||date[i].maibo>70){
      printf("%s\n",date[i].name);
    }
  }
  return 0;
}
