#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int map[501][501];
int t;
int main(){
    cin>>t;
    char tmp;
    int m,n;
    for(int k=0;k<t;k++){
        scanf("%d%d",&n,&m);
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>tmp;
                if(tmp=='.'){
                    map[i][j]=0;
                }else{
                    map[i][j]=1;
                    if(flag==0){
                        flag=i;
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(map[j][i]==0){
                    map[j][i]=1;
                }else{
                    break;
                }
            }
        }

        int ans=0;
        for(int i=flag;i<n;i++){
            int flag2=0;
            for(int j=0;j<m;j++){
                if(map[i][j]!=1){
                    flag2=1;
                    break;
                }
            }
            if(flag2==0){
                ans++;
            }
        }
        cout<<"Case "<<k+1<<':'<<' '<<ans+1<<endl;
    }
    return 0;
}