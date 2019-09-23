#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int x;
    int y;
}date[110];
double cx,cy;
double tol=0;
int rnd,n;
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
        tol=0;
        while(scanf("%d",&n)!=EOF){
            if(n==0){
                break;
            }
            tol=0;
            double tmpx=0;
          double tmpy=0;
          for(int i=0;i<n;i++){
              scanf("%d%d",&date[i].x,&date[i].y);
              tmpx+=date[i].x;
              tmpy+=date[i].y;
            }
            cx=tmpx/n;
            cy=tmpy/n;
            double a,b,c,tmp;
            date[n].x=date[0].x;
            date[n].x=date[0].y;
          for(int i=0;i<n;i++){
              a=dis(date[i].x,date[i].y,cx,cy);
              b=dis(date[i].x,date[i].y,date[i+1].x,date[i+1].y);
              c=dis(date[i+1].x,date[i+1].y,cx,cy);
              tmp=(a+b+c)/2;
              tol+=sqrt(tmp*(tmp-a)*(tmp-b)*(tmp-c));
          }
            printf("%.1f\n",tol);     
                
    }
    return 0;
}