#include<cstdio>
#include<algorithm>
using namespace std;
struct note{
  int x;
  int y;
  bool operator <(const note& d)
      {
         if(y < d.y)
         {
            return true;
         }
         if(y == d.y && x < d.x)
         {
            return true;
         }
         return false;
      }
} ar[5000];
int n,s;
int a,b,tol;
int main(){
  scanf("%d%d",&n,&s);
  scanf("%d%d",&a,&b);
  tol=a+b;
  for(int i=0;i<n;i++){
    scanf("%d%d",&ar[i].x,&ar[i].y);
  }
  sort(ar,ar+n);
  int ans=0;
  for(int i=0;i<n;i++){
    if(ar[i].y<=s){
      if(ar[i].x<=tol){
        ans++;
        s=s-ar[i].y;
        continue;
      }
      else
      continue;
    }
    else
    break;
  }
  printf("%d\n", ans);
  return 0;
}
