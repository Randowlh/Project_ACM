#include<stdio.h>
int map[12][2]={{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
int check(int year){
    if(year%100==0){
        if(year%400==0)
        return 1;
        else
        return 0;
    }else if(year%4==0)
    return 1;
    else 
    return 0;
}
int calc(int year,int mon,int day){
    int ans=0;
    if(check(year)){
        for(int i=0;i<mon-1;i++){
            ans+=map[i][1];
        }
        ans+=day;
        return ans;
    }else{
        for(int i=0;i<mon-1;i++){
            ans+=map[i][0];
        }
        ans+=day;
        return ans;
    }
}
int main(){
    int ans=0;
    int y1,y2,d1,d2,m1,m2;
    scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
    for(int i=y1;i<y2;i++){
        if(check(i)){
            ans+=366;
        }else{
            ans+=365;
        }
    }
    ans+=calc(y2,m2,d2)-calc(y1,m1,d1);
    printf("%d\n",ans);
    return 0;
}