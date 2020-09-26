#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
void work(){
    int a,b,c;
    scanf("%lld%lld%lld", &a, &b, &c);
    int x,y;
    int g=gcd(a,b,x,y);
    if(c%g){
        printf("-1\n");
        return;
    }
   // cout<<"x&y"<<x<<' '<<y<<endl;
    x=x*c/g;
    y=y*c/g;
  //  cout<<"a"<<a<<" x"<<x<<" b"<<b<<" y"<<y<<" c"<<c<<endl;
    int dx=b/g,dy=a/g;
    int l=(1-x)>0?(1-x)/dx+((1-x)%dx>0):(1-x)/dx;
    int r=(y-1)<0?(y-1)/dy-((y-1)%dy!=0):(y-1)/dy;
//cout<<"l="<<l<<" r="<<r<<endl;
    if(l>r){
        printf("%d %d\n",x+l*dx,y-r*dy);
        return;
    }else{
        printf("%d %d %d %d %d\n",r-l+1,x+l*dx,y-r*dy,x+r*dx,y-l*dy);
    }
}
signed main(){
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%lld", &t);
    while(t--){
        work();
    }
}