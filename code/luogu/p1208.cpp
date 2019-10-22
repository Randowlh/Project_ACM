#include<cstdio>
struct node{
  int m;
  int v;
} a[100000];
void qsort(int first,int end){
  int i,j,t1,t2,tmp;
  if(first>=end)
  return;
  else{
    tmp=a[first].v;
    i=first;
    j=end;
    while(i!=j){
      while(a[j].v>tmp&&i<j)
      j--;
      while(a[i].v<=tmp&&i<j)
      i++;
      if(i<j){
        t1=a[i].m;
        t2=a[i].v;
        a[i].m=a[j].m;
        a[i].v=a[j].v;
        a[j].m=t1;
        a[j].v=t2;
      }
    }
    t1=a[first].m;
    t2=a[first].v;
    a[first].m=a[i].m;
    a[first].v=a[i].v;
    a[i].v=t2;
    a[i].m=t1;
    qsort(first,i-1);
    qsort(i+1,end);
    return;
    }
}

int main(){
  int ans=0;
  int n,m;
  scanf("%d%d",&m,&n);
  for(int i=0;i<n;i++){
    scanf("%d%d",&a[i].v,&a[i].m);
  }
  qsort(0,n-1);
  for(int i=0;i<n;i++){
    if(m-a[i].m<=0){
      ans+=m*a[i].v;
      break;
    }
    else {
      m-=a[i].m;
      ans+=a[i].v*a[i].m;
    }
  }
  printf("%d\n",ans);
  return 0;
}
