#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int ar[100000];
void qsort(int left ,int right){
  int i,j,t,tmp;
  if(left>right)
  return;
  tmp=ar[left];
  i=left;
  j=right;
  while(i!=j){
    while(ar[j]>=tmp&&i<j)
    j--;
    while(ar[i]<=tmp&&i<j)
    i++;
  if(i<j){
    t=ar[i];
    ar[i]=ar[j];
    ar[j]=t;
  }
  }
  ar[left]=ar[i];
  ar[i]=tmp;
  qsort(left,i-1);
  qsort(i+1,right);
  return;
}
int main(){
  scanf("%d",&n );
  for(int i=0;i<n;i++){
    scanf("%d",&ar[i]);
  }
  qsort(0,n-1);
  for(int i=0;i<n;i++){
    printf("%d ",ar[i] );
  }
}
