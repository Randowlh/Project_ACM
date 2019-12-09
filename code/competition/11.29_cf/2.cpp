#include <cstdio>
#include <iostream>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int map[4][10];
string s[10];
int flag[10];
int find(int x){
    for(int i=0;i<9;i++){
        if(map[x][i]==0){
            return i;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
            memset(map,0,sizeof(map));
            memset(flag,0,sizeof(flag));
            int n;
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>s[i];
            } 
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++){
                    if(s[i]==s[j]){
                        flag[j]=1;
                    }
             }
             for(int i=0;i<4;i++){
                 for(int j=0;j<n;j++){
                     map[i][ s[j][i]-'0']=1;
                 }
             }
             int ans=0;
             for(int i=0;i<n;i++){
                 if(flag[i]==1){
                     for(int j=0;j<4;j++){
                         if(find(j)!=-1){
                             s[i][j]='0'+find(j);
                             map[j][find(j)]=1;
                             ans++;
                             break;
                         }
                     }
                 }
             }
             cout<<ans<<endl;
             for(int i=0;i<n;i++){
                 cout<<s[i]<<endl;
             }
            
    }
    return 0;
}