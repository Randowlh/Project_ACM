#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int e;
    int c;
    bool operator<(node a){
        return this->c>a.c;
    }
}   date[1010];
int flag[1010];
int t;
int n;
int main(){
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++){
            cin>>date[i].e;
        }
        for(int i=0;i<n;i++){
            cin>>date[i].c;
        }
        sort(date,date+n);
        int ans=0;
        for(int i=0;i<n;i++){
            int flag1=0;
            for(int j=date[i].e-1;j>=0;j--){
                if(flag[j]==0){
                    flag[j]=1;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
                ans+=date[i].c;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}