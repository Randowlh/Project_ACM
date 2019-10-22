#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
  int t[100000];
  memset(t,0,sizeof(t));
  int n=0;
  int a[1000];
  scanf("%d",&n );
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int ans=0;
  sort(a,a+n);
  for(int i=1;i<n-1;i++){
    for(int j=i+1;j<n;j++)
        for(int q=i-1;q>=0;q--)
          if(a[q]+a[i]==a[j]&&t[a[j]]==0){
            t[a[j]]=1;
            ans++;
          }
  }
  printf("%d\n",ans );

  return 0;
}
