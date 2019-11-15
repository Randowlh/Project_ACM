#include<stdio.h>
#include<math.h>
double dis(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int x[1000];
int y[1000];
int flag[1000];
int lx[1000];
int tail;
int  n;
int y;
int ans[1000];
int mi=1<<30;
double tol=0;
int main(){
    scanf("%d%d",&n,&y);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    while(1){
        if(tail==n){
            if(mi>tol&&&tol>y){
                mi=tol;
                for(int i=0;i<n;i++){
                    ans[i]=lx[i];
                }
            }
            for(int i=n-1;i>=;i--){
                
            }
        }
    }
}