#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int tian[1010];
int king[1010];
int map[1010];
int n;
int main(){
    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin>>tian[i];
        }
        for(int i=0;i<n;i++){
            cin>>king[i];
        }
        memset(map,0,sizeof(map));
        sort(tian,tian+n);
        sort(king,king+n,greater<int>()); 
        int ans=0;
        for(int i=0;i<n;i++){
            int flag=0;
            int flagt=0;
            for(int j=0;j<n;j++){
                if(tian[i]==king[j]&&map[j]==0){
                    flag=1;
                    flagt=j;
                }
                if(tian[i]>king[j]&&map[j]==0){
                    flag=2;
                    flagt=j;
                    break;
                }
            }
            if(flag==2){
                ans++;
                map[flagt]=1;
            }
            if(flag==1){
                map[flagt]=1;
            }
            if(flag==0){
                ans--;
            }
        }
        
            cout<<ans*200<<endl;
    }
    return 0;
}