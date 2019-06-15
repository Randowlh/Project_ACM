#include<cstdio>
#include<algorithm>
using namespace std;
int n=0;
int ar[1000];
int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d",&ar[i] );
  }
  sort(ar,ar+n);
  int tmp=0;
  int tail=0;
  for(int i=0;i<n;i++){
    if(tmp!=ar[i]){
      ar[tail]=ar[i];
      tmp=ar[i];
      tail++;
    }
    else
    continue;
  }
  printf("%d\n",tail );
  for (int i = 0; i < tail; i++) {
    printf("%d ",ar[i] );
  }
  return 0;
}
