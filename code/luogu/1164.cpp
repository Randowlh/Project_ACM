#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int f[10001][1000];
int date[1000];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    for(int i=0;i<n;i++)
    for(int j=1;j<=m;j++){
        if(j+date[i]<m){
            continue;
        }else{
            f[m-j-date[i]][i]=max(f[m-j-date[i]][i],f[m-j][i]+1);
        }
    }
    printf("%d\n",f[m][n]);
    return 0;
}