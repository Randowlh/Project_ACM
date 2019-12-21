#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf =0x7FFFFFFF;
int map[1000][1000];
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }else return gcd(b,a%b);
}
int main(){
    int r,c;
    cin>>r>>c;
    int cnt=2;
    int n=r+c;
    if(r<=1&&c<=1){
        cout<<0<<endl;
        return 0;
    }
    if(c==1){
        for(int i=1;i<=r;i++){
            printf("%d\n",i+1);
     }
     return 0;
    }
   // if((r+1))
    for(int i=0;i<c;i++){
        map[0][i]=cnt;
        cnt++;
    }
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            map[i][j]=cnt*map[0][j]/gcd(cnt,map[0][j]);
    //cnt++;
        }
        cnt++;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}