#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int s,m,h;
    scanf("%d:%d:%d",&h,&m,&s);
    s++;
    if(s==60){
        s=0;
        m++;
    }
    if(m==60){
        m=0;
        h++;
    }
    if(h==24){
        h=0;
    }
    if(h==0){
        printf("00:");
    }else if(h<10){
        printf("0%d:",h);
    }else
        printf("%2d:",h);
    if(m==0){
        printf("00:");
    }else  if(m<10){
        printf("0%d:",m);
    } else
        printf("%d:",m);
    if(s==0){
        printf("00\n");
    }else  if(s<10){
        printf("0%d\n",s);
    }   else
        printf("%d\n",s);
        return 0;
   
}