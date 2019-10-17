#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int map[511][511];
int t;
int main(){
    cin>>t;
    
    char tmp;
    int m,n;
    for(int k=0;k<t;k++){
        int ans=0;
        scanf("%d%d",&n,&m);
        int flag=-1;
        int flag1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>tmp;
                if(tmp=='.'){
                    map[i][j]=0;

                }else{
                    map[i][j]=1;
                    flag1=1;
                    if(flag==-1){
                        flag=i;
                    }
                }
            }
        }
        if(flag1==0){
            printf("1\n");
            continue;
        }
        for(int i=flag;i<n;i++){
            int flag2=0;
            for(int j=flag;j<m;j++){
                if(map[i][j]!=1){
                    flag2=1;
                    break;
                }
            }
            if(flag2==0){
                ans--;
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